import UIKit
import SSBPLite

class HomeTableViewController: UITableViewController {

    private static var lastDedup: (id: String, time: TimeInterval)?

    /// Populated in `AppDelegate` when user taps a notification; suppresses duplicate swizzle log on popup Show.
    private static var tapPendingOfferIds = Set<String>()

    static func markOfferTapPending(_ offerId: String) {
        tapPendingOfferIds.insert(offerId)
    }

    static var logHistory: [String] = []
    private static let kLogsKey = "ssbp_log_history"
    private static let kMaxLogs = 200

    // MARK: - Persistence

    static func loadPersistedLogs() {
        guard logHistory.isEmpty else { return }
        if let saved = UserDefaults.standard.stringArray(forKey: kLogsKey) {
            logHistory = saved
        }
    }

    private static func persistLogs() {
        UserDefaults.standard.set(logHistory, forKey: kLogsKey)
    }

    // MARK: - viewDidLoad

    override func viewDidLoad() {
        super.viewDidLoad()
        title = "SDK Data Monitor"
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "LogCell")

        HomeTableViewController.loadPersistedLogs()

        if !HomeTableViewController.logHistory.isEmpty {
            tableView.reloadData()
            scrollToBottom()
        }

        guard let ssbp = SSBPSdkIF.sharedInstance() else { return }

        // Pinable SDK How To Use v8.0 Step 4 — beacon/GPS campaign needs ranging; triggers Location + Bluetooth prompts when not yet granted.
        ssbp.config.useGeofence = false
        ssbp.config.useNotification = true
        ssbp.enablePopup(true, gps: true, ssid: true)
        ssbp.setOfferBeaconSelectMode(.nearest)
        ssbp.setDetectBeacon(true)
        ssbp.scanStart()

        ssbp.register(to: self, scannerHitBeaconOffers: { [weak self] offers, _ in
            guard let offer = offers?.first else { return }
            Self.emitOfferLog(offer: offer, vc: self)
        })

        ssbp.register(to: self, ssbpOnOfferReceive: { [weak self] offer in
            guard let offer = offer else { return }
            Self.emitOfferLog(offer: offer, vc: self)
        })

        NotificationCenter.default.addObserver(
            self,
            selector: #selector(onPinableEOfferDetected(_:)),
            name: Notification.Name(SSBPPinableEOfferWillShowNotification),
            object: nil
        )

        if HomeTableViewController.logHistory.isEmpty {
            let msg = "[SSBP_SDK_EXT] [\(Self.now())] SDK Monitoring Started (Waiting for Campaign...)"
            NSLog("%@", msg)
            addLog(msg)
        }
    }

    deinit {
        NotificationCenter.default.removeObserver(self)
        SSBPSdkIF.sharedInstance()?.unregisterScannerHitBeaconOffers(from: self)
        SSBPSdkIF.sharedInstance()?.unregisterSsbpOnOfferReceive(from: self)
    }

    // MARK: - pinableE handler

    @objc private func onPinableEOfferDetected(_ note: Notification) {
        let raw = note.userInfo ?? [:]
        func str(_ key: String) -> String { raw[key] as? String ?? "" }

        let offerId = str("offerId")
        guard !offerId.isEmpty else { return }

        let trigger      = str("_trigger")
        let isForeground = trigger == "swizzle"

        if isForeground && Self.tapPendingOfferIds.remove(offerId) != nil {
            return
        }

        let t = Date().timeIntervalSince1970
        if let last = Self.lastDedup, last.id == offerId, t - last.time < 3.0 { return }
        Self.lastDedup = (offerId, t)

        let title        = str("offerTitle")
        let mode         = isForeground ? "SIMPLE/SDK-UI" : "SIMPLE/SDK-UI [notification]"
        let displayTitle = title.isEmpty ? "(no title)" : title
        let offerAction  = str("offerAction").isEmpty ? "pinableE_popup" : str("offerAction")

        let msg = "[SSBP_SDK_EXT] [\(Self.now())] 💎 SDK DATA IDENTIFIED: \(displayTitle)" +
                  " (id=\(offerId), mode=\(mode))"
        NSLog("%@", msg)
        NSLog("[SSBP_SDK_EXT]   offerName   = %@", str("offerName"))
        NSLog("[SSBP_SDK_EXT]   offerAction = %@", offerAction)
        NSLog("[SSBP_SDK_EXT]   isForeground= %@", isForeground ? "true" : "false")
        NSLog("[SSBP_SDK_EXT]   offerTexts  = {title: \"%@\", desc: \"%@\", type: \"%@\", url: \"%@\"}",
              title, str("offerDescription"), str("type"), str("url"))
        NSLog("[SSBP_SDK_EXT]   offerLinks  = {imageL: \"%@\", thumbURL: \"%@\"}",
              str("imageL"), str("thumbURL"))

        addLog(msg)
    }

    // MARK: - SSBPOffer callbacks

    private static func displayTitle(from offer: SSBPOffer) -> String {
        offer.getValueText("title")
            ?? offer.getValueText("offerTitle")
            ?? offer.offerName
            ?? "(no title)"
    }

    private static func emitOfferLog(offer: SSBPOffer, vc: HomeTableViewController?) {
        let oid = offer.offerId ?? ""
        let t = Date().timeIntervalSince1970
        if !oid.isEmpty {
            if let last = lastDedup, last.id == oid, t - last.time < 3.0 { return }
            lastDedup = (oid, t)
        }

        let isSimple = offer.offerAction?.lowercased().hasPrefix("pinablee_") == true
        let mode = isSimple ? "SIMPLE/SDK-UI" : "NORMAL/APP-JSON"
        let title = displayTitle(from: offer)

        let msg = "[SSBP_SDK_EXT] [\(Self.now())] 💎 SDK DATA IDENTIFIED: \(title)" +
            " (id=\(oid.isEmpty ? "?" : oid), mode=\(mode))"
        NSLog("%@", msg)
        NSLog("[SSBP_SDK_EXT]   offerName   = %@", offer.offerName ?? "")
        NSLog("[SSBP_SDK_EXT]   offerAction = %@", offer.offerAction ?? "")
        NSLog("[SSBP_SDK_EXT]   isForeground= true")
        NSLog("[SSBP_SDK_EXT]   offerTexts  = {title: \"%@\", desc: \"%@\", url: \"%@\"}",
              offer.getValueText("offerTitle") ?? offer.getValueText("title") ?? "",
              offer.getValueText("desc") ?? "",
              offer.getValueText("url") ?? "")
        NSLog("[SSBP_SDK_EXT]   offerLinks  = {imageL: \"%@\", thumb: \"%@\"}",
              offer.getValueLink("imageL") ?? "",
              offer.getValueLink("thumb") ?? "")

        DispatchQueue.main.async { vc?.addLog(msg) }
    }

    // MARK: - Log display

    private func addLog(_ message: String) {
        HomeTableViewController.logHistory.append(message)
        if HomeTableViewController.logHistory.count > HomeTableViewController.kMaxLogs {
            HomeTableViewController.logHistory.removeFirst()
        }
        HomeTableViewController.persistLogs()
        let ip = IndexPath(row: HomeTableViewController.logHistory.count - 1, section: 0)
        tableView.insertRows(at: [ip], with: .none)
        tableView.scrollToRow(at: ip, at: .bottom, animated: true)
    }

    private func scrollToBottom() {
        let last = IndexPath(row: HomeTableViewController.logHistory.count - 1, section: 0)
        tableView.scrollToRow(at: last, at: .bottom, animated: false)
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        HomeTableViewController.logHistory.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "LogCell", for: indexPath)
        cell.textLabel?.text = HomeTableViewController.logHistory[indexPath.row]
        cell.textLabel?.font = .monospacedSystemFont(ofSize: 11, weight: .regular)
        cell.textLabel?.numberOfLines = 0
        cell.textLabel?.lineBreakMode = .byWordWrapping
        return cell
    }

    // MARK: - Helpers

    static func now() -> String {
        let f = DateFormatter()
        f.dateFormat = "HH:mm:ss"
        return f.string(from: Date())
    }
}

import UIKit
class EnablePopupView: UIView { static func instanceFromNib() -> EnablePopupView { return EnablePopupView() }; var delegate: Any?; func setupView(beacon: Bool, gps: Bool, ssid: Bool) {} }

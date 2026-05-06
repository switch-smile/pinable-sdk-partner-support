# Pinable SDK Data Identification Guide (Ministop iOS)

Tài liệu này hướng dẫn cách tích hợp tối giản và cách trích xuất dữ liệu Campaign từ Pinable SDK dành riêng cho dự án Ministop.

## 🎯 Mục tiêu

Giúp ứng dụng Ministop chủ động **xác định và trích xuất** được thông tin Campaign (Tên, ID) thời gian thực để phục vụ tracking và đồng bộ dữ liệu.

## 🛠 Hướng dẫn Build dự án

Trước khi build trên Xcode, các bạn cần thực hiện bước sau trong Terminal tại thư mục gốc của dự án:

```bash
pod install
```

Sau đó mở file `.xcworkspace` để bắt đầu.

## 📂 Các thành phần cốt lõi

### 1. Giám sát thời gian thực (`HomeTableViewController.swift`)

Sử dụng pattern **"Listen & Query"** để lấy dữ liệu ngay khi phát hiện Beacon.

```swift
@objc func onPinableEvent(_ notification: Notification) {
    guard let beacon = notification.object as? TSsbpBeacon else { return }
  
    SSBPSdkIF.sharedInstance()?.ssbpScanner?.getBeaconOffers(beacon) { (offer, _) in
        guard let data = offer else { return }
      
        let timestamp = DateFormatter.localizedString(from: Date(), dateStyle: .none, timeStyle: .medium)
        // Log định danh dữ liệu
        NSLog("[SSBP_CHECK] [\(timestamp)] 💎 DATA IDENTIFIED: \(data.offerName ?? "Unknown") (ID: \(data.offerId ?? ""))")
    }
}
```

### 2. Xử lý khi chạm Notification/Popup (`AppDelegate.swift`)

Đảm bảo bắt được dữ liệu ngay cả khi người dùng tương tác với quảng cáo của SDK.

```swift
func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
    if let offerData = notification.request.content.userInfo["offer"] as? [String: Any] {
        let name = offerData["offerName"] as? String ?? "Unknown"
        let id = offerData["offerId"] as? String ?? ""
        let timestamp = DateFormatter.localizedString(from: Date(), dateStyle: .none, timeStyle: .medium)
      
        NSLog("[SSBP_CHECK] [\(timestamp)] 🔔 SDK Data: \(name) (\(id))")
    }
    completionHandler([.alert, .sound])
}
```

## 🔍 Cách xác minh (Verification)

Mọi dữ liệu trích xuất thành công từ SDK đều được đánh dấu bằng tiền tố **`[SSBP_CHECK]`**.

1. Chạy ứng dụng trên thiết bị thật hoặc giả lập.
2. Mở **Xcode Console**.
3. Nhập **`SSBP_CHECK`** vào ô Filter.
4. Kiểm tra các dòng Log:
   - Nếu thấy mã ID và Tên Campaign xuất hiện kèm mốc thời gian -> **Tích hợp thành công**.

---

*Lưu ý: Bộ Sample này đã được tối giản hóa (loại bỏ SceneDelegate và UI dư thừa) để đảm bảo tính ổn định cao nhất cho quá trình bàn giao.*

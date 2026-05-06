# Pinable SDK Partner Support

Welcome to the official repository for Pinable SDK integration assets. This repository provides our partners with the necessary SDK binaries, sample applications, and documentation to integrate Pinable features into their mobile applications.

## Repository Structure

The repository is organized by platform and version. Each version is a self-contained package.

```text
.
├── android/
│   └── v8.1.1/
│       ├── sdk/
│       │   └── pinablesdk_v8.1.1_android_20260316.zip    # Extract to get .aar
│       ├── samples/
│       │   └── MinistopSdkSample/    # Functional Android Sample Project
│       └── docs/
│           └── Pinable SDK How To Use (Android)_v8.1.1.docx
├── ios/
│   └── v8.1.1/
│       ├── sdk/
│       │   └── pinablesdk_v8.1.1_ios_20260316.zip        # Extract to get .xcframework
│       ├── samples/
│       │   └── MinistopSdkSample/    # Functional iOS Sample Project
│       └── docs/
│           └── Pinable SDK How To Use (iOS)_v8.1.1.docx
├── docs/
│   └── release_notes/
│       └── v8.1.1.txt
├── README.md
└── CHANGELOG.md
```

## Getting Started

### 📦 Obtaining the Configuration
For security reasons, the configuration file (**`app_info.csv`**) is **NOT** included in this repository. 
- You must obtain your specific `app_info.csv` from the Pinable Management Dashboard.
- **Android**: Place it in `app/src/main/assets/`.
- **iOS**: Place it in the `MinistopSdkSample/Resources/demo/` directory and ensure it is added to the Xcode target.

### 🤖 Android Integration
1.  **SDK**: Download and extract `pinablesdk_v8.1.1_android_20260316.zip` from `android/v8.1.1/sdk/` to get the `.aar` file.
2.  **Sample**: Open `android/v8.1.1/samples/MinistopSdkSample/` in **Android Studio**.
3.  **Documentation**: Detailed instructions are in `android/v8.1.1/docs/Pinable SDK How To Use (Android)_v8.1.1.docx`.

### 🍎 iOS Integration
1.  **SDK**: Download and extract `pinablesdk_v8.1.1_ios_20260316.zip` from `ios/v8.1.1/sdk/` to get the `.xcframework`.
2.  **Sample**: Open the sample project in **Xcode**.
3.  **Documentation**: Detailed instructions are in `ios/v8.1.1/docs/Pinable SDK How To Use (iOS)_v8.1.1.docx`.

## Support & Contact

Refer to [CHANGELOG.md](./CHANGELOG.md) for version history. For further assistance, contact the Switch Smile integration support team.

---
© 2026 Switch Smile. All rights reserved.

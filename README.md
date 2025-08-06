# BadgeVMS example app with a static library included

This repository shows how you can set up CMake for a BadgeVMS application that needs an external library.

## Getting Started

Follow these steps to set up your environment, build the application, and upload it.

### 1. Prerequisites

Before you can build the application, you must set up the ESP-IDF environment and the BadgeVMS SDK.

* **Install ESP-IDF**: You need ESP-IDF version 5.5 installed and activated. See [The ESP IDF docs](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/linux-macos-setup.html) for instructions.

### 2. Build the Application

Once your environment is set up:

1.  Modify `src/sample_app.c` to your liking.
2.  Run the build script:
    ```bash
    ./build.sh
    ```
    This will compile your code and create the application binary in the `build/` directory.
3. After building, you can upload the `.elf` file to a project on BadgeHub. See the "BadgeHub Upload" section below for instructions.

## Upload to BadgeHub
This repository also contains a script that allows you to upload an app to BadgeHub.

To use this, you first need to:
* Create a project on [https://badge.why2025.org/page/create-project](https://badge.why2025.org/page/create-project).
* Create a project API token.
* Set the BADGEHUB_SAMPLE_APP_API_TOKEN in your env and the BADGEHUB_PROJECT_SLUG in the `upload-to-badgehub.sh` script.

Then you can use the script to upload your application:
```bash
./upload-to-badgehub.sh
```

## Updating the BadgeVMS Firmware SDK

For this, we have the `./dev/update-sdk.sh` script. To make this work, first check the firmware submodule's `README.md`. Then you can run `./dev/update-sdk.sh` from the root of the repository.

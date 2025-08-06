#!/bin/bash
# A simplified build script for BadgeVMS applications,
# designed to be run from within an ESP-IDF 5.5 environment.

# Exit immediately if a command exits with a non-zero status.
set -e

# --- Environment Checks ---
if [ -z "$IDF_PATH" ]; then
    echo "Error: ESP-IDF environment not detected (\$IDF_PATH is not set)." >&2
    echo "Please source your ESP-IDF environment first (e.g., '. \$HOME/esp/esp-idf/export.sh')." >&2
    exit 1
fi

# --- Build Process ---
BUILD_DIR="build"
echo "--- Configuring project with CMake (for BadgeVMS) ---"
cmake -S . -B "${BUILD_DIR}"

echo ""
echo "--- Building the application ---"
cmake --build "${BUILD_DIR}"

echo ""
echo "--- Build complete! ---"
echo "Application created at: ${BUILD_DIR}/sample_app.elf"
# CMakeLists.txt for a BadgeVMS Application
# Optimized for use within an ESP-IDF 5.5 environment.

cmake_minimum_required(VERSION 3.16)

# --- Toolchain and System Configuration (MUST be before 'project()') ---

# Tell CMake we are cross-compiling for a generic, bare-metal system.
# This prevents it from adding host-specific flags (e.g. -arch on macOS).
set(CMAKE_SYSTEM_NAME Generic)

# Explicitly set the C compiler. This must be done before the project()
# command so CMake uses it for the initial compiler checks.
set(CMAKE_C_COMPILER "riscv32-esp-elf-gcc")

# Now, define the project. CMake will use the compiler defined above.
project(BadgeVMS-App C)

# --- SDK Setup ---
# The BadgeVMS SDK must be present in a directory named 'sdk_dist'.
set(SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/sdk_dist")
if(NOT EXISTS "${SDK_PATH}")
    message(FATAL_ERROR "SDK directory 'sdk_dist' not found. Please build the SDK ('idf.py sdk') and place it here.")
endif()

# Set the sysroot for the compiler and linker. This is critical.
set(CMAKE_SYSROOT ${SDK_PATH})

# --- Application Target ---
# BadgeVMS applications are position-independent ELF shared objects.
add_library(app_elf SHARED "src/sample_app.c")

# Set the final output name to 'sample_app.elf' by controlling all parts.
set_target_properties(app_elf PROPERTIES
        PREFIX ""                  # Remove the 'lib' prefix
        OUTPUT_NAME "sample_app"   # Set the base name
        SUFFIX ".elf"              # Explicitly set the extension to .elf
)

# --- Required Build Flags (from BadgeVMS README) ---
set(BADGEVMS_COMPILE_FLAGS
        -O2
        -g3
        -fPIC
        -fdata-sections
        -ffunction-sections
        -flto
        -fno-builtin
        -fno-builtin-function
        -fno-jump-tables
        -fno-tree-switch-conversion
        -fstrict-volatile-bitfields
        -fvisibility=hidden
        -mabi=ilp32f
        -march=rv32imafc_zicsr_zifencei
)
target_compile_options(app_elf PRIVATE ${BADGEVMS_COMPILE_FLAGS})

set(BADGEVMS_LINK_FLAGS
        -nostartfiles
        -nostdlib
        -Wl,--gc-sections
        -Wl,--strip-debug
        -Wl,-e,main
        --sysroot=${SDK_PATH} # Also pass sysroot directly to linker
)
target_link_options(app_elf PRIVATE ${BADGEVMS_LINK_FLAGS})

# Add the SDK include directory.
target_include_directories(app_elf SYSTEM PRIVATE "${SDK_PATH}/include")

# --- User-friendly Output ---
message(STATUS "Configured for BadgeVMS target.")
message(STATUS "Run './build.sh' to compile.")
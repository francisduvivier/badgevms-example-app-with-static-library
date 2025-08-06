# CMakeLists.txt for a BadgeVMS Application
# Optimized for use within an ESP-IDF 5.5 environment.

cmake_minimum_required(VERSION 3.16)

# --- Toolchain and System Configuration (MUST be before 'project()') ---
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER "riscv32-esp-elf-gcc")

project(BadgeVMS-App C)

# --- SDK Setup ---
set(SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/sdk_dist")
if(NOT EXISTS "${SDK_PATH}")
    message(FATAL_ERROR "SDK directory 'sdk_dist' not found. Please build the SDK ('idf.py sdk') and place it here.")
endif()
set(CMAKE_SYSROOT ${SDK_PATH})

# --- Application Target ---
# Use add_executable() and the '-shared' flag to create the position-independent
# ELF file required by the BadgeVMS loader.
add_executable(sample_app.elf src/sample_app.c)

# --- Statically Link Your Libraries ---
# Place your static libraries (e.g., libmymath.a) in a 'lib' directory.
link_directories(lib)

# List your static libraries here. For 'libmymath.a', you would list 'mymath'.
set(MY_STATIC_LIBS
        # mymath # <-- Uncomment and replace with your library name(s)
)
target_link_libraries(sample_app.elf PRIVATE ${MY_STATIC_LIBS})


# --- Required Build Flags ---
target_compile_options(sample_app.elf PRIVATE
        -O2 -g3 -fPIC -fdata-sections -ffunction-sections -flto
        -fno-builtin -fno-builtin-function -fno-jump-tables -fno-tree-switch-conversion
        -fstrict-volatile-bitfields -fvisibility=hidden -mabi=ilp32f -march=rv32imafc_zicsr_zifencei
)

# Add '-shared' to the linker flags to produce the correct ELF file type.
set(BADGEVMS_LINK_FLAGS
        -shared -nostartfiles -nostdlib -Wl,--gc-sections -Wl,--strip-debug -Wl,-e,main --sysroot=${SDK_PATH}
)
target_link_options(sample_app.elf PRIVATE ${BADGEVMS_LINK_FLAGS})

# Per the BadgeVMS README, we must exclude symbols from static libraries.
foreach(LIB ${MY_STATIC_LIBS})
    target_link_options(sample_app.elf PRIVATE "-Wl,--exclude-libs,lib${LIB}.a")
endforeach()


# --- Include Directories ---
target_include_directories(sample_app.elf SYSTEM PRIVATE
        "${SDK_PATH}/include"
        # Add include paths for your static libraries here, e.g., "lib/include"
)

# --- User-friendly Output ---
message(STATUS "Configured for BadgeVMS target.")
message(STATUS "Run './build.sh' to compile.")
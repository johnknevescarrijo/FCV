cmake_minimum_required(VERSION 3.20)

project(ComputerVisionProject)

# =========================
# Configuração C++
# =========================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Exporta compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =========================
# OpenCV
# =========================

find_package(OpenCV REQUIRED)

# =========================
# Torch (libtorch)
# =========================

find_package(Torch REQUIRED)

# =========================
# Executável
# =========================

add_executable(app
    src/magnitude_borda.cpp
)

# =========================
# Includes
# =========================

target_include_directories(app PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

# =========================
# Linkagem
# =========================

target_link_libraries(app PRIVATE
    ${OpenCV_LIBS}
    ${TORCH_LIBRARIES}
)

# =========================
# Flags do Torch
# =========================

target_compile_options(app PRIVATE
    ${TORCH_CXX_FLAGS}
)

# =========================
# Linux Threads
# =========================

find_package(Threads REQUIRED)

target_link_libraries(app PRIVATE Threads::Threads)

# =========================
# Mensagens úteis
# =========================

message(STATUS "OpenCV encontrado")
message(STATUS "Torch encontrado")
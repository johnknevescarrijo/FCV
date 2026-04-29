cmake_minimum_required(VERSION 3.20)

project(Fundations)

# =========================
# C++
# =========================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gera compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =========================
# OpenCV
# =========================

find_package(OpenCV REQUIRED)

# =========================
# LibTorch
# =========================

find_package(Torch REQUIRED)

# =========================
# xtensor
# =========================

find_package(xtensor REQUIRED)

# =========================
# Executável
# =========================

add_executable(app
    src/magnitude_borda.cpp
)

# =========================
# Includes extras (opcional)
# =========================

target_include_directories(app PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

# =========================
# Linkagem
# =========================

target_link_libraries(app PRIVATE
    xtensor
    ${OpenCV_LIBS}
    ${TORCH_LIBRARIES}
)

# =========================
# Flags do LibTorch
# =========================

target_compile_options(app PRIVATE
    ${TORCH_CXX_FLAGS}
)

# =========================
# Linux Threads
# =========================

find_package(Threads REQUIRED)

target_link_libraries(app PRIVATE
    Threads::Threads
)

# =========================
# Mensagens
# =========================

message(STATUS "OpenCV encontrado")
message(STATUS "Torch encontrado")
message(STATUS "xtensor encontrado")
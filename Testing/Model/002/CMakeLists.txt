cmake_minimum_required(VERSION 3.0)

project(002)

set(CMAKE_CXX_STANDARD 11)

# Specifica il percorso completo del file di origine
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# Crea l'eseguibile
add_executable(002 main.cpp)

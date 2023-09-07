cmake_minimum_required(VERSION 3.0)

project(Input)

set(CMAKE_CXX_STANDARD 11)

# Aggiungi la cartella libraries/nlohmann alla lista delle cartelle di inclusione
include_directories(${PROJECT_SOURCE_DIR}/libraries/rapidjson)

# Imposta la variabile CMAKE_PREFIX_PATH per includere la directory delle librerie
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${PROJECT_SOURCE_DIR}/libraries")

# Crea l'eseguibile
add_executable(Input WIN32 src/main.cpp)

if(WIN32)
  set_target_properties(Input PROPERTIES WIN32_EXECUTABLE TRUE)
endif()


link_directories(${PROJECT_SOURCE_DIR}/libraries)

# Collega le librerie JSON
target_link_libraries(Input ${PROJECT_SOURCE_DIR}/libraries/rapidjson/rapidjson.h)

# Per problemi di output
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -u _printf_float")

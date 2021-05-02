cmake_minimum_required(VERSION 3.10)

project(Quadrilatero)

# Standard set to 17 to have mandatory RVO
set(CMAKE_CXX_STANDARD 17)


# EXECUTABLE SECTION
add_executable(mainEntry main.cpp)
add_executable(secondaryEntry main_soll.cpp)
add_executable(thirdEntry main_soll_concatenato.cpp)
target_include_directories(mainEntry PRIVATE include)
target_include_directories(secondaryEntry PRIVATE include)
target_include_directories(thirdEntry PRIVATE include)
# Class A is not a library: its source file needs to be included in the target sources
target_sources(mainEntry PRIVATE src/StePer_func.cpp
                    )

target_link_libraries(mainEntry)
target_sources(secondaryEntry PRIVATE src/StePer_func.cpp
                                src/StePer_sollevatore.cpp
                                src/guida.cpp)

target_link_libraries(secondaryEntry)
target_sources(thirdEntry PRIVATE src/StePer_func.cpp
                                src/StePer_sollevatore.cpp
                                src/guida.cpp)

target_link_libraries(thirdEntry)

# TESTS SECTION
# Basically makes CMake read the CMakeLists.txt file contained in tests
add_subdirectory(tests)




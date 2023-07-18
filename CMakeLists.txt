cmake_minimum_required(VERSION 3.12)
project(BeeSimulation VERSION 0.1)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the directories containing header files
include_directories(src)

# Add the source files for your project
set(SOURCES
    src/point.cpp
    src/vector.cpp
    src/flower.cpp
    src/bee.cpp
    src/main.cpp
    src/grid_functions.cpp
)

# Create a library target for your project
add_library(${PROJECT_NAME}_lib ${SOURCES})

# Include Catch2 using FetchContent
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.1  # Specify the desired Catch2 version here
)
FetchContent_MakeAvailable(Catch2)

# Add the test files for Catch2
set(TEST_SOURCES
    tests/test_main.cpp
    tests/test_point.cpp
    tests/test_vector.cpp
    tests/test_flower.cpp
    tests/test_grid_functions.cpp
)

# Create an executable target for your tests
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})

# Link the Catch2 library to the test executable
target_link_libraries(${PROJECT_NAME}_test PRIVATE Catch2::Catch2WithMain ${PROJECT_NAME}_lib)

# Create the main executable target
add_executable(${PROJECT_NAME} src/main.cpp)

# Link the library to the main executable
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

# Add a custom test target to run the tests
enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)

# Set the installation target for the BeeSimulation executable
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
)
# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
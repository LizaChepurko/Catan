# ID 211548268
# Mail: lizachep@gmail.com

cmake_minimum_required(VERSION 3.10)
project(CatanTest)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(CatanTest
    player.cpp
    Hextile.cpp
    node.cpp
    Board.cpp
    CardBank.cpp
    Catan.cpp
    CardBank.cpp
    test_Card.cpp
    test_player.cpp
    test_node.cpp
    test_main.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test libraries
target_link_libraries(CatanTest ${GTEST_LIBRARIES} pthread)

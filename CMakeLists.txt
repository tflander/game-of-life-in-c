cmake_minimum_required(VERSION 3.5)

# Set the project name
project(game-of-life)

SET(PROJECT_TEST ${PROJECT_NAME}-test)

SET(UNITY_DIR ${PROJECT_SOURCE_DIR}/unity)
SET(LIB_UNITY unity)

add_subdirectory(test)
add_subdirectory(unity)

add_dependencies(${PROJECT_TEST} ${LIB_UNITY})
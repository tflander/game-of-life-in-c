FILE(GLOB TEST_SRC *.c)

FILE(GLOB SUT_SRC ../src/*.c)

include_directories( ${PROJECT_SOURCE_DIR}/src )
include_directories(SYSTEM ${UNITY_DIR})

add_executable(${PROJECT_TEST} ${TEST_SRC} ${SUT_SRC})

target_link_libraries(${PROJECT_TEST} ${LIB_UNITY})



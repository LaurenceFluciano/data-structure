cmake_minimum_required(VERSION 3.10)
project(Main)

option(BUILD_MAIN "Build main program" ON)
option(BUILD_TESTS "Build test executable" OFF)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/linked_list
    ${CMAKE_SOURCE_DIR}/src/binary_tree
    ${CMAKE_SOURCE_DIR}/src/interface
    ${CMAKE_SOURCE_DIR}/src/queues
    ${CMAKE_SOURCE_DIR}/src/stack
    ${CMAKE_SOURCE_DIR}/src/vectors
    ${CMAKE_SOURCE_DIR}/__test__
    ${CMAKE_SOURCE_DIR}/unit
)

set(SOURCES
    src/linked_list/doubly_linked_list.c
    src/queues/simple_queue.c
    src/stack/stack.c
    src/binary_tree/binary_tree.c
    src/interface/node_box.c
    src/vectors/unordered_vectors.c
)

if(BUILD_MAIN)
    add_executable(main
        ${SOURCES}
        main.c
    )
endif()


if(BUILD_TESTS)
    set(TEST_SOURCES
        __test__/test.c
        unit/unity.c
    )

    add_executable(test
        ${SOURCES}
        ${TEST_SOURCES}
    )
endif()

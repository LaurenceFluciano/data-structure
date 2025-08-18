cmake_minimum_required(VERSION 3.10)
project(Main)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/linked_list
    ${CMAKE_SOURCE_DIR}/src/binary_tree
    ${CMAKE_SOURCE_DIR}/src/interface
    ${CMAKE_SOURCE_DIR}/src/queues
    ${CMAKE_SOURCE_DIR}/src/stack
)

set(SOURCES
    src/linked_list/doubly_linked_list.c
    src/queues/simple_queue.c
    src/stack/stack.c
    src/binary_tree/binary_tree.c
    src/interface/node_box.c
    main.c
    )

add_executable(main ${SOURCES})
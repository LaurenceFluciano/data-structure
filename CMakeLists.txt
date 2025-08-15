cmake_minimum_required(VERSION 3.10)
project(Main)

include_directories(
    linked_list
    binary_tree
    queues
    stack
)

set(SOURCES
    src/linked_list/doubly.linked.list.c
    src/queues/simple.queue.c
    src/stack/stack.c
    main.c
    )

add_executable(main ${SOURCES})
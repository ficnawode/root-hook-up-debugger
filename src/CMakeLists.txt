
set(NAME exec)

add_executable(${NAME})

target_link_libraries(${NAME}
PRIVATE
    ROOT
)

target_sources(${NAME}
PRIVATE
    tof.C
)

target_include_directories(${NAME}
PRIVATE
    include/
)

add_custom_target(${NAME}.run
    COMMAND ${CMAKE_EXECUTE_PROCESS_COMMAND_ECHO}
    ${NAME}
    DEPENDS ${NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    USES_TERMINAL
)
project(rest_test)

FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG asio-1-32-0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(asio)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include ${asio_SOURCE_DIR}/asio/include)
target_link_libraries(${PROJECT_NAME} PRIVATE glz_test_exceptions)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

add_executable(rest_registry_test rest_registry_test.cpp)

target_include_directories(rest_registry_test PRIVATE include ${asio_SOURCE_DIR}/asio/include)
target_link_libraries(rest_registry_test PRIVATE glz_test_exceptions)

add_subdirectory(rest_server)
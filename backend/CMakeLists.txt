cmake_minimum_required(VERSION 3.14)
project(trie_server)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# Fetch cpp-httplib
FetchContent_Declare(
    cpp_httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v0.14.1
)
FetchContent_MakeAvailable(cpp_httplib)

# Fetch nlohmann/json
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

add_executable(trie_server main.cpp trie.cpp trie.h)
target_link_libraries(trie_server PRIVATE httplib::httplib nlohmann_json::nlohmann_json)

cmake_minimum_required(VERSION 3.14)
project(trie_cli)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# Fetch nlohmann/json
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

add_executable(trie trie.cpp trie.h)
target_link_libraries(trie PRIVATE nlohmann_json::nlohmann_json)

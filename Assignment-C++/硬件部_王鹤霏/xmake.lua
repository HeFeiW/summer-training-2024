add_requires("nlohmann_json")
add_requires("libcurl")
target("cpp_json")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("nlohmann_json", "libcurl")
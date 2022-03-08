from conans import ConanFile, CMake

class PyRho(ConanFile):
    name = "pyrho"
    version = "2.0.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = (
        "gtest/1.11.0",
        "qt/6.2.3",
    )
    generators = "cmake", "cmake_find_package"
    exports_sources = "CMakeLists.txt", "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()
from conans import ConanFile, tools
from conan.tools.cmake import CMake

from os import path


class ShmurpConan(ConanFile):
    name = "shmurp"
    license = "MIT"
    author = "adnn"
    url = "https://github.com/Adnn/shmurp"
    description = "Shoot them urp!"
    topics = ("opengl", "2D", "game")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {
        "shared": False,
    }

    requires = (
        ("glad/0.1.34"),

        ("aunteater/6afa38a266@adnn/develop"),
        ("graphics/d3958e3ec1@adnn/develop"),
        ("math/4086708c05@adnn/develop"),
        ("websocket/84bbb84476@adnn/develop"),
    )

    build_requires = ("cmake/3.20.4")

    generators = "cmake_paths", "cmake_find_package", "CMakeToolchain"
    build_policy = "missing"

    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto",
        "submodule": "recursive",
    }


    def configure(self):
        tools.check_min_cppstd(self, "17")


    def _generate_cmake_configfile(self):
        """ Generates a conanuser_config.cmake file which includes the file generated by """
        """ cmake_paths generator, and forward the remaining options to CMake. """
        with open("conanuser_config.cmake", "w") as config:
            config.write("message(STATUS \"Including user generated conan config.\")\n")
            # avoid path.join, on Windows it outputs '\', which is a string escape sequence.
            config.write("include(\"{}\")\n".format("${CMAKE_CURRENT_LIST_DIR}/conan_paths.cmake"))


    def generate(self):
        self._generate_cmake_configfile()


    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake


    def build(self):
        cmake = self._configure_cmake()
        cmake.build()


    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

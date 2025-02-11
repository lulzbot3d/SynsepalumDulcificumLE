# Dulcificum JS

[![Badge Packages]][Packages]
[![Badge Test]][Test]
[![Badge Size]][Size]

A worker that runs Dulcificum in a browser using the Emscripten to compile for wasm

## System Requirements

### Windows

- Python 3.11 or higher
- Ninja 1.10 or higher
- VS2022 or higher
- CMake 3.23 or higher
- nmake

### macOS

- Python 3.11 or higher
- Ninja 1.10 or higher
- apply clang 11 or higher
- CMake 3.23 or higher
- make

### Linux

- Python 3.11 or higher
- Ninja 1.10 or higher
- gcc 13 or higher
- CMake 3.23 or higher
- make

## Installation

We are using conan to manage our C++ dependencies and build configuration. If you have never used Conan read their documentation which is quite extensive and well maintained.

1. Configure Conan

2. Before you start, if you use conan for other (big) projects as well, it's a good idea to either switch conan-home and/or backup your existing conan configuration(s).

That said, installing our config goes as follows:

    ```bash
    pip install conan==2.7.0
    conan config install https://github.com/lulzbot3d/conan-config-le.git
    conan profile new default --detect --force
    ```

3. conan install with wasm

    ```bash
    conan install . -s build_type=Release --build=missing --update -c tools.build:skip_test=True -pr:h cura_wasm.jinja
    conan install . -s build_type=Debug --build=missing --update -c tools.build:skip_test=True -pr:h cura_wasm.jinja
    ```

<!---------------------------------------->

[Packages]: https://github.com/lulzbot3d/SynsepalumDulcificumLE/actions/workflows/package.yml
[Test]: https://github.com/lulzbot3d/SynsepalumDulcificumLE/actions/workflows/unit-test.yml
[Size]: https://github.com/lulzbot3d/SynsepalumDulcificumLE

[Badge Packages]: https://img.shields.io/github/actions/workflow/status/lulzbot3d/SynsepalumDulcificumLE/package.yml?branch=main&style=for-the-badge&logoColor=white&logo=npm&label=Packages
[Badge Test]: https://img.shields.io/github/actions/workflow/status/lulzbot3d/SynsepalumDulcificumLE/unit-test.yml?branch=main&style=for-the-badge&logoColor=white&logo=Codacy&label=Unit%20Test
[Badge Size]: https://img.shields.io/github/repo-size/lulzbot3d/SynsepalumDulcificumLE?style=for-the-badge&logoColor=white&logo=GoogleAnalytics
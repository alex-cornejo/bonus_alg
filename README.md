# bonus_alg
Approximation algorithms for the Graph Burning Problem

The first time it is need to install the conan package manager with the respective libraries included in the conanfile.txt

# Install conan and libraries

```
pip3 install conan
```

## Reload local path
```
source ~/.profile
```

## Compiler configuration for GCC compiler >= 5.1 :
```
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default
```

## Install conan libraries
```
mkdir build && cd build
conan install ..
```

NOTE: Previous steps only are needed to be executed once. Once conan libraries are installed, to compile and run the program, get back to the root project folder with ```cd ..```

# Install cmake
```
sudo apt install cmake
```

# Compile program

```
cmake -DCMAKE_BUILD_TYPE=Release .
cmake --build .
```
The binary file will be generated onto the "bin/" folder. Get onto it with ```cd bin/```

# Run

```
./bin/bonus_alg [file] [algorithm] [p]
```

## Where,

|  Parameter |                                          Description                                          |
|----------|---------------------------------------------------------------------------------------------|
| `[file]` | (string) Instance file path with a valid format, defined here                                    |
| `[algorithm]`    | (string) Algorithm to execute (bon, bff and bonus)  |
| `[p]`    | (integer) p value (only if bonus algorithm is selected)   |

# Example 1
```
./bin/bonus_alg dataset/line49nodes.mtx bonus 1
```
# Approximation algorithms for the Graph Burning Problem

This repository contains the following approximation algorithms for the Graph Burning Problem.

|  Algorithm |                                          Complexity                               | <img src="https://render.githubusercontent.com/render/math?math=\rho">| keywork
|------------|-----------------------------------------------------------------------------------| -|-
| Bon        | <img src="https://render.githubusercontent.com/render/math?math=O(n^2 \log n)">   | <img src="https://render.githubusercontent.com/render/math?math=3-2/b(G)"> | bon
| BFF        | <img src="https://render.githubusercontent.com/render/math?math=O(n^3)">          | <img src="https://render.githubusercontent.com/render/math?math=3-2/b(G)">| bff
| BFF+       | <img src="https://render.githubusercontent.com/render/math?math=O(n^3)">          | <img src="https://render.githubusercontent.com/render/math?math=3-2/b(G)">| bff+
| Bonus      | <img src="https://render.githubusercontent.com/render/math?math=O(n^{3%2B p})">   | <img src="https://render.githubusercontent.com/render/math?math=3-2(p %2B 1)/b(G)">| bonus


## Install c++ boost libraries
```
sudo apt install libboost-all-dev
```

## Install cmake
```
sudo apt install cmake
```

## Compile program
```
cmake -DCMAKE_BUILD_TYPE=Release .
cmake --build .
```
The binary file will be generated onto the root folder with the name ```bonus_alg```.

## Run

```
./bonus_alg [file] [algorithm] [p]
```

### Where,

|  Parameter |                                          Description                                          |
|----------|---------------------------------------------------------------------------------------------|
| `[file]` | (string) Instance file path with a valid format.                                    |
| `[algorithm]`    | (string) Algorithm to execute (**bon**, **bff**, **bff+** and **bonus**)  |
| `[p]`    | (integer) ***p*** value (only if bonus algorithm is selected)   |

## Example 1 - Bon algorithm
```
./bonus_alg dataset/econ-mahindas.mtx bon
```

## Output 1
```
Compute all shortest paths running time: 0.140625 seconds
Algorithm running time: 0 seconds
[367, 1256, 893, 527, 1176, 1141, 555]
7
```

## Example 2 - BFF algorithm
```
./bonus_alg dataset/econ-mahindas.mtx bff
```

## Output 2
```
Compute all shortest paths running time: 0.125 seconds
Algorithm running time: 0 seconds
[367, 505, 555, 50, 503, 549]
6
```

## Example 3 - BFF+ algorithm
```
./bonus_alg dataset/econ-mahindas.mtx bff+
```

## Output 3
```
Compute all shortest paths running time: 0.140625 seconds
Algorithm running time: 0.046875 seconds
[989, 554, 555, 50, 51]
5
```

## Example 4 - Bonus algorithm with ***p=0***
```
./bonus_alg dataset/econ-mahindas.mtx bonus 0
```

## Output 4
```
Compute all shortest paths running time: 0.140625 seconds
Algorithm running time: 0 seconds
[357, 1049, 582, 415, 1191, 942]
6
```

## Example 5 - Bonus algorithm with ***p=1***
```
./bonus_alg dataset/econ-mahindas.mtx bonus 1
```

## Output 5
```
Compute all shortest paths running time: 0.140625 seconds
Algorithm running time: 7.0625 seconds
[819, 606, 607, 552, 608]
5
```

# Contact
* jesgadiaz@inaoep.mx
* alexcornejo@inaoep.mx


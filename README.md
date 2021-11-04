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

## Example 1
```
./bin/bonus_alg dataset/line49nodes.mtx bonus 1
```


# Contact
* jesgadiaz@inaoep.mx
* alexcornejo@inaoep.mx


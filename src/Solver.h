//
// Created by ale_j on 8/17/2021.
//

#ifndef BONUS_SOLVER_H
#define BONUS_SOLVER_H


#include <vector>

class Solver {

private:

    const int n;
    int **D;

public:
    Solver(int n, int **D);

    std::vector<int> burning_sequence(int k, std::vector<int> &V);

    int solve(int p);
};


#endif //BONUS_SOLVER_H

//
// Created by ale_j on 8/17/2021.
//

#ifndef BONUS_BONUSSOLVER_H
#define BONUS_BONUSSOLVER_H


#include <vector>
#include "BonSolver.h"

class BonusSolver : BonSolver {

private:
    int p;

public:
    BonusSolver(int n, int **D, int p);

    std::vector<int> run() override;
};


#endif //BONUS_BONUSSOLVER_H

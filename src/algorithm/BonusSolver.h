//
// Created by ale_j on 8/17/2021.
//

#ifndef BONUS_BONUSSOLVER_H
#define BONUS_BONUSSOLVER_H


#include <vector>
#include "BonSolver.h"
#include "AlgUtils.h"

class BonusSolver : BonSolver {

private:
    int p;
    std::vector<std::vector<int>> adj;
    bool isGraphConnected;

    bool isConnectedBFS();

public:
    BonusSolver(int n, int **D, int p, std::vector<std::pair<int, int>> &edges);

    std::vector<int> run() override;
};


#endif //BONUS_BONUSSOLVER_H

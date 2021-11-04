//
// Created by ale_j on 8/17/2021.
//
#include <iostream>
#include <set>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <queue>
#include "BonusSolver.h"

#include "../combinations/combinations.hpp"
#include "../combinations/combinations_init.hpp"

using namespace boost;
using namespace boost::combinations;
using namespace std;

BonusSolver::BonusSolver(const int n, int **D, int p, vector<pair<int, int>> &edges) : BonSolver(n, D) {
    BonusSolver::p = p;
    adj = AlgUtils::createAdjList(edges, n);
    isGraphConnected = isConnectedBFS();
}

template<typename Iter>
vector<int> get_permutation(Iter first, Iter middle, Iter last, int k) {
    vector<int> perm(k);
    int i = 0;
    for (Iter itr = first; itr != middle; ++itr) {
        perm[i++] = *itr;
    }
    return perm;
}

vector<int> BonusSolver::run() {
    int high = isGraphConnected ? ceil(sqrt(n)) : n;
    vector<int> f_best;
    for (int k = 1; k <= high; k++) {
        int p_tmp = p;
        vector<int> g_best(n + 1);

        if (p_tmp > k) {
            p_tmp = k;
        }

        // explore all p-tuples
        int numbers[n];
        std::iota(numbers, numbers + n, 0);
        init_permutation(numbers, numbers + p_tmp, numbers + n, true);

        do {
            vector<int> g = get_permutation(numbers, numbers + p_tmp, numbers + n, p_tmp);

            // Compute the vertices Vp covered by g
            std::vector<int> Vp;
            std::vector<int> covered(n);
            for (int i = 0; i < p_tmp; ++i) {

                for (int v = 0; v < n; ++v) {
                    if (D[g[i]][v] <= k - (i + 1)) {
                        Vp.push_back(v);
                        covered[v] = true;
                    }
                }
            }

            // Compute the subgraph induced by the vertices not covered by g
            vector<int> uncovered;
            uncovered.reserve(n);
            for (int i = 0; i < n; ++i) {
                if (!covered[i]) {
                    uncovered.push_back(i);
                }
            }
            vector<int> f = burning_sequence(k, uncovered);

            // concatenate sequence
            vector<int> g_seq = {g};
            for (int f_i: f) {
                g_seq.push_back(f_i);
            }

            // If needed add vertices to have a length of k
            std::vector<bool> C(n);
            int covered_count = 0;
            int S = g_seq.size();
            int i = 1;
            for (auto u: g_seq) {
                for (int v = 0; v < n; v++) {
                    if (D[u][v] <= S - i && !C[v]) {
                        C[v] = true;
                        covered_count++;
                    }
                }
                i++;
            }
            // Add vertices to complete the burning sequence
            while (covered_count < n) {
                int f_i = rand() % n;
                while (C[f_i]) {
                    f_i = rand() % n;
                }
                g_seq.push_back(f_i);
                S = g_seq.size();
                i = 1;
                for (auto u: g_seq) {
                    for (int v = 0; v < n; v++) {
                        if (D[u][v] <= S - i && !C[v]) {
                            C[v] = true;
                            covered_count++;
                        }
                    }
                    i++;
                }
            }
            // Save the best local sequence
            if (g_seq.size() < g_best.size()) {
                g_best = g_seq;
            }
        } while (next_permutation(numbers, numbers + p_tmp, numbers + n));
        // Save the best global sequence
        if (g_best.size() < f_best.size() || k == 1) {
            f_best = g_best;
        }
    }
    return f_best;
}

bool BonusSolver::isConnectedBFS() {
    queue<int> q;
    bool visited[n];
    int visitedCount = 0;
    q.push(0);
    visitedCount++;
    visited[0] = true;
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto u: adj[s]) {
            if (!visited[u]) {
                visitedCount++;
                visited[u] = true;
                q.push(u);
            }
        }
    }
    return visitedCount == n;
}

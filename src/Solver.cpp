//
// Created by ale_j on 8/17/2021.
//
#include <iostream>
#include <set>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <numeric>
#include "Solver.h"

#include "combinations/combinations.hpp"
#include "combinations/combinations_init.hpp"

using namespace boost;
using namespace boost::combinations;
using namespace std;

Solver::Solver(const int n, int **D) : n(n), D(D) {}

//vector<int> Solver::burning_sequence(int ** D, int k) {
//    set<int> C;
//    vector<int> f;
//    set<int> f_aux;
//    while (C.size() != n) {
//        int f_i = rand() % n;
//        while (C.find(f_i) != C.end()) {
//            f_i = rand() % n;
//        }
//        f.push_back(f_i);
//        f_aux.insert(f_i);
//        for (int v = 0; v < n; v++) {
//            if (D[f_i][v] <= 2 * (k - 1)) {
//                C.insert(v);
//            }
//        }
//    }
//    C.clear();
//    int S = f.size();
//    int i = 1;
//    for (auto f_i : f) {
//        for (int v = 0; v < n; v++) {
//            if (D[f_i][v] <= S - i) {
//                C.insert(v);
//            }
//        }
//        i++;
//    }
////    i = S + 1;
//    // second part
//    while (C.size() != n) {
//        int f_i = rand() % n;
//        while (f_aux.find(f_i) != f_aux.end()) {
//            f_i = rand() % n;
//        }
//        f.push_back(f_i);
//        f_aux.insert(f_i);
//        S = f.size();
//        i = 1;
//        for (auto u : f) {
//            for (int v = 0; v < n; v++) {
//                if (D[u][v] <= S - i) {
//                    C.insert(v);
//                }
//            }
//            i++;
//        }
//    }
//    return f;
//}

std::vector<int> Solver::burning_sequence(int k, vector<int> &V) {
    int n = V.size();
    std::vector<int> f;
    std::vector<bool> f_aux(n);
    std::vector<bool> C(n);

    // 1. Construct a sequence f
    int covered_count = 0;
    while (covered_count < n) {
        int f_i = rand() % n;
        while (C[f_i]) {
            f_i = rand() % n;
        }
        f.push_back(V[f_i]);
        f_aux[f_i] = true;
        int iv = 0;
        for (int v: V) {
            if (D[V[f_i]][v] <= 2 * (k - 1)) {
                if (!C[iv]) {
                    C[iv] = true;
                    if (++covered_count == n) break;
                }
            }
            iv++;
        }
    }

    // 2. Add extra vertices to f until all vertices in V are covered
    std::fill(C.begin(), C.end(), false);
    covered_count = 0;
    int S = f.size();
    int i = 1;
    for (auto u: f) {
        int iv = 0;
        for (int v: V) {
            if (D[u][v] <= S - i && !C[iv]) {
                C[iv] = true;
                covered_count++;
            }
            iv++;
        }
        i++;
    }
    // i = S + 1;
    // second part
    while (covered_count < n) {
        int f_i = rand() % n;
        while (C[f_i]) {
            f_i = rand() % n;
        }
        f.push_back(V[f_i]);
        f_aux[f_i] = true;
        S = f.size();
        i = 1;
        for (auto u: f) {
            int iv = 0;
            for (int v: V) {
                if (D[u][v] <= S - i && !C[iv]) {
                    C[iv] = true;
                    covered_count++;
                }
                iv++;
            }
            i++;
        }
    }
    return f;
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

int Solver::solve(int p) {
    int high = ceil(sqrt(n));
    vector<int> f_best(n + 1);
    for (int k = 1; k <= high; k++) {
        int p_tmp = p;
        vector<int> g_best(n + 1);

        if (p_tmp > k) {
            p_tmp = k;
        }

        // explore all p_tmp-tuples
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
            for (int i = 0; i < n; ++i) {
                if (!covered[i]) {
                    uncovered.push_back(i);
                }
            }
            auto f = burning_sequence(k, uncovered);

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
        if (g_best.size() < f_best.size()) {
            f_best = g_best;
        }
    }
    return f_best.size();
}




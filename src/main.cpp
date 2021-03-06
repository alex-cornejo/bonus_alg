#include <iostream>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/johnson_all_pairs_shortest.hpp>

#include "algorithm/BonusSolver.h"
#include "utils/FileUtil.h"
#include "algorithm/BFFSolver.h"

using namespace boost;
using namespace std;


int **computeAllShortestPaths(vector<pair<int, int>> &edges_vec, int n) {
    const int m = edges_vec.size();

    typedef adjacency_list<vecS, vecS, undirectedS, no_property,
            property<edge_weight_t, int, property<edge_weight2_t, int>>>
            Graph;

    typedef std::pair<int, int> Edge;
    Edge edges_array[m];
    for (int i = 0; i < m; ++i)
        edges_array[i] = Edge(edges_vec[i].first, edges_vec[i].second);

    Graph G(edges_array, edges_array + m, n);

    property_map<Graph, edge_weight_t>::type w = get(edge_weight, G);
    int weights[m];
    std::fill(weights, weights + m, 1);
    int *wp = weights;

    graph_traits<Graph>::edge_iterator e, e_end;
    for (boost::tie(e, e_end) = edges(G); e != e_end; ++e)
        w[*e] = *wp++;

    int **D = new int *[n];
    for (int i = 0; i < n; ++i) {
        D[i] = new int[n];
    }
    johnson_all_pairs_shortest_paths(G, D);
    return D;
}

int main(int argc, char **argv) {

    string input_file = argv[1];
    string alg = argv[2];

    // read instance
    vector<pair<int, int>> edges_vec;
    int n;
    tie(edges_vec, n) = FileUtil::load_graph(input_file);

    // time of compute all shortest paths
    clock_t begin = clock();
    int **D = computeAllShortestPaths(edges_vec, n);
    clock_t end = clock();
    double time_casp = (double) (end - begin) / CLOCKS_PER_SEC;
    // end computations of all shortest paths
    cout << "Compute all shortest paths running time: " << time_casp << " seconds" << endl;

    // time of algorithm
    vector<int> f;
    begin = clock();

    if (alg == "bon") {
        BonSolver solver(n, D);
        f = solver.run();
    } else if (alg == "bff") {
        BFFSolver solver(n, D, edges_vec);
        f = solver.run();
    } else if (alg == "bff+") {
        BFFSolver solver(n, D, edges_vec);
        solver.setPlus(true);
        f = solver.run();
    } else if (alg == "bonus") {
        int p = stoi(argv[3]);
        BonusSolver solver(n, D, p, edges_vec);
        f = solver.run();
    } else {
        cerr << "Invalid algorithm!" << endl;
    }
    end = clock();
    double time_alg = (double) (end - begin) / CLOCKS_PER_SEC;

    // print computations times and solution
    cout << "Algorithm running time: " << time_alg << " seconds" << endl;

    cout << "[";
    for (int i = 0; i < f.size() - 1; ++i) {
        cout << f[i] << ", ";
    }
    cout << f.back() << "]" << endl;
    cout << f.size() << endl;

    // clear memory
    for (int i = 0; i < n; ++i) {
        delete[] D[i];
    }
    return 0;
}

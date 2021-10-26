#include <iostream>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/johnson_all_pairs_shortest.hpp>
#include <numeric>
#include "Solver.h"

#include "utils/FileUtil.h"

#include "combinations/combinations.hpp"
#include "combinations/combinations_init.hpp"

using namespace boost;
using namespace std;
using namespace boost::combinations;

template<typename Iter>
vector<int> get_permutation(Iter first, Iter middle, Iter last, int k) {
    vector<int> perm(k);
    int i = 0;
    for (Iter itr = first; itr != middle; ++itr) {
        perm[i++] = *itr;
    }
    return perm;
}

int main(int argc, char **argv) {

    string input_file = argv[1];
    string alg = argv[2];
    int p = 1;
    if(alg == "bonus"){
        p = stoi(argv[3]);
    }

    // start time
    clock_t begin = clock();

    vector<pair<int, int>> edges_vec;
    int n;
    tie(edges_vec, n) = FileUtil::load_graph(input_file);
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

    Solver solver(n, D);
    int card = solver.solve(p);
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    cout << card << "," << time_spent << endl;
    return 0;
}

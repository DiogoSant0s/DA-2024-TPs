#include "../data_structures/Graph.h"

using namespace std;
template <typename T>

/****************** topsort ********************/
/*
 * Performs a topological sorting of the vertices of a graph.
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */
vector<T> topsort(const Graph<T>* g) {
    vector<T> res;
    vector<T> dfsOrder = g->dfs();
    reverse(dfsOrder.begin(), dfsOrder.end());
    for (int i = 0; i < dfsOrder.size(); ++i) {
        auto v = g->findVertex(dfsOrder[i]);
        for (auto &e : v->getAdj()) {
            auto w = e.getDest();
            if (v->getNum() <= w->getNum()) {
                return vector<T>();
            }
        }
        res.push_back(dfsOrder[i]);
    }
    return res;
}
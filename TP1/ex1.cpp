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
    vector<int> res;
    for (auto v : g->getVertexSet()) {
        v->setIndegree(0);
    }
    for (auto v : g->getVertexSet()) {
        for (auto e : v->getAdj()) {
            unsigned int indegree = e->getDest()->getIndegree();
            e->getDest()->setIndegree(indegree + 1);
        }
    }
    queue<Vertex<T>*> q;
    for (auto v : g->getVertexSet()) {
        if (v->getIndegree() == 0) {
            q.push(v);
        }
    }
    while(!q.empty()) {
        Vertex<T> * v = q.front();
        q.pop();
        res.push_back(v->getInfo());
        for(auto e : v->getAdj()) {
            auto w = e->getDest();
            w->setIndegree(w->getIndegree() - 1);
            if(w->getIndegree() == 0) {
                q.push(w);
            }
        }
    }
    if (res.size() != g->getVertexSet().size()) {
        std::cout << "Impossible topological ordering!" << std::endl;
        res.clear();
        return res;
    }
    return res;
}

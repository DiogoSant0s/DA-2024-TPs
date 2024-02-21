#include "../data_structures/Graph.h"
#include "stack"
using namespace std;

// Helper function to reverse the edges of a directed graph
template <typename T>
void aux_reverseGraphEdges(Graph<T>* g) {
    // TODO
}

// Kosaraju-Sharir algorithm to find strongly connected components
template <typename T>
vector<vector<T>> SCCkosaraju(Graph<T>* g)  {
    vector<vector<T>> sccs;
    for (auto v : g->getVertexSet()) {
        v -> setVisited(false);
    }
    stack<Vertex<T>*> vertexStack;
    for (auto v : g->getVertexSet()) {
        if (!v -> isVisited()) {
            firstDFSKosarajuSharir(v, vertexStack);
        }
    }
    for (auto v : g->getVertexSet()) {
        v -> setVisited(false);
    }
    while (!vertexStack.empty()) {
        Vertex<T>* v = vertexStack.top();
        vertexStack.pop();
        if (!v-> isVisited()) {
            vector<int> scc;
            secondDFSKosarajuSharir(v, scc);
            sccs.push_back(scc);
        }
    }
    return sccs;
}

// First depth-first search in Kosaraju-Sharir algorithm
template <typename T>
void firstDFSKosarajuSharir(Vertex<T> *v, stack<Vertex<T>*> *vertexStack)  {
    v -> setVisited(true);
    for (auto e : v -> getAdj()) {
        auto w = e -> getDest();
        if(!w -> isVisited()) {
            firstDfsKosarajuSharir(w, vertexStack);
        }
    }
    vertexStack->push(v);
}

// Second depth-first search in Kosaraju-Sharir algorithm
template <typename T>
void secondDFSKosarajuSharir(Vertex<T> *v, vector<int> & res)  {
    v -> setVisited(true);
    res.push_back(v->getId());
    for (auto& e : v -> getIncoming()) {
        auto w = e -> getOrig();
        if (!w -> isVisited()) {
            secondDfsKosarajuSharir(w, res);
        }
    }
}

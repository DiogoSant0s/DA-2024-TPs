// By: Gonçalo Leão

#ifndef DA_TP5_CLASSES_EXERCISES_H
#define DA_TP5_CLASSES_EXERCISES_H

#include <string>
#include <cmath>
#include <vector>

// Ex 1
// Recursive version
unsigned long factorialRecurs(unsigned long n);
// Version with dynamic programming
unsigned long factorialDP(unsigned long n);

// Ex 2
bool changeMakingUnlimitedDP(unsigned int C[], unsigned int n, unsigned int T, unsigned int usedCoins[]);

// Ex 3
bool changeMakingDP(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]);

// Ex 4
std::string calcSum(int sequence[], unsigned long n);
void testPerformanceCalcSum();

// Ex 5
unsigned long s_recursive(unsigned int n, unsigned int k);
unsigned long b_recursive(unsigned int n);
unsigned long s_dynamic(unsigned int n, unsigned int k);
unsigned long b_dynamic(unsigned int n);

// Ex 6
int maxSubsequenceDP(int A[], unsigned int n, unsigned int &i, unsigned int &j);
int maxSubsequenceBF(int A[], unsigned int n, unsigned int &i, unsigned int &j);
int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j);
void testPerformanceMaxSubsequence();

// Ex 7
std::string hanoiDP(unsigned int n, char src, char dest);

// Ex 8
unsigned int knapsackDP(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]);

// Ex 9
int editDistance(const std::string& pattern, const std::string& text);
float numApproximateStringMatching(const std::string& filename, const std::string& toSearch);

#include "../data_structures/Graph.h"
template <class T>
class DPGraph: public Graph<T> {
public:
    // Ex 10
    void dijkstra(const T &origin);
    std::vector<T> getPath(const T &origin, const T &dest) const;

    // Ex 11
    void bellmanFord(const T &origin);

    // Ex 12
    void floydWarshall();
    std::vector<T> getFloydWarshallPath(const T &origin, const T &dest) const;

protected:
    /**
    * Analyzes an edge in single source shortest path algorithm.
    * Returns true if the target vertex was relaxed (dist, path).
    * Used by all single-source shortest path algorithms.
    */
    //bool DPGraph::relax(Edge *edge);
    bool relax(Edge<T> *edge);
};

template<class T>
bool DPGraph<T>::relax(Edge<T> *edge) {
    if (edge->dest->dist > edge->orig->dist + edge->weight) {
        edge->dest->dist = edge->orig->dist + edge->weight;
        edge->dest->path = edge->orig;
        return true;
    }
    return false;
}

template<class T>
std::vector<T> DPGraph<T>::getFloydWarshallPath(const T &origin, const T &dest) const {

}

template<class T>
void DPGraph<T>::floydWarshall() {
    for (auto vertex : this->vertexSet) {
        for (auto edge : vertex->adj) {
            if (edge->weight < 0)
                throw std::logic_error("Graph has negative weights");
        }
    }

    for (auto k : this->vertexSet) {
        for (auto i : this->vertexSet) {
            for (auto j : this->vertexSet) {
                if (i != j && i != k && j != k) {
                    double d = i->dist + k->dist;
                    if (d < i->dist)
                        i->dist = d;
                }
            }
        }
    }
}

template<class T>
void DPGraph<T>::bellmanFord(const T &origin) {
    Vertex<T> *v = this->findVertex(origin);
    if (v == nullptr)
        return;

    for (auto vertex : this->vertexSet) {
        vertex->dist = INF;
        vertex->path = nullptr;
    }

    v->dist = 0;
    for (unsigned int i = 1; i < this->vertexSet.size(); i++) {
        for (auto vertex : this->vertexSet) {
            for (auto edge : vertex->adj) {
                relax(edge);
            }
        }
    }

    for (auto vertex : this->vertexSet) {
        for (auto edge : vertex->adj) {
            if (relax(edge))
                throw std::logic_error("Negative cycle");
        }
    }
}

template<class T>
std::vector<T> DPGraph<T>::getPath(const T &origin, const T &dest) const {
    std::vector<T> res;
    Vertex<T> *v = this->findVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for (; v != nullptr; v = v->path)
        res.insert(res.begin(), v->info);
    return res;
}

template<class T>
void DPGraph<T>::dijkstra(const T &origin) {
    Vertex<T> *v = this->findVertex(origin);
    if (v == nullptr)
        return;

    for (auto vertex : this->vertexSet) {
        vertex->dist = INF;
        vertex->path = nullptr;
    }

    v->dist = 0;
    MutablePriorityQueue<Vertex<T>> q;
    q.insert(v);

    while (!q.empty()) {
        v = q.extractMin();
        for (auto edge : v->adj) {
            if (relax(edge->dest, v, edge->weight))
                q.insert(edge->dest);
        }
    }

}

#endif //DA_TP5_CLASSES_EXERCISES_H

#include <iostream>
#include <vector>
#include <inttypes.h>
#include <algorithm>

#define MAX 1000010
typedef struct edge {
    int32_t from;
    int32_t to;
    int32_t cost;
} edge;

class Dsu{
public:
    Dsu(){
        p_.resize(MAX);
        rank_.resize(MAX);
        for (int32_t i = 0; i < MAX; ++i) {
            p_[i] = i;
            rank_[i] = 0;
        }
    }
    int dsu_get(int32_t v) {
        if (v == p_[v])
            return v;
        return p_[v] = dsu_get(p_[v]);
    }

    void dsu_unite(int32_t a, int32_t b) {
        a = dsu_get(a);
        b = dsu_get(b);
        if (a != b) {
            if (rank_[a] < rank_[b])
                std::swap (a, b);
            p_[b] = a;
            if (rank_[a] == rank_[b])
                ++rank_[a];
        }
    }
private:
    std::vector<int32_t> p_;
    std::vector<int32_t> rank_;
};

bool edge_sorter(edge const &lhs, edge const &rhs) {
    return lhs.cost < rhs.cost;
}

int main() {
    int32_t vert_num;
    int32_t edge_num;
    int32_t ans = 0;
    std::cin >> vert_num >> edge_num;
    std::vector<edge> graph;
    for (int32_t i = 0; i < edge_num; ++i) {
        int32_t from;
        int32_t to;
        int32_t cost;
        std::cin >> from >> to >> cost;
        graph.push_back({from, to, cost});
    }

    sort(graph.begin(), graph.end(), &edge_sorter);
    Dsu dsu;
    for (int32_t i = 0; i < graph.size(); ++i) {
        if (dsu.dsu_get(graph[i].from) != dsu.dsu_get(graph[i].to)) {
            ans += graph[i].cost;
            dsu.dsu_unite(graph[i].from, graph[i].to);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}


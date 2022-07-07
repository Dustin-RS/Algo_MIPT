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
    std::vector<int32_t> p_;
    std::vector<int32_t> size_;
    Dsu(){
        p_.resize(MAX);
        size_.resize(MAX);
        for (int32_t i = 0; i < MAX; ++i) {
            p_[i] = i;
            size_[i] = 0;
        }
    }
    void make_set(int32_t v){
        p_[v] = v;
        size_[v] = 0;
    }
    int dsu_get(int32_t v) {
        if (v == p_[v])
            return v;
        return p_[v] = dsu_get(p_[v]);
    }

    void dsu_unite(int32_t a, int32_t b, int32_t cost) {
        a = dsu_get(a);
        b = dsu_get(b);
        if (a != b) {
            if (size_[a] < size_[b])
                std::swap (a, b);
            p_[b] = a;
            size_[a] += size_[b] + cost;
        } else{
            size_[a] += cost;
        }
    }
};

int main() {
    int32_t vert_num;
    int32_t query_num;
    scanf("%d%d", &vert_num, &query_num);
    std::vector<edge> graph;
    Dsu dsu;
    int32_t it = 0;
    for (int32_t i = 0; i < query_num; ++i) {
        int32_t type;
        scanf("%d", &type);
        switch (type) {
            case 1:{
                int32_t from;
                int32_t to;
                int32_t cost;
                scanf("%d%d%d", &from, &to, &cost);
                graph.push_back({from, to, cost});
                dsu.dsu_unite(graph[it].from, graph[it].to, graph[it].cost);
                ++it;
                break;
            }
            case 2:{
                int32_t v;
                scanf("%d", &v);
                int32_t res = dsu.dsu_get(v);
                printf("%d\n", dsu.size_[res]);
                break;
            }
        }
    }
    return 0;
}


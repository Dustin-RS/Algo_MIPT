#include <iostream>
#include <vector>
#include<inttypes.h>

#define INF 30000
struct edge {
    int32_t from;
    int32_t to;
    int32_t cost;
};

int main() {
    int32_t vert_num;
    int32_t edge_num;
    std::cin >> vert_num >> edge_num;
    std::vector<edge> graph(edge_num + 1);
    std::vector<int32_t> dist(vert_num + 1, INF);
    for (int32_t i = 1; i <= edge_num; ++i) {
        int32_t from;
        int32_t to;
        int32_t cost;
        std::cin >> from >> to >> cost;
        graph[i] = {from, to, cost};
    }

    dist[1] = 0;
    bool flag = true;
    while(flag) {
        flag = false;
        for (int32_t j = 1; j <= edge_num; ++j) {
            if (dist[graph[j].from] < INF && dist[graph[j].to] > dist[graph[j].from] + graph[j].cost) {
                dist[graph[j].to] = dist[graph[j].from] + graph[j].cost;
                flag = true;
            }
        }
    }
    for(int32_t i=1;i<=vert_num;++i){
        std::cout<<dist[i]<<' ';
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <inttypes.h>
#include <algorithm>

#define INF 100000000
#define MAX 100000
struct edge {
    int32_t from;
    int32_t to;
    int32_t cost;
};

int main() {
    int32_t vert_num;
    int32_t edge_num = 0;
    std::cin >> vert_num;
    std::vector<edge> graph;
    std::vector<int32_t> dist(vert_num + 1);
    std::vector<int32_t> parent(vert_num + 1, -1);
    for (int32_t i = 1; i <= vert_num; ++i) {
        for (int32_t j = 1; j <= vert_num; ++j) {
            int32_t cost;
            std::cin>>cost;
            if(cost != MAX && cost != 0){
                graph.push_back({i,j,cost});
            }

        }
    }

    int32_t x = -1;
    for (int32_t i = 1; i <= vert_num; ++i) {
        x = -1;
        for (int32_t j = 0; j < graph.size(); ++j) {
            if (dist[graph[j].from] < MAX && dist[graph[j].to] > dist[graph[j].from] + graph[j].cost) {
                dist[graph[j].to] = std::max(-INF, dist[graph[j].from] + graph[j].cost);
                parent[graph[j].to] = graph[j].from;
                x = graph[j].to;
            }
        }
    }
    if (x == -1) {
        std::cout << "NO" << std::endl;
    } else {
        int32_t prev = x;
        for(int32_t i=0;i<=vert_num;++i){
            prev = parent[prev];
        }
        std::vector<int32_t> path;
        for(int32_t curr=prev; ;curr = parent[curr]){
            path.push_back(curr);
            if(curr == prev && path.size() > 1){
                break;
            }
        }
        std::cout << "YES" << std::endl << path.size() << std::endl;
        reverse(path.begin(), path.end());
        for(auto e : path){
            std::cout<<e<<" ";
        }
    }
    return 0;
}


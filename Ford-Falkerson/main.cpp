#include <iostream>
#include <inttypes.h>
#include <vector>
#define INF 1e5
#define EDGE 1e6
#define VERT 1e6
class Flow{
public:
    void add_edge(int32_t from, int32_t to, int32_t c){
        cost.push_back(c);
        straight_edge.push_back(to);
        reverse_edge.push_back(vert_stack[from]);
        vert_stack[from] = edge_count;
        ++edge_count;
        cost.push_back(0);
        straight_edge.push_back(from);
        reverse_edge.push_back(vert_stack[to]);
        vert_stack[to] = edge_count;
        ++edge_count;
    }

    int32_t dfs(int32_t v, int32_t min){
        if(v == stock){
            return min;
        }
        used[v] = true;
        for(int32_t vert = vert_stack[v]; vert != -1; vert = reverse_edge[vert]){
            int32_t find_min;
            if(!used[straight_edge[vert]] && cost[vert] > 0 && (find_min = dfs(straight_edge[vert], std::min(min, cost[vert]))) > 0){
                cost[vert] -= find_min;
                cost[vert^1] += find_min;
                return find_min;
            }
        }
        return 0;
    }

    Flow(){
        vert_stack.assign(VERT, -1);
        used.assign(VERT, false);
    }
    std::vector<int32_t> cost;
    std::vector<int32_t> straight_edge;
    std::vector<int32_t> reverse_edge;
    std::vector<int32_t> vert_stack;
    std::vector<bool> used;
    int32_t stock;
    int32_t edge_count;
};
int32_t main() {
    int32_t n;
    int32_t m;
    std::cin>>n>>m;
    Flow flow;
    flow.stock = n;
    flow.edge_count = 0;
    for(int32_t i=0;i<m;++i){
        int32_t from;
        int32_t to;
        int32_t cost;
        std::cin>>from>>to>>cost;
        flow.add_edge(from,to,cost);
    }

    int32_t ans = 0;
    int32_t it = flow.dfs(1,INF);
    while(it > 0){
        ans += it;
        flow.used.assign(VERT, false);
        it = flow.dfs(1,INF);
    }
    std::cout<<ans<<std::endl;
    return 0;
}


#include <inttypes.h>

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define INF 1e5
#define EDGE 1e6
#define VERT 1e6

struct Edge{
  int32_t from;
  int32_t to;
  int32_t cost;
  int32_t func;
};
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
        edges[vert].func += find_min;
        edges[vert^1].func -= find_min;
        return find_min;
      }
    }
    return 0;
  }

  void dfs2(int v) {
    path.push_back(v);

    if(v == stock){
      return;
    }
    for (int id : graph[v]) {
      int vt = edges[id].to;

      if (!used[id] && edges[id].func == 1) {
        used[id] = true;
        dfs2(vt);
        break;
      }
    }
  }

  void printPath(int32_t start) {
    dfs2(start);

    for (int i : path) {
      std::cout << i << " ";
    }
    std::cout << "\n";

    path.clear();
  }

  Flow(int32_t vert_num = VERT){
    vert_stack.assign(VERT, -1);
    used.assign(VERT, false);
    graph.resize(vert_num);
  }
  std::vector<int32_t> cost;
  std::vector<int32_t> straight_edge;
  std::vector<int32_t> reverse_edge;
  std::vector<int32_t> vert_stack;
  std::vector<int32_t> path;
  std::vector<std::vector<int32_t>> graph;
  std::vector<Edge> edges;
  std::vector<bool> used;
  int32_t stock;
  int32_t edge_count;
};

int32_t main() {
  int32_t vert_num;
  int32_t edge_num;
  int32_t start;
  int32_t to;
  std::cin>>vert_num>>edge_num>>start>>to;
  Flow flow(vert_num + 1);
  flow.stock = to;
  flow.edge_count = 0;
  for(int32_t i=0;i<edge_num;++i){
    int32_t from;
    int32_t t;
    std::cin>>from>>t;
    flow.graph[from].push_back(flow.edges.size());
    flow.edges.push_back({from, t, 1, 0});
    flow.graph[t].push_back(flow.edges.size());
    flow.edges.push_back({t, from, 0, 0});
    flow.add_edge(from,t,1);
  }
  int32_t ans = 0;
  int32_t it = flow.dfs(start,INF);
  while(it > 0){
    ans += it;
    flow.used.assign(VERT, false);
    it = flow.dfs(start,INF);
  }
  if(ans>=2){
    std::cout<<"YES"<<std::endl;
    flow.used.assign(VERT, false);
    flow.printPath(start);
    flow.printPath(start);
  } else {
    std::cout<<"NO" <<std::endl;
  }
  return 0;
}

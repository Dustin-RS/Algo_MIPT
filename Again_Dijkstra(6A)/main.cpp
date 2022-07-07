#include <iostream>
#include <vector>

#define INF 1e9 + 1
void dijkstra(std::vector<std::vector<int32_t>>& gr, std::vector<int32_t>& dist, int32_t& from){
  std::vector<bool> used(gr.size());
  used[from] = true;
  used.assign(gr.size(), false);
  for(int32_t i=1;i<gr.size();++i){
    int32_t vert = -1;
    for(int32_t j=1;j<gr.size();++j){
        if(!used[j] && (vert==-1 || dist[j] < dist[vert])){
            vert = j;
        }
    }
    if(dist[vert] == INF){
        break;
    }
    used[vert] = true;
    for(int32_t j=1; j<gr[vert].size(); ++j){
        int32_t len = gr[vert][j];
        if(dist[vert] + len < dist[j] && len != -1 && !used[j]){
            dist[j] = dist[vert] + len;
        }
    }
  }
}
int main() {
  std::vector<std::vector<int32_t>> gr;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int32_t gr_sz;
  int32_t from;
  int32_t to;
  std::vector<int32_t> dist;
  scanf("%d%d%d", &gr_sz, &from, &to);
  gr.assign(gr_sz+1, std::vector<int32_t>(gr_sz+1));
  dist.assign(gr_sz+1, INF);
  for (int32_t i=1;i<=gr_sz;++i){
    for (int32_t j=1;j<=gr_sz;++j){
      int32_t weight;
      scanf("%d", &weight);
      gr[i][j] = weight;
    }
  }
  dist[from] = 0;
  for(int32_t i = 1; i<=gr_sz; ++i){
    if( gr[from][i]!=-1) {
        dist[i] = gr[from][i];
    }
  }
  dijkstra(gr, dist, from);
  if(dist[to] == INF){
      printf("%d", -1);
  }else {
      printf("%d", dist[to]);
  }
  return 0;
}


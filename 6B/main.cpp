#include <iostream>
#include <vector>
#include <set>
#define INF 2009000999

void dijkstra(std::vector<std::vector<std::pair<int32_t,int32_t>>>& gr, std::set<std::pair<int32_t, int32_t>>& set_gr,
              std::vector<int32_t>& dist){
    std::vector<bool> used(gr.size());
    used.assign(gr.size(), false);
    while(!set_gr.empty()){
        int32_t from = set_gr.begin()->second;
        used[from] = true;
        set_gr.erase(set_gr.begin());
        for(auto vert : gr[from]){
            if(!used[vert.first] && dist[vert.first] > dist[from] + vert.second) {

                if(dist[vert.first] != INF){
                    set_gr.erase(set_gr.find(std::make_pair( dist[vert.first],vert.first)));
                }
                dist[vert.first] = dist[from] + vert.second;
                set_gr.insert({dist[vert.first],vert.first});
            }
        }
    }
}
int main() {

    int32_t num;
    int32_t N;
    int32_t M;
    int32_t s;
    scanf("%d", &num);
    for(int32_t i=0;i<num;++i){
        scanf("%d%d", &N,&M);
        std::vector<std::vector<std::pair<int32_t,int32_t>>> gr(N,std::vector<std::pair<int32_t,int32_t>>{});
        std::set<std::pair<int32_t,int32_t>> set_gr{};
        std::vector<int32_t> dist(N, INF);
        for(int32_t j=0;j<M;++j){
            int32_t from;
            int32_t to;
            int32_t cost;
            std::cin>>from>>to>>cost;
            gr[from].push_back({to,cost});
            gr[to].push_back({from,cost});
        }
        scanf("%d",&s);
        dist[s] = 0;
        set_gr.insert({dist[s],s});
        dijkstra(gr, set_gr, dist);
        for(auto j : dist){
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}


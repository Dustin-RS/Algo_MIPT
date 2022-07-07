#include <iostream>
#include <vector>
#define INF 1e9

class Lca{
public:
    Lca(int32_t N=0){
        while ((1<<log) <= N) {
            ++log;
        }
        gr.resize(N);
        tout.resize(N);
        tin.resize(N);
        dist.assign(N, INF);
        h.resize(N);
        for (int32_t i=0; i<N; ++i){
            h[i].resize (log+1);
        }

        for (int32_t i = 0; i < N - 1; ++i) {
            int32_t from;
            int32_t to;
            std::cin >> from >> to;
            gr[from-1].push_back(to-1);
            gr[to-1].push_back(from-1);
        }
    }
    void dfs(int32_t v, int32_t he=0, int32_t p=0) {
        tin[v] = ++timer;
        h[v][0] = p;
        for (int32_t i = 1; i <= log; ++i) {
            h[v][i] = h[h[v][i - 1]][i - 1];
        }
        dist[v] = he;
        for (int32_t i = 0; i <= log; ++i) {
            if(dist[i]!=INF){
                continue;
            }
            dist[i] = dist[v] + 1;
        }
        for (int32_t i = 0; i < gr[v].size(); ++i) {
            if (gr[v][i] != p) {
                dfs(gr[v][i],he+1,v);
            }
        }
        tout[v] = ++timer;
    }
    bool is_par(int32_t a, int32_t b) {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    }

    int32_t lca(int32_t a, int32_t b){
        if(is_par(a,b)){
            return a;
        }
        if(is_par(b,a)){
            return b;
        }
        for(int32_t i=log;i>=0;--i){
            if(!is_par(h[a][i], b)){
                a = h[a][i];
            }
        }
        return h[a][0];
    }
    std::vector<std::vector<int32_t>> gr;
    std::vector<int64_t> tout;
    std::vector<int64_t> tin;
    std::vector<int64_t> dist;
    std::vector<std::vector<int32_t>> h;
    int32_t log=1;
    int64_t timer=0;
};

int main() {
    int32_t N;
    int32_t M;
    std::cin>>N;
    Lca l(N);

    l.dfs(0);
    std::cin >> M;
    int32_t a;
    int32_t b;
    while(M){
        std::cin>>a>>b;
        int32_t res = l.dist[a-1] + l.dist[b-1] - 2*l.dist[l.lca(a-1,b-1)];
        std::cout<<res<<std::endl;;
        --M;
    }
    return 0;
}


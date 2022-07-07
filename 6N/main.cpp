#include <iostream>
#include <vector>

class Lca{
public:
    Lca(int32_t N=0){
        while ((1<<log) <= N) {
            ++log;
        }
        gr.resize(N);
        tout.resize(N);
        tin.resize(N);
        h.resize(N);
        for (int32_t i=0; i<N; ++i){
            h[i].resize (log+1);
        }

        for (int32_t i = 1; i < N; ++i) {
            int32_t from;
            std::cin >> from;
            gr[from].push_back(i);
            gr[i].push_back(from);
        }
    }
    void dfs(int32_t v, int32_t p = 0) {
        tin[v] = ++timer;
        h[v][0] = p;
        for (int32_t i = 1; i <= log; ++i) {
            h[v][i] = h[h[v][i - 1]][i - 1];
        }
        for (int32_t i = 0; i < gr[v].size(); ++i) {
            if (gr[v][i] != p) {
                dfs(gr[v][i],v);
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
            if(is_par(h[a][i], b)){
                continue;
            }
            a = h[a][i];
        }
        return h[a][0];
    }
    std::vector<std::vector<int32_t>> gr;
    std::vector<int64_t> tout;
    std::vector<int64_t> tin;
    std::vector<std::vector<int32_t>> h;
    int32_t log=1;
    int64_t timer=0;
};

int main() {
    int32_t N;
    int32_t M;
    std::cin>>N>>M;
    Lca l(N);

    l.dfs(0);

    int32_t a1;
    int32_t a2;
    int64_t x;
    int64_t y;
    int64_t z;
    int32_t v = 0;
    int64_t sum = 0;

    std::cin >> a1 >> a2;
    std::cin >> x >> y >> z;

    for(int32_t i = 0; i < M; ++i) {
        v = l.lca((a1 + v) % N, a2);
        sum += v;
        a1 = (x * a1 + y * a2 + z) % N;
        a2 = (x * a2 + y * a1 + z) % N;
    }
    std::cout << sum;
    return 0;
}


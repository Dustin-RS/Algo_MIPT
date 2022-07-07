#include <iostream>
#include <vector>

std::vector<int32_t> p_;
std::vector<int32_t> rank_;
int32_t get_par(int32_t v){
    if(v == p_[v]){
        return v;
    }
    p_[v] = get_par(p_[v]);
    return p_[v];
}
void unite(int32_t a, int32_t b){
    a = get_par(a);
    b = get_par(b);
    if(a != b){
        if(rank_[b] > rank_[a]){
            std::swap(a,b);
        }
        p_[b] = a;
        rank_[a] += rank_[b];
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int32_t n;
    int32_t m;
    int32_t k;
    std::cin>>n>>m>>k;
    p_.resize(n+1);
    rank_.assign(n+1, 0);
    std::vector<std::vector<int32_t>> inp;
    for(int32_t i=0;i<m;++i){
        int32_t from;
        int32_t to;
        std::cin>>from>>to;
    }
    for(int32_t i=0;i<k;++i){
        std::string ans;
        int32_t u;
        int32_t v;
        int32_t t=0;
        std::cin>>ans>>u>>v;
        if(ans[0] == 'a'){
            t = 1;
        }
        inp.push_back({t,u,v});
    }
    std::vector<std::string> tot_ans;
    for(int32_t i = 1; i <= n; ++i){
        p_[i] = i;
    }
    for(int32_t i=k-1;i>=0;--i){
        if(inp[i][0]){
            if(get_par(inp[i][1]) == get_par(inp[i][2])){
                tot_ans.emplace_back("YES\n");
            }else{
                tot_ans.emplace_back("NO\n");;
            }
        }else{
            unite(inp[i][1], inp[i][2]);
        }
    }
    for(int32_t i = tot_ans.size() - 1; i >= 0; --i){
        std::cout<<tot_ans[i];
    }
    return 0;
}


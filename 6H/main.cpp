#include <iostream>
#include <inttypes.h>
#include <vector>
#include <math.h>
#define INF 1e9
int main() {
    int32_t N;
    std::cin>>N;
    std::vector<std::pair<int32_t, int32_t>> vert(N, {0,0});
    for(int32_t i=0;i<N;++i){
        std::cin>>vert[i].first >> vert[i].second;
    }
    std::vector<bool> used(N);
    std::vector<double> left_e(N, INF);
    std::vector<int32_t> right_e(N, (-1)*INF);
    left_e[0] = 0;
    double ans = 0;
    for(int32_t i=0;i<N;++i){
        int32_t v = -1;
        for(int32_t j=0;j<N;++j){
            if(!used[j] && (v == -1 || left_e[j] < left_e[v]) ){
                v = j;
            }
        }
        used[v] = true;
        for(int32_t j=0;j<N;++j){
            int32_t x1 = vert[v].first;
            int32_t y1 = vert[v].second;
            int32_t x2 = vert[j].first;
            int32_t y2 = vert[j].second;

            double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
            if(dist<left_e[j]){
                left_e[j] = dist;
                right_e[j] = v;
            }
        }
        double min = INF;
        for(int32_t j = 1; j < N; ++j){
            if(left_e[j] == 0){
                continue;
            }
            if(left_e[j] < min){
                min = left_e[j];
            }
        }
        if(min == INF){
            min = 0;
        }
        ans+=min;
    }
    printf("%.10f", ans);
    return 0;
}


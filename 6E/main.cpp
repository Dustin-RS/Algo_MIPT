#include <iostream>
#include <vector>
#include <inttypes.h>
#include <algorithm>

int main() {
    int32_t vert_num;
    std::cin >> vert_num;
    std::vector<std::vector<int32_t>> graph(vert_num+1, std::vector<int32_t>(vert_num+1));
    std::vector<std::vector<int32_t>> ans(vert_num+1, std::vector<int32_t>(vert_num+1));
    for(int32_t i=1;i<=vert_num;++i){
        for(int32_t j=1;j<=vert_num;++j){
            std::cin>>graph[i][j];
        }
    }

    for(int32_t k=1;k<=vert_num;++k){
        for(int32_t i=1;i<=vert_num;++i){
            for(int32_t j=1;j<=vert_num;++j){
                if(graph[i][k] && graph[k][j]){
                    graph[i][j] = 1;
                }
            }
        }
    }
    for(int32_t k=1;k<=vert_num;++k){
        for(int32_t i=1;i<=vert_num;++i){
            std::cout<<graph[k][i]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}


#include <inttypes.h>

#include <iostream>
#include <vector>
#include<bits/stdc++.h>

void Dfs(int32_t vert, std::vector<bool>& used, std::vector<std::set<int32_t>>& gr) {
  used[vert] = true;
  for(auto e : gr[vert]){
    if(!used[e]){
      Dfs(e, used, gr);
    }
  }
}

int32_t main() {
  int32_t m;
  int32_t n;
  std::cin >> m >> n;
  std::vector<std::set<int32_t>> gr(m + n + 1);
  for (int32_t i = 1; i <= m; ++i) {
    int32_t num;
    std::cin >> num;
    for (int32_t j = 1; j <= num; ++j) {
      int32_t right;
      std::cin>>right;
      gr[i].insert(right + m);
    }
  }
  std::set<int32_t> MM;
  for (int32_t i = 1; i <= m; ++i) {
    int32_t right;
    std::cin >> right;
    if(right == 0){
      MM.insert(i);
    }
    gr[i].erase(right+m);
    gr[right + m].insert(i);
  }
  std::vector<bool> used(m + n+2, false);
  for(auto e : MM){
    Dfs(e,used,gr);
  }


  std::set<int32_t> a;
  std::set<int32_t> b;
  for (int i = 1; i <= m; ++i)
    if (!used[i])
      a.insert(i);

  for (int i = 1; i <= n; ++i)
    if (used[m + i])
      b.insert(i + m);

  std::cout<<a.size() + b.size()<<std::endl;
  std::cout<<a.size()<<" ";
  for(auto it : a){
    std::cout<<it<<" ";
  }
  std::cout<<std::endl<<b.size()<<" ";
  for(auto it : b){
    std::cout<<it-m<<" ";
  }

  return 0;
}

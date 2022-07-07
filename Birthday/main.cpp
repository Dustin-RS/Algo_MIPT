#include <inttypes.h>

#include <iostream>
#include <vector>
#include<bits/stdc++.h>

bool Kuhn(int32_t v, std::vector<bool> &used, std::vector<int32_t> &MM, std::vector<std::set<int32_t>> &gr) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (auto vert: gr[v]) {
    if (MM[vert] == -1 || Kuhn(MM[vert], used, MM, gr)) {
      MM[vert] = v;
      MM[v] = vert;
      return true;
    }
  }
  return false;
}

void Dfs(int32_t vert, std::vector<bool> &used, std::vector<std::set<int32_t>> &gr) {
  used[vert] = true;
  for (auto e: gr[vert]) {
    if (!used[e]) {
      Dfs(e, used, gr);
    }
  }
}

int32_t main() {
  int32_t q;
  std::cin >> q;
  while (q > 0) {
    --q;
    int32_t m;
    int32_t n;
    std::cin >> m >> n;
    std::vector<std::set<int32_t>> gr(m + n + 1);
    for (int32_t i = 1; i <= m; ++i) {
      int32_t right;
      std::cin >> right;
      while (right != 0) {
        gr[i].insert(right + m);
        std::cin >> right;
      }
    }
    for (int32_t i = 1; i <= m; ++i) {
      for (int32_t j = m + 1; j <= m + n; ++j) {
        auto res = gr[i].find(j);
        if (res != gr[i].end()) {
          gr[i].erase(j);
        } else {
          gr[i].insert(j);
        }
      }
    }
    std::vector<int32_t> MM(m + n + 1, -1);
    std::vector<bool> used(m + n + 2, false);
    for (int32_t i = 1; i <= m; ++i) {
      Kuhn(i, used, MM, gr);
      used.assign(m + n + 2, false);
    }
    for (int32_t i = 1; i <= m; ++i) {
      if(MM[i]!=-1){
        gr[i].erase(MM[i]);
        gr[MM[i]].insert(i);
      }
    }
    for (int32_t i = 1; i <= m; ++i) {
      if (MM[i] == -1) {
        Dfs(i, used, gr);
      }
    }

    std::vector<int32_t> a;
    std::vector<int32_t> b;
    for (int i = 1; i <= m; ++i)
      if (used[i])
        a.push_back(i);

    for (int i = 1; i <= n; ++i)
      if (!used[m + i])
        b.push_back(i + m);

    std::cout << a.size() + b.size() << std::endl;
    std::cout << a.size() << " " << b.size() << std::endl;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (auto it: a) {
      std::cout << it << " ";
    }
    std::cout << std::endl;
    for (auto it: b) {
      std::cout << it - m << " ";
    }
    std::cout << "\n" << std::endl;
    gr.clear();
    used.clear();
    a.clear();
    b.clear();
    MM.clear();
  }
  return 0;
}

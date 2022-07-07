#include <cmath>
#include <iostream>
#include <vector>
#define CONST_FORM5 5
#define CONST_FORM13 13
#define CONST_FORM17 17
#define CONST_FORM23 23
#define CONST_FORM593 593
#define CONST_FORM751 751
#define CONST_FORM21563 21563
#define CONST_FORM16714589 16714589
#define NEUTRAL_ELEMENT 1e9
uint32_t KthQuer(size_t q_amount, size_t soldiers_in_army,
                 std::vector<std::pair<uint32_t, uint32_t>>& l_r_section,
                 int32_t** sparse_table, std::vector<uint32_t> sec_degs) {
  uint32_t ans;
  for (size_t i = 1; i <= q_amount; ++i) {
    int32_t l =
        std::min(l_r_section[i - 1].first, l_r_section[i - 1].second) - 1;
    int32_t r =
        std::max(l_r_section[i - 1].first, l_r_section[i - 1].second) - 1;
    ans = std::min(sparse_table[sec_degs[r - l + 1]][l],
                   sparse_table[sec_degs[r - l + 1]]
                               [r - (1 << (sec_degs[r - l + 1])) + 1]);
    if (i == q_amount) {
      break;
    }
    l_r_section[i].first = (CONST_FORM17 * l_r_section[i - 1].first +
                            CONST_FORM751 + ans + 2 * i) %
                               soldiers_in_army +
                           1;
    l_r_section[i].second = (CONST_FORM13 * l_r_section[i - 1].second +
                             CONST_FORM593 + ans + CONST_FORM5 * i) %
                                soldiers_in_army +
                            1;
  }
  return ans;
}
void SparseTableInit(int32_t**& sparse_table, size_t tmp,
                     size_t soldiers_in_army,
                     std::vector<uint32_t> soldiers_heigh) {
  for (size_t i = 0; i < tmp; ++i) {
    sparse_table[i] = new int32_t[soldiers_in_army];
    for (size_t j = 0; j < soldiers_in_army; ++j) {
      sparse_table[i][j] = NEUTRAL_ELEMENT;
    }
  }
  for (size_t i = 0; i < soldiers_in_army; ++i) {
    sparse_table[0][i] = soldiers_heigh[i];
  }
  for (size_t i = 1; i < tmp; ++i) {
    for (size_t j = 0; j < soldiers_in_army; ++j) {
      sparse_table[i][j] = std::min(sparse_table[i - 1][j],
                                    sparse_table[i - 1][j + (1 << (i - 1))]);
    }
  }
}
void Clear(int32_t**& sparse_table, size_t tmp) {
  for (size_t i = 0; i < tmp; ++i) {
    delete[] sparse_table[i];
  }
  delete[] sparse_table;
}
int main() {
  size_t soldiers_in_army;
  uint32_t q_amount;
  std::cin >> soldiers_in_army >> q_amount;
  std::vector<uint32_t> soldiers_heigh(soldiers_in_army);
  std::vector<std::pair<uint32_t, uint32_t>> l_r_section(
      q_amount,
      std::pair<uint32_t, uint32_t>(NEUTRAL_ELEMENT, NEUTRAL_ELEMENT));
  std::cin >> soldiers_heigh[0] >> l_r_section[0].first >>
      l_r_section[0].second;
  for (size_t i = 1; i < soldiers_in_army; i++) {
    soldiers_heigh[i] =
        (CONST_FORM23 * soldiers_heigh[i - 1] + CONST_FORM21563) %
        CONST_FORM16714589;
  }
  size_t tmp = (size_t)(log2((double)(soldiers_in_army))) + 1;
  std::vector<uint32_t> sec_degs(soldiers_in_army + 1);
  for (size_t i = 0; i < soldiers_in_army + 1; ++i) {
    sec_degs[i] = floor(log2((double)(i)));
  }
  int32_t** sparse_table = new int32_t*[tmp];
  SparseTableInit(sparse_table, tmp, soldiers_in_army, soldiers_heigh);
  uint32_t ans =
      KthQuer(q_amount, soldiers_in_army, l_r_section, sparse_table, sec_degs);
  std::cout << l_r_section.back().first << " " << l_r_section.back().second
            << " " << ans;
  Clear(sparse_table, tmp);
  return 0;
}
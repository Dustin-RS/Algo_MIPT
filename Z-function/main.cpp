#include <iostream>
#include <string.h>
#include <vector>
#include<inttypes.h>
#define MAX_PRIME 31

std::vector<int32_t> z_function (std::string s) {
  int32_t n = s.length();
  std::vector<int32_t> z (n);
  for (int32_t i=1, l=0, r=0; i<n; ++i) {
    if (i <= r)
      z[i] = std::min(r-i+1, z[i-l]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      ++z[i];
    if (i+z[i]-1 > r)
      l = i,  r = i+z[i]-1;
  }
  return z;
}
int main() {
  std::string inp;
  std::cin>>inp;
  auto ans = z_function(inp);
  ans[0] = inp.length();
  for(auto item : ans){
    std::cout<<item<<" ";
  }
  std::cout<<std::endl;
  return 0;
}


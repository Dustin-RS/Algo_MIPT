#include <iostream>
#include <string.h>
#include <vector>
#define MAX_PRIME 31


int main() {
  int32_t N;
  std::cin>>N;
  std::vector<int32_t> z(N);
  std::vector<int32_t> pref(N);
  std::vector<char> sigma = {'a'};
  std::string ans = "a";
  ans.resize(N);
  for(int32_t i=0;i<N;++i){
    int32_t p;
    std::cin>>p;
    z[i] = p;
  }

  for(int i = 1; i < N; i++)
    if(z[i]){
      for(int j = z[i] - 1; j >= 0 && !(pref[i + j]); j--){
        pref[i + j] = j + 1;
      }
    }

  for(int32_t i=1;i<N;++i){
    if(pref[i] == 0){
      for(auto let : sigma){
        ans[i] = let;

        auto tmp = pref[i - 1];
        while(true){
          if(tmp <= 0 || ans[tmp] == ans[i]){
            break;
          }
          tmp = pref[tmp - 1];
        }
        if(ans[tmp] == ans[i]) {
          ++tmp;
        }
        if(tmp == 0){
          break;
        }

        char last_letter = sigma[sigma.size() - 1];
        if(ans[i] == last_letter){
          sigma.push_back(last_letter + 1);
          ans[i] = last_letter + 1;
        }
      }
    }else if(pref[i] != 0) {
      ans[i] = ans[pref[i] - 1];
    }
  }
  std::cout<<ans;
  return 0;
}


#include <iostream>
#include <string.h>
#include <vector>
#define MAX_PRIME 31


int main() {
  std::string text;
  std::string substring;
  std::cin>>text>>substring;
  std::vector<int64_t> pow_p(std::max(substring.length(), text.length()));
  pow_p[0] = 1;
  for(int32_t i=1;i<pow_p.size();++i){
    pow_p[i] = MAX_PRIME * pow_p[i-1];
  }

  std::vector<int64_t> pref_hash_t(text.length());
  for(int32_t i=0;i<text.length(); ++i){
    pref_hash_t[i] = (text[i] - 'a' + 1) * pow_p[i];
    if(i){
      pref_hash_t[i] += pref_hash_t[i-1];
    }
  }

  int64_t hash_substring = 0;
  for(int32_t i=0;i<substring.length();++i){
    hash_substring += (substring[i] - 'a' + 1) * pow_p[i];
  }

  for(int32_t i=0; i + substring.length() - 1 < text.length(); ++i){
    int64_t tmp = pref_hash_t[i+substring.length() - 1];
    if(i){
      tmp -= pref_hash_t[i - 1];
    }
    if(hash_substring * pow_p[i] == tmp){
      std::cout<<i<<std::endl;
    }
  }
  return 0;
}


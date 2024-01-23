#include <iostream>
#include <string>

std::string compressString(std::string s) {
  std::string ns = "";
  
  if (s.empty()) { return s; }
  
  int ctr = 0;
  char ctd_char = s[0];
  for (char ch : s) {
    if (ch != ctd_char) {
      ns += ctd_char + std::to_string(ctr);
      ctd_char = ch;
      ctr = 1;
    } else {
      ctr++;
    }
  }
  ns += ctd_char + std::to_string(ctr);

  if (ns.length() >= s.length()) {
    return s;
  }
  return ns;
}


int main() {
  std::string test = "aabcccccaaa";
  std::string test1 = "AABCCCCCAAAaaa";
  std::cout << test << " compresses to " << compressString(test) << std::endl; 
  std::cout << test1 << " compresses to " << compressString(test1) << std::endl; 
  return 0;
}

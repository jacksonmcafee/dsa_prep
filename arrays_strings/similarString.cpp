#include <iostream>
#include <string>
#include <map>

/*
*  This provides an example of how to verify that one string is 
*  within one edit, insertion, or deletion from another. 
*
*  An "edit" is a swap from one character to another, where an 
*  insertion or deletion is the introduction or removal of a character.
*
*  similarString() runs in O(n) time where n is the size of the larger 
*  string between s1 and s2.
*  It uses O(n) space, where n is the size of the larger string 
*  between s1 and s2. 
*
*  This could potentially be optimized to be in O(1) space if 
*  you created an iterator across the length of both strings and 
*  checked for differences. Once a difference was reached, you could 
*  simply return false at that point. To be added later. 
*/

bool similarString(std::string s1, std::string s2) {
  int L1 = s1.length();
  int L2 = s2.length();

  if (L1 != L2 && L1 + 1 != L2 && L1 - 1 != L2) { 
    return false;
  }

  std::map<char, int> cm1, cm2;
  for (char ch : s1) {
    cm1[ch]++;
  }
  for (char ch : s2) {
    cm2[ch]++;
  }

  int offBy = 0;

  for (auto kv : cm1) {
    if (kv.second != cm2[kv.first]) {
      offBy++;
    }
    if (offBy > 1) { return false; }
  }
  return true;
}

int main() {
  std::string test1, test2, test3, test4;
  test1 = "pale";
  test2 = "ple";
  test3 = "tale";
  test4 = "tile";

  std::cout << similarString(test1, test2) << std::endl;
  std::cout << similarString(test1, test3) << std::endl;
  std::cout << similarString(test1, test4) << std::endl;
  std::cout << similarString(test3, test4) << std::endl;

  return 0;
}

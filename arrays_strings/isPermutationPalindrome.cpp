#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>

/*
*  This provides two examples of how to verify that a string 
*  is a permutation of a palindromic string.
*
*  isPermPalindromeMap() uses a map to verify this. 
*  isPermPalindromeSort() uses a string sort to verify this.
*
*  isPermPalindromeMap() runs in O(n) time where n is the size of the string s.
*  It uses O(n) space where n is roughly equal to the size of the string s.
*
*  isPermPalindromeSort() runs in O(n log n) time where n is the size of the string s.
*  It uses O(n) space where n is the size of the string s.
*/ 

bool isPermPalindromeMap(std::string s) {
  std::map<char, int> cm;
  for (char ch : s) {
    if (isalpha(ch)) {
      ch = tolower(ch);
      cm[ch]++;
    }
  }

  int ctr = 0;
  for (auto kv : cm) {
    if (kv.second % 2 == 1) {
      ctr++;
    }
    if (ctr > 1) {
      return false;
    }
  }
  return true;
}

bool isPermPalindromeSort(std::string s) {
  std::string clean = "";
  for (char ch : s) {
    if (isalpha(ch)) {
      clean += tolower(ch);
    }
  }

  std::sort(clean.begin(), clean.end());
  int ctr = 0;
  
  for (int i = 1; i < clean.size(); i += 2) {
    if (clean[i] != clean[i-1]) {
      ctr++;
      i++;
    }
    if (ctr > 1) {
      return false;
    }
  }

  return true;
}

int main() {
  std::string test1 = "Tact Coa";
  std::string test2 = "A Man A Plan A Canal Panama";
  std::string test3 = "Racecor";
  
  std::cout << isPermPalindromeMap(test1) << std::endl;
  std::cout << isPermPalindromeMap(test2) << std::endl;
  std::cout << isPermPalindromeMap(test3) << std::endl;


  std::cout << isPermPalindromeSort(test1) << std::endl;
  std::cout << isPermPalindromeSort(test2) << std::endl;
  std::cout << isPermPalindromeSort(test3) << std::endl;

  return 0;
}

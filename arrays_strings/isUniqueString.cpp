#include <iostream>
#include <string>
#include <set>

/*
*  This provides two examples of how to verify that a string
*  is composed entirely of unique characters. 
*
*  checkStringWithSet() uses a set to verify this.
*  checkStringWithoutSet() uses an array to verify instead.
*  This second implementation assumes an input that is lowercase alphabetic.
*  It can be extended to include uppercase, numerics, and others by swapping
*  the size of carr[], comparison character, and initializing character to account for it.
*
*  Either should run in O(n) time where n is the number of characters in s.
*  Either should run in O(m) space where m is the size of s. This is because 
*  the array will be roughly the same size as s and the set is guaranteed to be 
*  less than or equal to in size to s.
*
*  A funny option would be the brute force approach of checking each character
*  against one another to verify, which would be in O(1) space but would 
*  be in O(n^2) time. 
*
*  Another option if constant space is needed but the string is mutable is to 
*  sort the array and then compare adjacent characters to one another. This could
*  go afoul if the sorting algorithm implemented requires extra space, but if not
*  this could be done in O(n log n) time and O(1) space.
*/


bool checkStringWithSet(std::string s) {
  std::set<char> cs;
  for (char ch : s) {
    if (cs.find(ch) != cs.end()) {
      return false;
    }
    cs.insert(ch);
  }
  return true;
}

bool checkStringWithoutSet(std::string s) {
  char carr[26] = {
                   '0','0','0','0','0','0',
                   '0','0','0','0','0','0',
                   '0','0','0','0','0','0',
                   '0','0','0','0','0','0',
                   '0','0'
                  };
  for (char ch : s) {
    if (carr[ch - 'a'] != '0') {
      return false;
    }
    carr[ch-'a'] = ch;
  }
  return true;
}

int main() {
  std::string test[6] = {"abcdefg", "aabcdefg", "abcdefgg", "thisstring", "thatstring", "abcdefghijklmnopqrstuvwxyz"};

  for (std::string s : test) {
    std::cout << s << " is " << checkStringWithSet(s) << " / " << checkStringWithoutSet(s) << std::endl;
  }

  return 0;
}

#include <iostream>
#include <string>

/*
*  This program determines if a given string 
*  is a rotated substring of another string.
*
*  It has a time complexity of O(n + m), where 
*  n is the size of s1 and m is the size of s2.
*  It has a space complexity of O(n) where n is the size 
*  of s1. This is because we have to create a 
*  spare string that is double the length of s1.
*/

bool isRotation(std::string s1, std::string s2) {
  if (s1.length() != s2.length()) {
    return false;
  }
  std::string doubled = s1 + s1;
  if (doubled.find(s2) == std::string::npos) {
    return false;
  }
  return true;
}

int main() {
  std::string s1 = "abcdefgh";
  std::string s2 = "ghabcdef";
 
  std::cout << s1 << (isRotation(s1, s2) ? " is " : " is not ") << "a rotation of " << s2 << std::endl;
  return 0;
}

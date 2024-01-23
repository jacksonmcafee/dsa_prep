#include <iostream>

/*
*  This provides an example of how to "URLify" a char array.
*  URLify, at least by the CTCI book's definition, is to
*  replace all spaces with "%20". This must be done in
*  constant space. No requirements are placed on time.
*
*  URLify() counts the number of spaces in the string, 
*  then calculates full size needed to perform this operation 
*  to get the max size. It then iterates backwards through
*  the char array and shifts characters as needed.
*
*  It runs in O(n) time where n is the size of the array
*  as it must fully iterate through twice to count spaces and 
*  perform the operation.
*  It runs in O(1) space because no new space is needed given
*  that the array has enough space necessary to start.
*/


char* URLify(char* s, int real_size) {
  int spaces = 0;
  for (int i = 0; i < real_size; ++i) {
    if (s[i] == ' ') {
      spaces++;
    }
  }

  int extendedSize = real_size + spaces * 2; 
  int index = extendedSize - 1;

  for (int i = real_size - 1; i >= 0; --i) {
    if (s[i] == ' ') {
      s[index] = '0';
      s[index - 1] = '2';
      s[index - 2] = '%';
      index -= 3;
    } else {
      s[index] = s[i];
      index--;
    }
  }

  return s;
}

int main() {
  char* s = new char[10];
  s[0] = 't';
  s[1] = 'h';
  s[2] = ' ';
  s[3] = 'a';
  s[4] = ' ';
  s[5] = 't';
  int rs = 6;

  std::cout << s << std::endl;
  s = URLify(s, rs);
  std::cout << s << std::endl;
  
  return 0; 
}

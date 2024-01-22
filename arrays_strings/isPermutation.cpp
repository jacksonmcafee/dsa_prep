#include <iostream>
#include <string>
#include <map>
#include <algorithm>

/*
*   This provides two examples of how to verify that a pair of
*   strings are permutations of one another.
*
*   isPermutationSort() sorts using the inbuilt sorting algorithm 
*   (which is introsort when compiled on G++). It then performs a string
*   comparison to determine whether strings are permutations.
*   This function is in O(n log n) time because of the sort.
*   This function is in O(1) space because the sort is done in place. 
*
*   isPermutationMap() uses a map of characters and their counts
*   and then compares the maps to determine whether strings are
*   permutations.
*   This function is in O(n) time where n is the length of 
*   the longer string between s1 and s2. 
*   This function is in O(m) space where m the is larger number 
*   of unique characters between s1 and s2.
*/ 

bool isPermutationSort(std::string s1, std::string s2) {
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  return s1 == s2;
}

bool isPermutationMap(std::string s1, std::string s2) {
  std::map<char, int> cm1;
  std::map<char, int> cm2;

  for (char ch : s1) {
    cm1[ch]++;
  }
  for (char ch : s2) {
    cm2[ch]++;
  }

  return cm1 == cm2;
}

int main() {
  std::string s1 = "abcd";
  std::string s2 = "abcde";
  std::string s3 = "";
  std::string s4 = "aaaaaaaa";

  std::cout << isPermutationMap(s1, s1) << ", " << isPermutationSort(s1, s1) << std::endl;
  std::cout << isPermutationMap(s2, s1) << ", " << isPermutationSort(s2, s1) << std::endl;
  std::cout << isPermutationMap(s2, s4) << ", " << isPermutationSort(s2, s4) << std::endl;
  std::cout << isPermutationMap(s3, s3) << ", " << isPermutationSort(s3, s3) << std::endl;

  return 0;
}

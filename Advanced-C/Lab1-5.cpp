#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string & text, int start, int end) {
  if (start >= end)
    return true;

  if (text[start] != text[end])
    return false;

  return isPalindrome(text, start + 1, end - 1);
}

int main() {
  std::string text;

  std::cout << "Input a string: ";
  std::getline(std::cin, text);

  text.erase(std::remove(text.begin(), text.end(), ' '), text.end());

  bool palindrome = isPalindrome(text, 0, text.length() - 1);

  if (palindrome)
    std::cout << "The string is a palindrome." << std::endl;
  else
    std::cout << "The string is not a palindrome." << std::endl;

  return 0;
}
#include <iostream>
#include <string>

bool isPalindrome(const std::string& str);

int main() {
    std::string palindromeStr = "A man, a plan, a canal, Panama";
    std::string nonPalindromeStr = "Hello, World!";

    if (isPalindrome(palindromeStr)) {
        std::cout << "\"" << palindromeStr << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << palindromeStr << "\" is not a palindrome." << std::endl;
    }

    if (isPalindrome(nonPalindromeStr)) {
        std::cout << "\"" << nonPalindromeStr << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << nonPalindromeStr << "\" is not a palindrome." << std::endl;
    }

    return 0;
}

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
         
        while (left < right && !std::isalnum(str[left])) {
            ++left;
        }
        while (left < right && !std::isalnum(str[right])) {
            --right;
        }

         
        char leftChar = std::tolower(str[left]);
        char rightChar = std::tolower(str[right]);

        if (leftChar != rightChar) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

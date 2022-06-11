//https://leetcode.com/problems/implement-strstr/

#include <iostream>

int strStr(std::string haystack, std::string needle) {
    //iterate through string, find first char that matches needle[0]
    //get substring of curser + needle length, and similar substring from haystack
    //if ==, return cursor, else continue

    if (haystack == needle) {
        return 0;
    }

    for (int i = 0; i < haystack.length(); i++) {
        if (haystack.at(i) == needle.at(0)) {
            std::cout << haystack.substr(i, i + (needle.length() - 2)) << std::endl;
            if (haystack.substr(i, i + (needle.length() - 2)) == needle) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    std::string needle = "aa";
    std::string haystack = "aaa";

    std::cout << strStr(haystack, needle) << std::endl;

    return 0;
}
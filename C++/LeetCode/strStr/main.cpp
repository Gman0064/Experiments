#include <iostream>

int strStr(std::string haystack, std::string needle) {
    int index = -1;

    for (int i = 0; i < haystack.length(); i++) {
        if (haystack[i] == needle[0]) {
            std::string segment = haystack.substr(i, needle.length());
            if (segment == needle) {
                std::cout << segment << std::endl;
                index = i;
                break;
            }
        }
    }

    return index;
}

int main() {
    std::cout << strStr("aaa", "aa") << std::endl;
    return 0;
}
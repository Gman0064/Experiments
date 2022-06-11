#include <iostream>

bool isPalindrome(int x) {
    std::string input = std::to_string(x);
    std::string output;

    char reversed[input.length() + 1];
    int j = 0;
    
    for (int i = input.length() - 1; i >= 0; i--) {
        reversed[i] = input.at(j);
        j++;
    }

    reversed[input.length()] = '\0';

    output = std::string(reversed);

    if (input == output) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int input = 121;

    std::cout << isPalindrome(input) << std::endl;

    return 0;
}
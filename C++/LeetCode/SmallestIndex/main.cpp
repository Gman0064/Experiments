#include <iostream>
#include <vector>

int smallestEqual(std::vector<int>& nums) {
    std::vector<int> m;
    for (int i = 0; i < nums.size(); i++) {
        if ((i % 10) == nums[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::vector<int> input = {4,3,2,6};
    std::cout << smallestEqual(input) << std::endl;
    return 0;
}
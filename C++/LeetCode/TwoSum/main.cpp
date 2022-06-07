#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> output;
    for (int i = 0; i < (nums.size() - 1); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                output.push_back(i);
                output.push_back(j);
            }
        }
    }
    return output;
}

int main() {
    std::vector<int> input = {3,3};
    std::vector<int> output = twoSum(input, 6);

    for (int i = 0; i < output.size(); i++) {
        std::cout << output[i] << " " << std::endl;
    }
}

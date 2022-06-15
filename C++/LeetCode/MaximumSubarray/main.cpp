#include <iostream>
#include <vector>

int maxSubArray(std::vector<int>& nums) {
    int currSum = 0, maxSum = INT16_MIN;

    for (int i=0; i < nums.size(); i++) {
        currSum += nums[i];
        if (currSum > maxSum) {
            maxSum = currSum;
        }

        if (currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}


int main() {
    std::vector<int> input = {-2, 1};
    std::cout << maxSubArray(input) << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] == val) {
            nums[i] = -1;
            for (int j = i; j < (nums.size() - 1); j++) {
                int tmp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = tmp;
            }
            k++;
        }
    }
    return (nums.size() - k);
}

int main() {
    std::vector input = {2};
    std::cout << removeElement(input, 3) << std::endl;
    return 0;
}
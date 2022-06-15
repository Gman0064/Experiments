#include <iostream>
#include <vector>


int bs(std::vector<int>& nums, int start, int end, int target) {
    int i = start + (((end - start) / 2));
    //std::cout << i << std::endl;
    
    if (nums[i] == target) {
        return i;
    }

    if ((nums[i] < target) && (nums[i+1] > target)) {
        return ++i;
    }

    if ((nums[i] < target) && (nums[i+1] > target)) {
        return ++i;
    }

    if ((nums[i] > target) && (nums[i-1] < target)) {
        return i;
    }

    if (nums[i] < target) {
        //right side
        return bs(nums, i+1, end, target);
    }

    // otherwise left side
    return bs(nums, start, i, target);
    
}

int searchInsert(std::vector<int>& nums, int target) {
    if (nums.size() > 0) {
        if (nums.back() < target) {
            return nums.size();
        }

        if (nums.front() > target) {
            return 0;
        }

        return bs(nums, 0, nums.size() - 1, target);
    } else {
        return 0;
    }
}

int main() {
    std::vector<int> input = {1,3,5,6};
    std::cout << searchInsert(input, 0) << std::endl;
    return 0;
}
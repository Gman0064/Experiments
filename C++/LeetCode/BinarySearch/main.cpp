#include <iostream>
#include <vector>

int position;

int bs(std::vector<int>& nums, int start, int end, int target) {
    if (end >= start) {
        int middle = start + (end - start) / 2;

        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] > target) {
            return bs(nums, start, middle - 1, target);
        }

        return bs(nums, middle + 1, end, target);
    } 

    return -1;
}

int main() {
    std::vector<int> my_nums = {-1,0,3,5,9,12};

    std::cout << bs(my_nums, 0, my_nums.size() - 1, 4) << std::endl;
    
    return 0;
}
#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {    
    std::vector<int> result(m + n);
    
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            result[k++] = nums1[i++];
        } else {
            result[k++] = nums2[j++];
        }
    }

    while (i < m) {
        result[k++] = nums1[i++];
    }

    while (j < n) {
        result[k++] = nums2[j++];   
    }

    nums1 = result;
}


int main() {

    std::vector<int> vec1 = {1,2,3,0,0,0};
    std::vector<int> vec2 = {2,5,6};

    merge(vec1, 3, vec2, 3);

    for (int i : vec1) {
        std::cout << i << std::endl;
    }
    
    return 0;
}
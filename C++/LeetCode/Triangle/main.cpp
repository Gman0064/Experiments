#include <iostream>
#include <vector>


// i : Vertical index
// j : Horizontal index
// n : Maximum number of levels
// triangle : Input triangle vector
// memory : Vector of all nodes that have been visited (-1 by default)
int dfs(int i, int j, int n, std::vector<std::vector<int>>& triangle, std::vector<std::vector<int>>& memory) {
    // Check to see if we have reached the last level of the tree
    // return 0 if true
    if (i == n) return 0;

    // Check to see if the value we are currently at has been visited,
    // and return it if true
    if (memory[i][j] != -1) return memory[i][j];

    // Get the sums of the lower left and right nodes from the current position,
    // then compare to see which one is smallest
    int lower_left = triangle[i][j] + dfs(i + 1, j, n, triangle, memory);
    int lower_right = triangle[i][j] + dfs(i + 1, j + 1, n, triangle, memory);
    memory[i][j] = std::min(lower_left, lower_right);

    // return the smallest value at this stage
    return memory[i][j];
}

int main() {

    std::vector<std::vector<int>> input = {{-1},{2,3},{1,-1,-3}};
    //std::vector<std::vector<int>> input = {{2},{3,4},{6,5,7},{4,1,8,3}};

    for (std::vector<int> i : input) {
        for (int j : i) {
            std::cout << j << " " ;
        }

        std::cout << std::endl;
    }

    int n = input.size();
    std::vector<std::vector<int>> memory(n, std::vector<int>(n, -1));
    
    std::cout << dfs(0, 0, n, input, memory) << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool check(int x, int y, int n, int m)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>> &visited, int x, int y, int n, int m)
{
    // Check to see if the target point is within the bounds of the map, is a land,
    // and has not been visited before
    if (!check(x, y, n, m) || grid[x][y] == '0' || visited[x][y] == true)
    {
        return;
    }

    // Otherwise, mark our current position as visited
    visited[x][y] = true;

    // For every adjacent direction, run DFS to see if its a land
    for (std::pair<int, int> p : directions)
    {
        dfs(grid, visited, x + p.first, y + p.second, n, m);
    }
}

int numOfIslands(std::vector<std::vector<char>> &grid)
{
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();

    // Define an initial map of all our positions as false, since we don't
    // know what all is land yet
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    // Iterate through every tile
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // If we've never seen this tile before, and its a land,
            // we explore it to find more lands

            // Since we're checking for continuous land formations, a single
            // DFS search will cover an entire landmass, and will be marked as visited

            // Non-visited members will be considered a new landmass
            if ((visited[i][j] == false) && (grid[i][j] == '1'))
            {
                ans++;
                dfs(grid, visited, i, j, n, m);
            }
        }
    }

    return ans;
}

int main()
{

    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    std::cout << numOfIslands(grid) << std::endl;

    return 0;
}
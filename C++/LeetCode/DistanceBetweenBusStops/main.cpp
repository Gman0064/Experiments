#include <iostream>
#include <vector>

int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination) {
    // int i = start;
    // int length1 = 0;
    // int length2 = 0;
    
    // while ((i % distance.size()) != destination) {
    //     std::cout << distance[i % distance.size()] << std::endl;
    //     length1+= distance[i % distance.size()];
    //     i++;
    // }
    // std::cout << "length1: " << length1 << std::endl;

    // i = start - 1;

    // while ((i % distance.size()) != (destination - 1)) {
    //     std::cout << distance[i % distance.size()] << std::endl;
    //     length2 += distance[i % distance.size()];
    //     i--;
    // }
    // std::cout << "length2: " << length2 << std::endl;

    // return std::min(length1, length2);

    int res = 0;
    int i = start;
    int j = start;
    int n = distance.size();
    int disti = 0, distj = 0;

    while(i != destination || j != destination) {
        if (i != destination) {
            i == 0 ? i = n - 1 : i--;
            disti += distance[i];
        }

        if (j != destination) {
            distj += distance[j];
            j == n - 1 ? j = 0 : j++;
        }
    }

    res = std::min(disti, distj);
    return res;
}

int main() {
    std::vector<int> input = {1,2,3,4};
    std::cout << distanceBetweenBusStops(input, 0, 3) << std::endl;
    return 0;
}
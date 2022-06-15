#include <iostream>

const int VERSION = 8;

bool isBadVersion(int n) {
    if (n > VERSION) {
        return true;
    } else {
        return false;
    }
}


int bs(int start, int end) {
    int mid = start + ((end - start) / 2);
    std::cout << mid << std::endl;
    if(isBadVersion(mid)) {
        if (!isBadVersion(mid-1))
            return mid;
        return bs(0, mid-1);
    } else {
        return bs(mid+1, end);
    }
}


int firstBadVersion(int n) {
    if (!isBadVersion(n-1)) {
        return n;
    }
    else {
        return bs(0, n);
    }
}

int main() {
    std::cout << firstBadVersion(30);
    return 0;
}
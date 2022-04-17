#include <iostream>

int main() {
    int d;
    std::cin >> d;
    int n = 0;
    int s = 0;
    while (s <= 365) {
        s = s + d;
        n = n + 5;
    }
    std::cout << n;
    return 0;
}



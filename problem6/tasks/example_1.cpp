#include <iostream>

int main() {
    int s;
    std::cin >> s;
    int n = 1;
    while (s < 51) {
        s = s + 5;
        n = n * 2;
    }
    std::cout << n;
    return 0;
}



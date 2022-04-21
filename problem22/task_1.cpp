#include <iostream>

// главный метод программы
int main() {
    int x, L, M, Q;
    std::cin >> x;
    Q = 9;
    L = 0;
    while (x >= Q) {
        L = L + 1;
        x = x - Q;
    }
    M = x;
    if (M < L) {
        M = L;
        L = x;
    }
    std::cout << L << std::endl;
    std::cout << M << std::endl;
    return 0;
}



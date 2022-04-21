#include <iostream>

// главный метод программы
int main() {

    int x, L, M, Q;
    for (int i = 1000; i > 0; i--) {
        x = i;
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
        // если значения совпадают
        if (L == 4 && M == 5) {
            // выводим значение счётчика
            std::cout << i;
            break;
        }
    }
    return 0;
}



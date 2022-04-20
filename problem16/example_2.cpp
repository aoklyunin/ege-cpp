#include <iostream>

int cnt = 0;

// функция
void F(int n) {
    cnt++;
    if (n >= 1) {
        cnt++;
        F(n - 1);
        F(n - 2);
        F(n - 3);
    }
}

// главный метод программы
int main() {
    std::cout << cnt << std::endl;
    return 0;
}



#include <iostream>


// функция
int F(int n) {
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return n + 2 + F(n - 1);
    return 2 * F(n - 2);
}


// главный метод программы
int main() {
    std::cout << F(24) << std::endl;
    return 0;
}



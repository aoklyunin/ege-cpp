#include <iostream>

// список перебираемых значений переменной boolean
int booleanValues[] = {0, 1};

// операция импликации(следования)
bool impl(int a, int b) {
    return !a || b;
}

// логическая функция, аргументы которой мы подбираем
bool f(int x, int y, int z) {
    return impl(x, y) && impl(y, z);
}


// главный метод программы
int main() {
    // выводим заголовок
    std::cout << "x y z" << std::endl;
    // перебираем все наборы значений
    for (int xV0: booleanValues)
        for (int yV0: booleanValues)
            for (int zV0: booleanValues)
                // если функция даёт ложь
                if (!f(xV0, yV0, zV0))
                    std::cout << xV0 << " " << yV0 << " " << zV0 << std::endl;
    return 0;
}



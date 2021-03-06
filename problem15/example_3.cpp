#include <iostream>

// операция импликации(следования)
bool impl(int a, int b) {
    return !a || b;
}

// главный метод программы
int main() {
    // перебираем значения A
    for (int N = 1; N < 1000; N++) {
        // кол-во целочисленных переменных x, которые при заданном N
        // дают истинное значение для функции f(x)
        int cnt = 0;
        // перебираем значения x
        for (int x = 1; x < 1000; x++) {
            // если выражение истинно
            if (impl(!(x >= 70 && x <= 90), x >= 40 && x <= 60) && impl(!(x >= 0 && x <= N), x >= 70 && x <= 90)) {
                // увеличиваем кол-во на 1
                cnt++;
            }
        }
        // если при заданном N функция f(x) истинна для более чем 30 целых значений x
        if (cnt > 30) {
            // выводим N
            std::cout << N << std::endl;
            // заканчиваем перебор
            break;
        }
    }
    return 0;
}



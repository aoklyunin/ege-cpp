#include <iostream>

// главный метод программы
int main() {
    // читаем число
    int i;
    std::cin >> i;
    // номер читаемого разряда
    int r = 0;
    // пока есть хотя бы одна цифра в числе
    while (i > 0) {
        // получаем цифру младшего разряда
        int c = i % 10;
        std::cout << r << ": " << c << std::endl;
        // увеличиваем номер текущего разряда
        r++;
        // отбрасываем младший разряд числа
        i /= 10;
    }
    return 0;
}



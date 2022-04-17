#include <iostream>

int main() {
    // перебираем значения переменной s
    for (int i = 0; i < 100000; i++) {
        int s;
        s = i;
        int n = 1;
        while (s < 51) {
            s = s + 5;
            n = n * 2;
        }
        // если ответ совпал
        if (n == 64) {
            // выводим необходимое значение i
            std::cout << i << std::endl;
            // завершаем перебор
            break;
        }
    }
    return 0;
}



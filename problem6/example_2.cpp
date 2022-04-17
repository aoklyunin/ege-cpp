#include <iostream>

int main() {
    // перебираем значения переменной s
    for (int i = 100000; i >=0 ; i--) {
        int d;
        d = i;
        int n = 0;
        int s = 0;
        while (s <= 365) {
            s = s + d;
            n = n + 5;
        }
        // если ответ совпал
        if (n == 55) {
            // выводим необходимое значение i
            std::cout << i << std::endl;
            // завершаем перебор
            break;
        }
    }
    return 0;
}



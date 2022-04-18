#include <iostream>


int main() {
    // создаём строку
    std::string a = "POEZD";
    int i = a.length();
    int k = 2;
    std::string b = "A";
    while (i > 0) {
        // индексация в строках идёт с нуля, а в задании с 1
        char c = a[i-1];
        b = b + c;
        i = i - k;
    }
    b = b + "T";
    // выводим результат
    std::cout << b;
    return 0;
}



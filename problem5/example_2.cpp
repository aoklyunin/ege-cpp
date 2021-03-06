#include <iostream>


// главный метод программы
int main() {
    // читаем число
    int n;
    std::cin >> n;
    // инициализируем переменную цикла
    int i = n;
    // номер читаемого разряда
    int r = 0;
    // пока есть хотя бы одна цифра в числе
    while (i > 0) {
        // увеличиваем номер текущего разряда
        r++;
        // отбрасываем младший разряд числа
        i /= 10;
    }

    // сохраняем кол-во разрядов
    int cnt = r;
    // создаём массив цифр по кол-ву разрядов
    int d[cnt];
    // инициализируем переменную цикла
    i = n;
    // номер читаемого разряда
    r = 0;
    // пока есть хотя бы одна цифра в числе
    while (i > 0) {
        // получаем цифру младшего разряда
        d[r] = i % 10;
        // увеличиваем номер текущего разряда
        r++;
        // отбрасываем младший разряд числа
        i /= 10;
    }

    // Теперь можно работать с цифрами числа, как с массивом
    // для демонстрации эта программа просто выведет их в строчку
    // если идти по массиву от первого элемента к последнему, то
    // число выведется в развёрнутом виде. Ведь нулевой элемент
    // массива соответствует нулевому разряду числа, первый - первому и т.д.
    // поэтому массив следует вывести в обратном порядке
    for (int j = cnt - 1; j >= 0; j--) {
        std::cout << d[j] << " ";
    }
    // перехожим на новую строку
    std::cout << std::endl;

    return 0;
}


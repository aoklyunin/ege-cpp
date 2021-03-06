#include <iostream>


// главный метод программы
int main() {

    // перебираем все четырёхзначные числа
    for (int n = 100; n < 1000; n++) {
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

        // в массиве цифры расположены по разрядам,
        // поэтому элементы для сумм берутся в обратном порядке
        int s12 = d[2] + d[1];
        int s23 = d[1] + d[0];

        int res;
        // формируем число так, чтобы суммы шли в порядке невозрастания
        if (s23 > s12)
            res = s23 * 100 + s12;
        else
            res = s12 * 100 + s23;

        // если результат равен одному из заданных, выведем его
        if (res == 1915 || res == 1815 || res == 188 || res == 1518)
            // перехожим на новую строку
            std::cout << res << std::endl;
    }

    return 0;
}


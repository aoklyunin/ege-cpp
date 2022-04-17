#include <iostream>


// главный метод программы
int main() {

    // перебираем все четырёхзначные числа
    for (int n = 1000; n < 10000; n++) {
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
        int s12 = d[3] + d[2];
        int s23 = d[2] + d[1];
        int s34 = d[1] + d[0];

        // итоговое число
        int res;
        // если сумма первой и второй цифры меньше или равна остальным
        if (s12 <= s23 && s12 <= s34) {
            // формируем число так, чтобы суммы шли в порядке неубывания
            if (s23 < s34)
                res = s23 * 100 + s34;
            else
                res = s34 * 100 + s23;
            // если сумма второй и третьей цифры меньше или равна остальным
        } else if (s23 <= s12 && s23 <= s34) {
            // формируем число так, чтобы суммы шли в порядке неубывания
            if (s12 < s34)
                res = s12 * 100 + s34;
            else
                res = s34 * 100 + s12;
            // если сумма третьей и четвёртой цифры меньше или равна остальным
        } else {
            // формируем число так, чтобы суммы шли в порядке неубывания
            if (s23 < s12)
                res = s23 * 100 + s12;
            else
                res = s12 * 100 + s23;
        }

        // если результат равен 511
        if (res == 511)
            // перехожим на новую строку
            std::cout << n <<std::endl;
    }

    return 0;
}


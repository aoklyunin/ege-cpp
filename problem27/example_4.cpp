#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// главный метод программы
int main() {
    // открываем файл
    std::ifstream myfile;
    // бинарник собирается в отдельной папке, поэтому относительный путь такой
    // можно вместо этого закинуть файл куда-нибудь на диск и указать полный путь
    myfile.open("../problem27/27-3B.txt");

    // читаем кол-во
    int n;
    myfile >> n;
    // число, на которое должна делиться подпоследовательность
    int d = 1111;
    // минимальная длина последовательности
    int m = 100;

    // списки индексов элементов, сумма всех элементов до которого включительно
    // даёт соответствующий остаток. Например: в динамическом списке под индексом
    // 5 будут запоминаться индексы всех элементов, сумма до которых имеет остаток
    // равный 5
    std::vector<std::vector<int>> rs;
    for (int i = 0; i < d; i++) {
        std::vector<int> v;
        rs.push_back(v);
    }

    // сумма всех прочитанных элементов изначально равна 0
    int sum = 0;
    // кол-во подпоследовательностей делящихся на заданное число - тоже
    int cnt = 0;
    // читаем числа
    for (int i = 0; i < n; i++) {
        // Читаем число
        int a;
        myfile >> a;
        // прибавляем его к сумме
        sum += a;
        // если элементов уже больше заданной границы и при этом сумма сама по себе
        // делится на заданное число
        if (i > m && sum % d == 0)
            // увеличиваем кол-во подпоследовательностей на 1
            cnt++;

        // получаем список индексов всех элементов сумма всех чисел до которых
        // имеет соответствующий остаток
        // ОБЯЗАТЕЛЬНО ИСПОЛЬЗУЙТЕ ССЫЛКУ &, иначе будете работать с копией вектора,
        // которая уничтожится в конце итерации
        std::vector<int> & rPoses = rs[sum % d];

        // перебираем индексы всех элементов, сумма до которых имеет
        // такой эже остаток, если мы вычтем суммы всех элементов
        // до прочитанного эту сумму, то это будет сумма подпоследовательности
        // начиная со следующего после сохранённого в динамическом списке
        // индекса. При этом она будет делиться на заданное число
        // поэтому перебираем все индексы элементов, сумма до которых
        // имеет такой же остаток
        for (int rPos: rPoses)
            // если при этом расстояние между положением прочитанного элемента
            // и перебираемым индексом больше заданной длины
            if (i - rPos > m)
                // значит подпоследовательность будет допустимое
                // число элементов и при этом будет делиться на заданное число
                cnt++;

        // добавляем в список индексов номер прочитанного элемента
        rPoses.push_back(i);
    }

    // выводим кол-во последовательностей, делящихся на
    // заданное число
    std::cout << cnt;


    return 0;
}



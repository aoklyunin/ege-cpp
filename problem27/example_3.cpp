#include <iostream>
#include <fstream>
#include <algorithm>

// максимальная подходящая сумма
int maxSum = 0;

// создаём массив для подсчёта подмножеств, сумма которых имеет тот
// или иной остаток от деления на 12
int d[6][6];

// функция для рекуррентного заполнения массива последовательностями
// остатков, если при этом все их вычесть из исходной суммы и результат
// будет делиться на 6, тогда по массиву остатков возьмём
// столько первых разниц, сколько соответствующих остатков задействовано
void process(int pos, int *arr, int fsum) {
    // если массив остатков полностью заполнен
    if (pos == 6) {
        // вычитаем из исходной суммы остатки
        int subs = fsum;
        for (int j = 0; j < 6; j++) {
            subs -= arr[j];
        }
        // если разность делится на 6
        if (subs % 6 == 0) {
            // номера разностей, которые мы ещё не использовали,
            // пока что все равны 0,
            int dPs[6];
            std::fill(std::begin(dPs), std::begin(dPs) + 6, 0);
            // перебираем массив остатков
            for (int i = 0; i < 6; i++) {
                // если задействованный остаток равен ноль или
                // мы не встретили достаточное кол-во разниц заданного остатка
                // и они все кончились
                if (arr[i] == 0 || d[arr[i]][dPs[i]] == 10000000)
                    // заканчиваем выполнение функции
                    return;
                // вычитаем из исходной суммы соответствующую разницу
                fsum -= d[arr[i]][dPs[i]];
                // говорим, что из массива разниц мы взяли ещё одну
                dPs[i]++;
            }
            // если новая подходящая сумма больше максимальной
            if (fsum > maxSum)
                // сохраняем новую сумму в качестве максимальной
                maxSum = fsum;

        }
    } else
        // на место pos в массиве остатков ставим по очереди все остатки
        for (int i = 0; i < 6; i++) {
            // для конкретного варианта ставим на меcто pos остаток, равный i
            arr[pos] = i;
            // запускаем рекурсию для следующего положения
            process(pos + 1, arr, fsum);
        }
}

// главный метод программы
int main() {
    // открываем файл
    std::ifstream myfile;
    // бинарник собирается в отдельной папке, поэтому относительный путь такой
    // можно вместо этого закинуть файл куда-нибудь на диск и указать полный путь
    myfile.open("../problem27/27-2b.txt");

    // читаем кол-во
    int n;
    myfile >> n;
    // создаём массив для подсчёта остатков
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            d[i][j] = 10000000;
        }
    }

    // изначально сумма чисел равна 0
    int sum = 0;

    // читаем сами числа
    for (int i = 0; i < n; i++) {
        int a;
        myfile >> a;
        int b;
        myfile >> b;
        int delta = std::abs(a - b);
        int r = delta % 6;

        int pos = 0;
        while (pos < 6 && d[r][pos] <= delta)
            pos++;
        if (pos < 6)
            d[r][pos] = delta;
        sum += std::max(a, b);
    }

    // если сумма уже делится на 6
    if (sum % 6 == 0) {
        // выводим её
        std::cout << sum << std::endl;
        // завершаем работу программы
        return 0;
    }

    // запускаем перебор остатков
    int init[] = {0, 0, 0, 0, 0, 0};
    process(0, init, sum);
    // выводим максимальную сумму
    std::cout << maxSum << std::endl;

    return 0;
}



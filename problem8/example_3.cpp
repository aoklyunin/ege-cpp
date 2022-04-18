#include <iostream>
#include <bits/stdc++.h>

// множество значений
std::set<std::string> values;

// обработка перестановки
void processPermutation(std::vector<char> arr) {
    // переменная, которая отвечает на вопрос, подходит ли нам текущая комбинация
    // изначально кладём в неё ответ, правда ли, что первый символ - не 'Ь'
    bool f = arr[0] != '.';
    // строка с кодом
    std::string s;
    for (int i = 0; i < arr.size() - 1; i++) {
        // если текущий символ - 'Ь', а следующий - гласная
        if (arr[i] == '.' && (arr[i + 1] == 'A' || arr[i + 1] == 'U'))
            // тогда комбинация нам не подходит
            f = false;
        // прибавляем текущий символ к строке
        s += arr[i];
    }
    // добавляем последний символ к строке
    s += arr[arr.size() - 1];
    // если повторяющихся символов в строке нет
    if (f) {
        // добавляем её в множество
        values.insert(s);
    }
}


// главный метод программы
int main() {
    std::vector<char> origin = {'V', 'U', 'A', 'L', '.'};
    // ОБЯЗАТЕЛЬНО ОТСОРТИРУЙТЕ ВЕКТОР! иначе перестановки
    // будут работать неправильно
    std::sort(origin.begin(), origin.end());
    // перебираем перестановки
    do {
        processPermutation(origin);
    } while (std::next_permutation(origin.begin(), origin.end()));
    // выводим размер множества
    std::cout << values.size() << std::endl;

    return 0;
}



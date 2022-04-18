#include <iostream>
#include <bits/stdc++.h>

// множество значений
std::set<std::string> values;

// обработка перестановки
void processPermutation(std::vector<char> arr) {
    // кол-во повторяющихся символов
    int c = 0;
    // строка с кодом
    std::string s;
    for (int i = 0; i < arr.size() - 1; i++) {
        // если текущий символ равен предыдущему
        if (arr[i] == arr[i + 1])
            // увеличиваем кол-во повторяющихся функций
            c++;
        // прибавляем текущий символ к строке
        s += arr[i];
    }
    // добавляем последний символ к строке
    s += arr[arr.size() - 1];
    // если повторяющихся символов в строке нет
    if (c == 0) {
        // добавляем её в множество
        values.insert(s);
    }
}


// главный метод программы
int main() {
    std::vector<char> origin = {'K', 'A', 'P', 'K', 'A', 'N'};
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



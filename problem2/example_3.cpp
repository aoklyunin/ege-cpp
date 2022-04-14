#include <iostream>
#include <vector>
#include <algorithm>

// имена колонок
char names[] = {'x', 'y', 'z', 'w'};
// список перебираемых значений переменной boolean
int booleanValues[]{0, 1};

// операция импликации(следования)
int impl(int a, int b) {
    return !a || b;
}

// логическая функция, аргументы которой мы подбираем
int f(int x, int y, int z, int w) {
    return ((x && !y) || impl(w, z)) == (z == x);
}

// проверка значений в линии на совпадение
int findLine(int xV, int yV, int zV, int wV, int f, std::vector<std::vector<int>> combinations) {
    if (!yV && !zV && wV&& f && combinations[0].empty()) {
        return 0;
    }
    // обязательно надо сначала проверить эту строку, потому что она
    if (!xV && yV && !zV && !wV  && f && combinations[1].empty()) {
        return 1;
    }
    if (!xV && wV && f && combinations[2].empty()) {
        return 2;
    }
    return -1;
}

// обработка перестановки
static void processPermutation(std::vector<int> p) {
    // найденные комбинации, их может быть максимум 16, потому что перменных 4, а 2^4=16
    std::vector<std::vector<int>> combinations;
    combinations.reserve(3);
    for (int i = 0; i < 3; i++)
        combinations.emplace_back();

    // кол-во найденных комбинаций
    int foundCombinationCnt = 0;
    // перебираем все варианты значений для каждой логической переменной
    // из таблицы истинности, значений всего два: true и false
    for (int xV0: booleanValues)
        for (int yV0: booleanValues)
            for (int zV0: booleanValues)
                for (int wV0: booleanValues) {
                    // чтобы использовать перестановку, построим на основе четырёх логических
                    // переменных массив
                    int values[] = {xV0, yV0, zV0, wV0};

                    // получим значения логических переменных с учётом перестановки
                    // т.е. мы по сути формируем строку значений, которую потом будем сверять с данной
                    int xV = values[p[0]];
                    int yV = values[p[1]];
                    int zV = values[p[2]];
                    int wV = values[p[3]];
                    // ищем подходящую строку таблицы
                    int lineNum = findLine(xV, yV, zV, wV, f(xV0, yV0, zV0, wV0), combinations);
                    // если строка найдена и ещё не сохранена соответствующая этой строке комбинация
                    if (lineNum != -1) {
                        // сохраняем комбинацию
                        combinations[lineNum].assign(values, values + 4);
                        foundCombinationCnt++;
                    }
                }
    // если найдено три комбинации
    if (foundCombinationCnt == 3) {
        std::cout << "++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "permutation: ";
        for (int i = 0; i < 4; i++)
            std::cout << p[i] << " ";
        std::cout << std::endl;
        // выводим шапку
        for (int i = 0; i < 4; i++) {
            std::cout << names[p[i]] << " ";
        }
        std::cout << std::endl;
        // выводим сохранённые комбинации
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                std::cout << combinations[i][p[j]] << " ";
            }
            std::cout << std::endl;
        }
    }
}


// главный метод программы
int main() {
    std::vector<int> origin = {0, 1, 2, 3};
    do {
        processPermutation(origin);
    } while (std::next_permutation(origin.begin(), origin.end()));
    return 0;
}



#include <iostream>
#include <bits/stdc++.h>

// кол-во вершин (используется для удобства)
const int SIZE = 7;

//      П1  П2  П3  П4  П5  П6  П7
const int source[SIZE][SIZE] = {
        {0, 45, 0, 10, 0, 0, 0}, // П1
        {45, 0, 0, 40, 0, 55, 0}, // П2
        {0, 0, 0, 0,15, 60, 0}, // П3
        {10, 40, 0, 0, 0, 20, 35}, // П4
        {0, 0, 15, 0, 0, 55, 0}, // П5
        {0, 55, 60, 20, 55, 0, 45}, // П6
        {0, 0, 0, 35, 0, 45, 0}  // П7
};

//       А  Б  В  Г  Д  Е  Ж
const int target[SIZE][SIZE] = {
        {0, 1, 1, 0, 0, 0, 0}, // A
        {1, 0, 1, 0, 0, 0, 0}, // Б
        {1, 1, 0, 1, 1, 1, 0}, // В
        {0, 0, 1, 0, 0, 1, 1}, // Г
        {0, 0, 1, 0, 0, 1, 0}, // Д
        {0, 0, 1, 1, 1, 0, 1}, // Е
        {0, 0, 0, 1, 0, 1, 0}  // К
};


// степени вершин
int sourceSum[SIZE];
int targetSum[SIZE];

// получить обратную перестановку
int *getReversePermutation(std::vector<int> arr) {
    static int reverse[SIZE];
    for (int i = 0; i < SIZE; i++) {
        reverse[arr[i]] = i;
    }
    return reverse;
}

// обработка перестановки
void processPermutation(std::vector<int> arr) {
    // проверяем, что в представлениях совпадают степени вершин
    for (int i = 0; i < SIZE; i++) {
        if (sourceSum[arr[i]] != targetSum[i]) {
            return;
        }
    }

    // нужна проверка связности, т.е. того, что при перестановке все связи сохраняются, те не
    // обратятся в ноль
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // если в эталонном представлении связь между вершинами есть,
            // а в данном в задании - нет
            if (target[i][j] > 0 && source[arr[i]][arr[j]] == 0)
                // заканчиваем выполнение обработчика, потому такая перестановка
                // создаёт представление, не совместимое с данным, а значит, нас не
                // интересует
                return;
        }
    }
    // здесь мы уже выполняем проверку, определённую заданием


    // получаем обратную перестановку
    int *reverse = getReversePermutation(arr);
    // названия вершин
    const std::string names[SIZE] = {"A", "B", "C", "D", "E", "F", "G"};
    // выводим названия вершин
    for (int i = 0; i < SIZE; i++) {
        std::cout << names[reverse[i]] << " ";
    }
    std::cout << std::endl;
    // выводим расстояния
    int veDistance = source[arr[2]][arr[5]];
    std::cout << veDistance << std::endl;

}


// главный метод программы
int main() {
    // рассчитываем взвешенные степени
    for (int i = 0; i < SIZE; i++) {
        sourceSum[i] = 0;
        targetSum[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            // в исходном представлении надо не забыть заменить ненулевые веса единицей
            sourceSum[i] += source[i][j] > 0 ? 1 : 0;
            targetSum[i] += target[i][j];
        }
    }

    std::vector<int> origin = {0, 1, 2, 3, 4, 5, 6};
    do {
        processPermutation(origin);
    } while (std::next_permutation(origin.begin(), origin.end()));

    return 0;
}



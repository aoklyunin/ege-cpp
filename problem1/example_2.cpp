#include <iostream>
#include <bits/stdc++.h>

// кол-во вершин (используется для удобства)
const int SIZE = 7;

//      П1  П2  П3  П4  П5  П6  П7
const int source[SIZE][SIZE] = {
        {0, 11, 7, 5, 0, 0, 12}, // П1
        {11, 0, 0, 0, 13, 8, 14}, // П2
        {7, 0, 0, 15, 0, 10, 0}, // П3
        {5, 0, 15, 0, 0, 9, 0}, // П4
        {0, 13, 0, 0, 0, 6, 0}, // П5
        {0, 8, 10, 9, 6, 0, 0}, // П6
        {12, 14, 0, 0, 0, 0, 0}  // П7
};

//       А  Б  В  Г  Д  Е  Ж
const int target[SIZE][SIZE] = {
        {0, 1, 0, 1, 0, 0, 0}, // A
        {1, 0, 1, 1, 0, 1, 0}, // Б
        {0, 1, 0, 0, 0, 1, 0}, // В
        {1, 1, 0, 0, 1, 0, 1}, // Г
        {0, 0, 0, 1, 0, 1, 1}, // Д
        {0, 1, 1, 0, 1, 0, 1}, // Е
        {0, 0, 0, 1, 1, 1, 0}  // Ж
};

// степени вершин
int sourceSum[SIZE];
int targetSum[SIZE];

// названия вершин
const std::string names[SIZE] = {"A", "B", "C", "D", "E", "F", "G"};


// получить обратную перестановку
int *getReversePermutation(std::vector<int> arr) {
    static int reverse[SIZE];
    for (int i = 0; i < SIZE; i++) {
        reverse[arr[i]] = i;
    }
    return reverse;
}

// поиск кратчайшего пути
int findMinDistance(int start, int end, std::vector<int> arr) {
    // заполняем расстояния от начальной вершины до рассматриваемой значениями -1
    int distances[SIZE];
    std::fill(std::begin(distances),std::begin(distances)+SIZE,-1);
    // упорядоченное множество, в котором будут лежать индексы вершин графа, которые
    // начинаем с точки Б, поэтому индекс 1
    int currentPoint = start;
    // расстояние от точки до самой себя равно нулю
    distances[currentPoint] = 0;
    // массив флагов, закончена ли проверка для заданной точки, изначально все элементы false
    bool complete[SIZE];
    std::fill(std::begin(complete),std::begin(complete)+SIZE, false);
    // пока есть следующая точка
    while (currentPoint != -1) {
        // выводим расстояния
//        std::cout<<"current: " << currentPoint <<" " << names[currentPoint]<<std::endl;
//        for (int i = 0; i < SIZE; ++i) {
//            std::cout<<distances[i]<<" ";
//        }
//        std::cout <<std::endl;

        // перебираем все вершины
        for (int i = 0; i < SIZE; i++) {
            if (i == currentPoint || complete[i])
                continue;
            // если у текущей есть с ней ребро
            if (source[arr[currentPoint]][arr[i]] > 0) {
                // если мы не обрабатывали вершину или новое расстояние через рассматриваемую вершину выше
                if (distances[i] == -1 || distances[i] > distances[currentPoint] + source[arr[currentPoint]][arr[i]]) {
                    // рассчитываем новое расстояние, как сумму длины пути до текущей вершины
                    // и ребра от текущей вершины до заданной
                    distances[i] = distances[currentPoint] + source[arr[currentPoint]][arr[i]];
                }
            }
        }
        complete[currentPoint] = true;
        // ищем следующую точку
        int nextPoint = -1;
        for (int i = 0; i < SIZE; i++) {
            // если обработка точки не завершена
            if (!complete[i])
                // если мы уже доходили до точки и следующая точка ещё не задана или
                // новое расстояние меньше
                if (distances[i] > 0 && (nextPoint == -1 || distances[i] < distances[nextPoint]))
                    nextPoint = i;

        }
        // переходим к следующей точке
        currentPoint = nextPoint;
    }

    return distances[end];
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

    // находим расстояние между вершинами
    int minAGDistance = findMinDistance(0, 6, arr);
    // если расстояние ГД меньше ГЕ, то комбинация нам подходит
    if (minAGDistance <= 15) {
        // получаем обратную перестановку
        int *reverse = getReversePermutation(arr);
        // выводим названия вершин
        for (int i = 0; i < SIZE; i++) {
            std::cout << names[reverse[i]] << " ";
        }
        std::cout << std::endl;
        // выводим расстояния
        std::cout << findMinDistance(4, 2, arr) << std::endl;
    }

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
    } while(std::next_permutation(origin.begin(), origin.end()));

    return 0;
}



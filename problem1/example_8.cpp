#include <algorithm>
#include <bits/stdc++.h>

// кол-во вершин (используется для удобства)
const int SIZE = 7;

//      П1  П2  П3  П4  П5  П6  П7
const int m[SIZE][SIZE] = {
        {0, 5, 0, 12, 0, 0, 25}, // A
        {5, 0, 0, 8, 0, 0, 0}, // B
        {0, 0, 0, 2, 4, 5, 10}, // C
        {12, 8, 2, 0, 0, 0, 0}, // D
        {0, 0, 4, 0, 0, 0, 5}, // E
        {0, 0, 5, 0, 0, 0, 5}, // F
        {25, 0, 10, 0, 5, 5, 0}, // G
};


int findMinDistance(int start, int end) {
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
            if (m[currentPoint][i] > 0) {
                // если мы не обрабатывали вершину или новое расстояние через рассматриваемую вершину выше
                if (distances[i] == -1 || distances[i] > distances[currentPoint] + m[currentPoint][i]) {
                    // рассчитываем новое расстояние, как сумму длины пути до текущей вершины
                    // и ребра от текущей вершины до заданной
                    distances[i] = distances[currentPoint] + m[currentPoint][i];
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

// главный метод программы
int main() {
    // выводим ответ
    std::cout << findMinDistance(0,6);
}
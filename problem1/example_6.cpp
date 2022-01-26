#include <iostream>

// кол-во вершин графа
static const int  SIZE= 6;
//       A  B  C  D  E  F

int m[SIZE][SIZE] = {
        {0,  2, 4, 8, 0, 16}, // A
        {2,  0, 0, 3, 0, 0}, // B
        {4,  0, 0, 3, 0, 0}, // C
        {8,  3, 3, 0, 5, 3}, // D
        {0,  0, 0, 5, 0, 5}, // E
        {16, 0, 0, 3, 5, 0}, // F
};

int findMinDistance(int start, int end, int skipPoint) {
    // заполняем расстояния от начальной вершины до рассматриваемой значениями -1
    int distances[SIZE];
    std::fill(std::begin(distances),std::begin(distances)+SIZE,-1);
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
            if (i == currentPoint || i == skipPoint || complete[i])
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
                if (distances[i] > 0 && (nextPoint == -1 || distances[i] < distances[nextPoint])) {
                    nextPoint = i;
                }

        }
        // переходим к следующей точке
        currentPoint = nextPoint;

        //    System.out.println("set cp: " + currentPoint);
    }
    return distances[end];
}


// главный метод программы
int main() {
    int part1 = findMinDistance(0, 4, 1);
    int part2 = findMinDistance(4, 5, 1);
    std::cout << part1 + part2;
}

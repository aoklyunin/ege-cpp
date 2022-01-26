#include <iostream>

// главный метод программы
int main() {
    // кол-во вершин графа
    static const int SIZE = 8;
    //       А  Б  В  Г  Д  Е  Ж  З
    int m[SIZE][SIZE] = {
            {0, 5, 0, 2, 4, 0, 0, 0}, // А
            {0, 0, 0, 5, 0, 0, 7, 2}, // Б
            {0, 0, 0, 0, 0, 0, 0, 8}, // В
            {0, 0, 0, 0, 0, 0, 1, 0}, // Г
            {0, 0, 3, 0, 0, 0, 0, 0}, // Д
            {0, 0, 0, 0, 0, 0, 2, 0}, // Е
            {0, 0, 0, 0, 0, 0, 0, 0}, // Ж
            {0, 0, 0, 0, 0, 4, 0, 0}, // З
    };
    // названия вершин
    char names[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    // заполняем расстояния от начальной вершины до рассматриваемой значениями -1
    int distances[SIZE];
    std::fill(std::begin(distances),std::begin(distances)+SIZE,-1);
    // массив флагов, закончена ли проверка для заданной точки, изначально все элементы false
    bool complete[SIZE];
    std::fill(std::begin(complete),std::begin(complete)+SIZE, false);
    // начинаем с точки Б, поэтому индекс 1
    int currentPoint = 1;
    // расстояние от точки до самой себя равно нулю
    distances[currentPoint] = 0;
    // пока есть следующая точка
    while (currentPoint != -1) {
        // выводим расстояния
        std::cout<<"current: " << currentPoint <<" " << names[currentPoint]<<std::endl;
        for (int i = 0; i < SIZE; ++i) {
            std::cout<<distances[i]<<" ";
        }
        std::cout <<std::endl;

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
                if (distances[i] > 0 && (nextPoint == -1 || distances[i] < distances[nextPoint])) {
                    nextPoint = i;
                }

        }
        // переходим к следующей точке
        currentPoint = nextPoint;

        //    System.out.println("set cp: " + currentPoint);
    }

    // выводим расстояния
    std::cout<<"current: " << currentPoint <<" " << names[currentPoint]<<std::endl;
    for (int distance : distances) {
        std::cout<<distance<<" ";
    }
    std::cout <<std::endl;

    // Выводим расстояние от Б до Ж
    std::cout << distances[6];
    return 0;
}

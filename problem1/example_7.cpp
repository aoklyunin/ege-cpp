#include <string>
#include <iostream>
#include <bits/stdc++.h>


// кол-во вершин графа
const int SIZE = 7;// названия вершин

const std::string names[SIZE] = {"A", "B", "C", "D", "E", "F", "Z"};

//       A  B  C  D  E  F  Z
int m[SIZE][SIZE] = {
        {0,  4, 6, 0,  0, 0, 30}, // A
        {0,  0, 3, 0,  0, 0, 0}, // B
        {0,  0, 0, 11, 0, 0, 27}, // C
        {0,  0, 0, 0,  4, 7, 10}, // D
        {0,  0, 0, 0,  0, 4, 8}, // E
        {0,  0, 0, 0,  5, 0, 2}, // F
        {29, 0, 0, 0,  0, 0, 0}, // Z
};

// кол-во путей
int pathCnt = 0;


// сгенерировать пути
static void generatePaths(int currentPoint, int target, const int inPathPositions[], int stepCnt) {
    // если мы дошли до целевой вершины
    if (currentPoint == target) {
        // шагов всегда меньше на 1, чем вершин в пути, поэтому сравниваем
        // пятью вместо шести
        if (stepCnt >= 5) {
            // инициализируем массив порядковых номеров вершин
            int pointOrder[SIZE];
            std::fill(std::begin(pointOrder), std::begin(pointOrder) + SIZE, -1);
            // перебираем вершины
            for (int i = 0; i < SIZE; i++) {
                // если порядковый номер вершины в пути задан
                if (inPathPositions[i] != -1)
                    // порядковый номер вершины
                    pointOrder[inPathPositions[i]] = i;
            }
            // находим, сколько вершин мы использовали при построении пути
            int realSize = SIZE;
            for (int i = SIZE - 1; i > 0; i--) {
                if (pointOrder[i] != -1) {
                    realSize = i + 1;
                    break;
                }
            }

            // находим длину пути
            int pathLength = 0;
            for (int i = 0; i < realSize - 1; i++) {
                pathLength += m[pointOrder[i]][pointOrder[i + 1]];
            }
            std::cout << pathLength << " ";
            // выводим вершины, которые участвую в пути в порядке следования
            for (int i = 0; i < realSize; i++) {
                std::cout << names[pointOrder[i]];
            }
            std::cout << std::endl;
            // увеличиваем кол-во путей на 1
            pathCnt++;
        }
    } else { // иначе
        // перебираем все вершины
        for (int i = 0; i < SIZE; i++) {
            // если порядковый номер вершины в пути ещё не задан
            // и между обрабатываемой вершиной и перебираемой есть ребро
            if (inPathPositions[i] == -1 && m[currentPoint][i] > 0) {
                int copyInPathPositions[SIZE];
                for (int j = 0; j < SIZE; j++) {
                    copyInPathPositions[j] = inPathPositions[j];
                }
                // задаём порядковый номер для перебираемой вершины
                copyInPathPositions[i] = stepCnt + 1;
                // генерируем путь через эту вершину
                generatePaths(i, target, copyInPathPositions, stepCnt + 1);
            }
        }
    }
}


// главный метод программы
int main() {
    // положение вершин в пути
    int inPathPositions[SIZE];
    std::fill(std::begin(inPathPositions), std::begin(inPathPositions) + SIZE, -1);
    // начальная точка A
    int start = 0;
    // конечная точка Z
    int target = 6;
    // текущая точка имеет нулевой порядковый индекс
    inPathPositions[start] = 0;
    // ищем все пути между двумя точками
    generatePaths(start, target, inPathPositions, 0);
    // выводим ответ
    std::cout << "path cnt: " << pathCnt;
}
#include <iostream>

// кол-во вершин (используется для удобства)
const int SIZE = 7;

//      П1  П2  П3  П4  П5  П6  П7
const int source[SIZE][SIZE] = {
        {0,  10, 15, 0,  0,  0,  0}, // П1
        {10, 0,  0,  13, 17, 0,  0}, // П2
        {15, 0,  0,  0,  19, 0,  9}, // П3
        {0,  14, 0,  0,  10, 20, 11}, // П4
        {0,  17, 19, 10, 0,  0,  20}, // П5
        {0,  0,  0,  20, 0,  0,  25}, // П6
        {0,  0,  9,  11, 20, 25, 0}  // П7
};

//       А  Б  В  Г  Д  Е  Ж
const int target[SIZE][SIZE] = {
        {0, 1, 1, 0, 0, 0, 0}, // A
        {1, 0, 0, 1, 1, 0, 0}, // Б
        {1, 0, 0, 1, 0, 1, 0}, // В
        {0, 1, 1, 0, 1, 1, 0}, // Г
        {0, 1, 0, 1, 0, 1, 1}, // Д
        {0, 0, 1, 1, 1, 0, 1}, // Е
        {0, 0, 0, 0, 1, 1, 0}  // Ж
};

// степени вершин
int sourceSum[SIZE];
int targetSum[SIZE];

// получить обратную перестановку
int *getReversePermutation(const int arr[]) {
    static int reverse[SIZE];
    for (int i = 0; i < SIZE; i++) {
        reverse[arr[i]] = i;
    }
    return reverse;
}


// обработка перестановки
void processPermutation(const int arr[]) {
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

    // расстояние между Г и Д
    int gdDistance = source[arr[3]][arr[4]];
    // расстояние между Г и Е
    int geDistance = source[arr[3]][arr[5]];
    // расстояние между А и Б
    int abDistance = source[arr[0]][arr[1]];
    // если расстояние ГД меньше ГЕ, то комбинация нам подходит
    if (gdDistance < geDistance) {
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
        std::cout << abDistance << " " << gdDistance << " " << geDistance;
    }

}

// функция-генератор перестановок
void permute(int p[], int pos) {
    // Если мы дошли до последнего элемента
    if (pos == SIZE - 1) {
        processPermutation(p);
    } else { // иначе
        // Перебираем все оставшиеся элементы
        for (int i = pos; i < SIZE; i++) {
            // меняем местами текущий элемент и перебираемый
            std::swap(p[pos], p[i]);
            // Вызываем Рекурсию для следующего элемента
            permute(p, pos + 1);
            // меняем местами обратно
            std::swap(p[pos], p[i]);
        }
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
    // запускаем генерацию перестановок
    permute(new int[7]{0, 1, 2, 3, 4, 5, 6}, 0);

    return 0;
}



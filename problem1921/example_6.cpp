#include <iostream>


// декларируем метод хода второго игрока
bool player2(int s, int step);

// декларируем метод хода второго игрока
bool checkPlayer2(int s, int step);


// ход Пети, результат отвечает на вопрос, выполняется ли первое
// требование задачи,
// s - кол-во камней в куче, step - номер хода
bool player1(int s, int step) {
    // если это первый ход Пети, тогда Ваня пока что
    // не сделал ни одного хода
    if (step == 1) {
        // При любом ходе Пети Ваня должен победить,
        // поэтому используем И
        return player2(s + 1, step) &&
               player2(s + 4, step) &&
               player2(s * 2, step);

    } else if (step == 2) { // если это второй ход Пети, т.е. Ваня сделал уже один ход
        // если Ваня при этом победил,
        if (s >= 52)
            // требование задачи выполнено
            return true;

        // При любом ходе Пети Ваня должен победить,
        // поэтому используем И
        return player2(s + 1, step) &&
               player2(s + 4, step) &&
               player2(s * 2, step);
    } else { // если это третий ход Пети, т.е. Ваня сделал уже два хода
        // если Ваня при этом победил, то требование задачи не выполнено
        return s >= 52;
    }
}

// ход Вани, результат отвечает на вопрос, выполняется ли первое
// требование задачи,
// s - кол-во камней в куче, step - номер хода
bool player2(int s, int step) {
    // обработка состояния игры после хода Пети
    // если Петя сделал первый ход
    if (step == 1) {
        // если он при этом победил,
        if (s >= 52)
            // требование задачи не выполнено
            return false;

        // разные ходы Вани
        // у Вани есть стратегия, которая позволит ему гарантированно выиграть первым ходом
        // или вторым ходом, т.е. есть хотя бы один ход, ведущий к победе,
        return player1(s + 1, step + 1) ||
               player1(s + 4, step + 1) ||
               player1(s * 2, step + 1);
    } else { // если Петя сделал второй ход
        // если он при этом победил,
        if (s >= 52)
            // требование задачи не выполнено
            return false;

        // у Вани есть стратегия, которая позволит ему гарантированно выиграть первым ходом
        // или вторым ходом, т.е. есть хотя бы один ход, ведущий к победе,
        return player1(s + 1, step + 1) ||
               player1(s + 4, step + 1) ||
               player1(s * 2, step + 1);
    }
}


// ход Пети, результат отвечает на вопрос, выполняется ли второе
// требование задачи,
// s - кол-во камней в куче, step - номер хода
bool checkPlayer1(int s, int step) {
    if (step == 1) {
        // При любом ходе Пети Ваня не должен гарантированно победить,
        // поэтому отрицаем выражение и используем И
        return !(checkPlayer2(s + 1, step) &&
                 checkPlayer2(s + 4, step) &&
                 checkPlayer2(s * 2, step));
    } else { // если это второй ход Пети, т.е. Ваня сделал уже один ход
        // если он при этом победил, возвращаем, что условие выполнено
        return s >= 52;
    }
}

// ход Вани, результат отвечает на вопрос, выполняется ли второе
// требование задачи
// s - кол-во камней в куче, step - номер хода
bool checkPlayer2(int s, int step) {
    // При любом ходе Пети Ваня должен победить,
    // поэтому используем И
    return checkPlayer1(s + 1, step + 1) ||
           checkPlayer1(s + 4, step + 1) ||
           checkPlayer1(s * 2, step + 1);
}


// главный метод программы
int main() {
    // перебираем кол-во камней в куче
    for (int s = 1; s < 69; s++) {
        // запускаем обработку первого шага Пети, если
        // нас устраивает результат,
        if (player1(s, 1) && checkPlayer1(s, 1)) {
            // выводим кол-во камней во второй куче
            std::cout << s << std::endl;
            // завершаем цикл
            break;
        }
    }
    return 0;
}



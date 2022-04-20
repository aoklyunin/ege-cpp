#include <iostream>
#include <vector>
#include <algorithm>

// основание системы счисления
const int BASE = 7;

// после операций сложения и вычетания в начале вектора может появиться несколько
// нулей, этот метод удаляет их
std::vector<int> removeBeginZeros(std::vector<int> v) {
    while (v[0] == 0) {
        v.erase(v.begin());
    }
    return v;
}

// сумма длинных чисел
std::vector<int> plus(std::vector<int> a, std::vector<int> b) {
    // ответ
    std::vector<int> res;
    // выделяем сразу память под результат
    res.reserve(std::max(a.size(), b.size()));
    // если первый вектор длиннее второго
    if (a.size() > b.size())
        // добавляем в начале второго вектора нули
        for (int i = 0; a.size() - b.size(); i++)
            b.insert(b.begin(), 0);
    else
        // добавляем в начале первого вектора нули
        for (int i = 0; b.size() - a.size(); i++)
            a.insert(a.begin(), 0);
    // перенос
    int add = 0;
    // перебираем разряды чисел
    for (int i = 0; i < a.size(); i++) {
        // разряды числа идут в обратном порядке
        int sum = a[a.size() - 1 - i] + b[b.size() - 1 - i] + add;
        // если поразрядная сумма больше основания
        if (sum >= BASE) {
            // вычитаем основание из суммы
            sum -= BASE;
            // перенос равен 1
            add = 1;
        } else
            // переноса нет
            add = 0;
        // добавляем сумму в вектор
        res.push_back(sum);
    }
    // если после суммы перенос больше нуля
    if (add > 0)
        // добавляем его в вектор
        res.push_back(add);
    // сформированный вектор создан развёрнутым,
    // чтобы разряды шли в том же порядке, что и в числе,
    // необходимо развернуть вектор
    std::reverse(res.begin(), res.end());
    // убираем нули в начале вектора-результата
    return removeBeginZeros(res);
}

// вычетание длинных чисел(предполагается, что первый вектор больше второго,
// т.е. результат всегда положительный
std::vector<int> minus(std::vector<int> a, std::vector<int> b) {
    // ответ
    std::vector<int> res;
    // выделяем сразу память под результат
    res.reserve(std::max(a.size(), b.size()));
    // если первый вектор длиннее второго
    if (a.size() > b.size())
        // добавляем в начале второго вектора нули
        for (int i = 0; a.size() - b.size(); i++)
            b.insert(b.begin(), 0);
    else
        // добавляем в начале первого вектора нули
        for (int i = 0; b.size() - a.size(); i++)
            a.insert(a.begin(), 0);
    // перенос
    int add = 0;
    // перебираем разряды чисел
    for (int i = 0; i < a.size(); i++) {
        // разряды числа идут в обратном порядке
        int sub = a[a.size() - 1 - i] - b[b.size() - 1 - i] + add;
        // если поразрядная разность меньше нуля
        if (sub < 0) {
            // к разности добавляем основание
            sub += BASE;
            // перенос равен -1
            add = -1;
        } else
            // переноса нет
            add = 0;
        // добавляем разность в вектор
        res.push_back(sub);
    }
    // сформированный вектор создан развёрнутым,
    // чтобы разряды шли в том же порядке, что и в числе,
    // необходимо развернуть вектор
    std::reverse(res.begin(), res.end());
    // убираем нули в начале вектора-результата
    return removeBeginZeros(res);
}

// получение числа, равного овнованию в заданной степени
std::vector<int> pow(int p) {
    std::vector<int> vec;
    // изначально число равно 1
    vec.push_back(1);
    // домножаме его на основание p раз, добавляя ноль в конец dtrnjhf
    for (int i = 0; i < p; i++) {
        vec.push_back(0);
    }
    return vec;
}

// перевод произвольного числа в длинное с заданным основанием
std::vector<int> valueOf(int a) {
    // результат
    std::vector<int> res;
    // пока в числе есть цифры в семеричном представлении
    while (a > 0) {
        // добавляем в вектор последнюю цифру в семеричном представлении
        res.push_back(a % BASE);
        // отбрасываем её
        a /= BASE;
    }
    // разворачиваем вектор-результат
    std::reverse(res.begin(), res.end());
    return res;
}


int main() {
    // первое большое число
    std::vector<int> a = pow(7 * 2);
    // второе большое число
    std::vector<int> b = pow(21);
    // третье большое число
    std::vector<int> c = valueOf(7);

    // вычисляем результат
    std::vector<int> r = minus(plus(a, b), c);

    // кол-во шестёрок изначально равно нулю
    int count6 = 0;
    // перебираем цифры числа
    for (int i: r) {
        // если цифра равна 6
        if (i == 6)
            // увеличиваем кол-во на 1
            count6++;
    }
    // выводим кол-во шестёрок
    std::cout << count6 << std::endl;
    return 0;
}



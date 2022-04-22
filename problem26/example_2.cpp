#include <iostream>
#include <fstream>
#include <map>
#include <set>

// главный метод программы
int main() {
    // открываем файл
    std::ifstream myfile;
    // бинарник собирается в отдельной папке, поэтому относительный путь такой
    // можно вместо этого закинуть файл куда-нибудь на диск и указать полный путь
    myfile.open("../problem26/26-59.txt");

    // словарь записей вида: "номер ряда: упорядоченное множество мест"
    std::map<int, std::set<int>> mp;
    // читаем кол-во записей
    int n;
    myfile >> n;

    // читаем сами записи
    for (int i = 0; i < n; i++) {
        // читаем номер ряда
        int r;
        myfile >> r;
        // читаем номер места
        int v;
        myfile >> v;

        // если в словаре есть запись с текущим номером ряда
        if (mp.count(r)) {
            // добавляем номер места в ряд с номером r
            mp.at(r).insert(v);
        } else {
            // создаём новый ряд
            std::set<int> row;
            // добавляем в него место
            row.insert(v);
            // добавляем в словарь ряд с ключом, соответствующим его номеру
            mp.insert({r, row});
        }
    }

    // закрываем файл
    myfile.close();

    // максимальный номер ряда
    int maxR = 0;
    // минимальный номер места
    int minV = -1;

    // перебираем записи словаря
    for (std::pair<int, std::set<int>> entry: mp) {
        // получаем ряд
        std::set<int> row = entry.second;
        // получаем минимальный номер места в ряде
        int l = *row.begin();
        // получаем максимальный номер места в ряде
        int r = *row.rbegin();
        // перебираем все места ряда
        for (int i = l; i <= r; i++) {
            // если текущее место занято и занято через два,
            // значит выполняется условие задачи для места с номером i+1
            if (row.count(i) && row.count(i + 3)) {
                // если номер ряда больше максимального
                if (entry.first > maxR) {
                    // сохраняем в качестве минимального номера
                    // номер следующего места
                    minV = i + 1;
                    // сохраняем номер ряда
                    maxR = entry.first;
                }
                // завершаем перебор мест
                break;
            }
        }
    }

    // выводим максимальное количество
    std::cout << maxR << " " << minV << std::endl;

    return 0;
}


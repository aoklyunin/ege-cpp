#include <iostream>

int main() {
    // создаём строку
    std::string s = "";
    // добавляем в неё 70 символов '8'
    for (int i = 0; i < 70; i++) {
        s += "8";
    }
    // пока строка содержит "2222" или "8888"
    while (s.find("2222") != std::string::npos || s.find("8888") != std::string::npos) {
        // если строка содержит "2222"
        if (s.find("2222") != std::string::npos)
            // заменяем "2222" на "88"
            s = s.replace(s.begin(), s.end(), "88", "2222");
        // если строка содержит "8888"
        else
            // заменяем "8888" на "22"
            s = s.replace(s.begin(), s.end(), "22", "8888");

    }
    // выводим результат
    std::cout << s;
    return 0;
}



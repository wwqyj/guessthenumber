#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "");
    srand(clock());

    // НОВОЕ: Запрос количества попыток
    int max_attempts;
    do {
        cout << "Сколько попыток вы хотите получить? (5, 7, 10): ";
        cin >> max_attempts;
        if (max_attempts <= 0) {
            cout << "Количество попыток должно быть больше 0.\n";
        }
    } while (max_attempts <= 0);

    int attempts_left = max_attempts; // Счётчик оставшихся попыток

    int num = rand() % 998 + 1;
    cout << "Программа: угадай число.\n";
    cout << "Компьютер загадал число от 1 до 999. \n";
    cout << "У вас " << attempts_left << " попыток. \n";

    int usernum;

    // ИЗМЕНЕНО: Цикл работает, пока есть попытки
    while (attempts_left > 0)
    {
        cout << "\nОсталось попыток: " << attempts_left << "\n";

        do
        {
            cout << "Введите число: ";
            cin >> usernum;
            if (usernum < 1 || usernum > 999)
            {
                cout << "Число должно лежать в диапазоне от 1 до 999. Повторите ввод. \n";
            }
        } while (usernum < 1 || usernum > 999);

        if (usernum > num)
        {
            cout << "Перелёт...\n";
            attempts_left--; // Уменьшаем количество попыток
        }
        else if (usernum < num)
        {
            cout << "Недолёт...\n";
            attempts_left--; // Уменьшаем количество попыток
        }
        else
        {
            int used = max_attempts - attempts_left + 1;
            cout << "Вы угадали число " << num <<
                " за " << used << " попыток.\n";
            return 0;
        }
    }

    // НОВОЕ: Попытки закончились
    cout << "Попытки закончились! Загаданное число было: " << num << "\n";
    return 0;
}
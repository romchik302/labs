#include <iostream>

using namespace std;

int check_num()
{
    int number; // Переменная для ввода числа
    bool t = true; // Логическая переменная, которая управляет циклом для повторения ввода

    while (t)
    {
        cin >> number; // Ввод числа

        // Проверка, не было ли ошибки при вводе данных
        if (cin.fail())
        {
            cout << "Incorrect value entered, please re-enter:\n";

            cin.clear();  // Очищает флаг ошибки ввода
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Игнорирует оставшиеся символы в потоке до конца строки
        }
        else
        {
            t = false; // Если ошибок нет, прекращаем цикл
        }
    }

    return number;
}

int check_num_arr()
{
    int number; // Переменная для ввода числа
    bool t = true; // Логическая переменная для контроля повторения ввода

    while (t)
    {
        cin >> number; // Ввод числа

        if (cin.fail())
        {
            cout << "Incorrect value entered, please re-enter:\n";

            cin.clear();  // Очищает флаг ошибки ввода
            cin.ignore(12345, '\n');  // Игнорирует оставшиеся символы в потоке
        }
        else if (number <= 1) // Проверяем, чтобы число было больше 1
        {
            cout << "The value entered is too small, please re-enter:\n";
        }
        else
        {
            t = false; // Если введено корректное значение, выходим из цикла
        }
    }

    return number; // Возвращаем корректное значение
}

int** array_creating(int len)
{
    // Создание двумерного динамического массива
    int** array = new int* [len]; // Создаём массив указателей для строк
    for (int i = 0; i < len; ++i)
    {
        array[i] = new int[len]; // Создаём массив для каждой строки
    }

    return array; // Возвращаем указатель на созданный массив
}

void array_output(int len, int** array)
{
    // Вывод двумерного массива
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            cout << array[i][j] << "\t\t"; // Выводим элементы массива с табуляцией
        }
        cout << "\n\n"; // Переход на новую строку после вывода строки массива
    }
}

int** array_diagonal_operation(int len, int** array)
{
    // Обнуление диагональных элементов массива
    for (int i = 0; i < len; ++i)
    {
        array[i][i] = 0; // Главная диагональ
        array[len - 1 - i][i] = 0; // Побочная диагональ
    }

    return array; // Возвращаем изменённый массив
}

int** array_filling(int len, int** array)
{
    // Заполнение двумерного массива пользователем
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            cout << "Enter element [" << i << "][" << j << "]: "; // Просим пользователя ввести элемент массива
            array[i][j] = check_num(); // Используем функцию проверки ввода
        }
    }

    return array; // Возвращаем заполненный массив
}

bool option_check()
{
    char symb; // Переменная для хранения ответа пользователя

    while (true)
    {
        cin >> symb;

        // Проверяем ввод
        if (symb == 'y' || symb == 'Y')
        {
            return true;
        }
        else if (symb == 'n' || symb == 'N')
        {
            return false;
        }
        else
        {
            cout << "Incorrect value entered, please re-enter:\n";

            cin.clear();  // Очищает флаг ошибки ввода
            cin.ignore(12345, '\n');  // Игнорирует оставшиеся символы в потоке
        }
    }
}

int main()
{
    int** matrix = new int*; // Указатель на двумерный массив
    bool repeat = true; // Флаг для повторения программы

    int lenght; // Переменная для длины стороны матрицы

    while (repeat)
    {
        // Ввод размеров массива
        cout << "Enter the side length of the square matrix: ";
        lenght = check_num_arr(); // Вводим размерность матрицы (больше 1)

        matrix = array_creating(lenght); // Создаём массив

        matrix = array_filling(lenght, matrix); // Заполняем массив
        cout << "Entered matrix:\n";
        array_output(lenght, matrix); // Выводим заполненный массив

        matrix = array_diagonal_operation(lenght, matrix); // Обнуляем диагональные элементы
        cout << "\nProcessed matrix:\n";
        array_output(lenght, matrix); // Выводим обработанный массив

        // Освобождаем память, выделенную под массив
        for (int i = 0; i < lenght; ++i) {
            delete[] matrix[i]; // Освобождаем память для каждой строки
        }
        delete[] matrix;

        cout << "\nContinue?(Y/N): ";
        repeat = option_check(); // Проверяем, хочет ли пользователь продолжить
        cout << '\n';
    }

    return 0;
}

#include <iostream>

using namespace std;

int check_num()
{
    int number; // ���������� ��� ����� �����
    bool t = true; // ���������� ����������, ������� ��������� ������ ��� ���������� �����

    while (t)
    {
        cin >> number; // ���� �����

        // ��������, �� ���� �� ������ ��� ����� ������
        if (cin.fail())
        {
            cout << "Incorrect value entered, please re-enter:\n";

            cin.clear();  // ������� ���� ������ �����
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���������� ���������� ������� � ������ �� ����� ������
        }
        else
        {
            t = false; // ���� ������ ���, ���������� ����
        }
    }

    return number;
}

int check_num_arr()
{
    int number; // ���������� ��� ����� �����
    bool t = true; // ���������� ���������� ��� �������� ���������� �����

    while (t)
    {
        cin >> number; // ���� �����

        if (cin.fail())
        {
            cout << "Incorrect value entered, please re-enter:\n";

            cin.clear();  // ������� ���� ������ �����
            cin.ignore(12345, '\n');  // ���������� ���������� ������� � ������
        }
        else if (number <= 1) // ���������, ����� ����� ���� ������ 1
        {
            cout << "The value entered is too small, please re-enter:\n";
        }
        else
        {
            t = false; // ���� ������� ���������� ��������, ������� �� �����
        }
    }

    return number; // ���������� ���������� ��������
}

int** array_creating(int len)
{
    // �������� ���������� ������������� �������
    int** array = new int* [len]; // ������ ������ ���������� ��� �����
    for (int i = 0; i < len; ++i)
    {
        array[i] = new int[len]; // ������ ������ ��� ������ ������
    }

    return array; // ���������� ��������� �� ��������� ������
}

void array_output(int len, int** array)
{
    // ����� ���������� �������
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            cout << array[i][j] << "\t\t"; // ������� �������� ������� � ����������
        }
        cout << "\n\n"; // ������� �� ����� ������ ����� ������ ������ �������
    }
}

int** array_diagonal_operation(int len, int** array)
{
    // ��������� ������������ ��������� �������
    for (int i = 0; i < len; ++i)
    {
        array[i][i] = 0; // ������� ���������
        array[len - 1 - i][i] = 0; // �������� ���������
    }

    return array; // ���������� ��������� ������
}

int** array_filling(int len, int** array)
{
    // ���������� ���������� ������� �������������
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            cout << "Enter element [" << i << "][" << j << "]: "; // ������ ������������ ������ ������� �������
            array[i][j] = check_num(); // ���������� ������� �������� �����
        }
    }

    return array; // ���������� ����������� ������
}

bool option_check()
{
    char symb; // ���������� ��� �������� ������ ������������

    while (true)
    {
        cin >> symb;

        // ��������� ����
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

            cin.clear();  // ������� ���� ������ �����
            cin.ignore(12345, '\n');  // ���������� ���������� ������� � ������
        }
    }
}

int main()
{
    int** matrix = new int*; // ��������� �� ��������� ������
    bool repeat = true; // ���� ��� ���������� ���������

    int lenght; // ���������� ��� ����� ������� �������

    while (repeat)
    {
        // ���� �������� �������
        cout << "Enter the side length of the square matrix: ";
        lenght = check_num_arr(); // ������ ����������� ������� (������ 1)

        matrix = array_creating(lenght); // ������ ������

        matrix = array_filling(lenght, matrix); // ��������� ������
        cout << "Entered matrix:\n";
        array_output(lenght, matrix); // ������� ����������� ������

        matrix = array_diagonal_operation(lenght, matrix); // �������� ������������ ��������
        cout << "\nProcessed matrix:\n";
        array_output(lenght, matrix); // ������� ������������ ������

        // ����������� ������, ���������� ��� ������
        for (int i = 0; i < lenght; ++i) {
            delete[] matrix[i]; // ����������� ������ ��� ������ ������
        }
        delete[] matrix;

        cout << "\nContinue?(Y/N): ";
        repeat = option_check(); // ���������, ����� �� ������������ ����������
        cout << '\n';
    }

    return 0;
}

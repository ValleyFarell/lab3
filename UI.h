#include<iostream>
#include"matrix.h"
#include"ArraySequence.h"

using namespace std;

enum class State {
    MENU,
    TYPE,
    FIRST_ED,
    SECOND_ED,
    TESTS,
    EXIT
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& obj)
{
    for (size_t i = 0; i < obj.getSize(); ++i) {
        for (size_t j = 0; j < obj.getSize(); ++j) {
            os << obj[i][j] << "\t";
        }
        os << endl;
    }
    return os;
}

int typeChoiceView(size_t& n1, size_t& n2) {
    int tmp = -1;
    while (tmp > 4 || tmp < 1) {
        cout << "/-----------------------Тип матриц-----------------------\\" << endl;
        cout << "|                                                        |" << endl;
        cout << "|  1. Целочисненные                                      |" << endl;
        cout << "|  2. Вещественные                                       |" << endl;
        cout << "|  3. Выход                                              |" << endl;
        cout << "|                                                        |" << endl;
        cout << "\\--------------------------------------------------------/" << endl;
        cout << " >>> ";
        cin >> tmp;
    }
    cout << " Введите размер первой и второй матрицы";
    cout << " >>> ";
    cin >> n1 >> n2;
    return tmp;
}

int mainMenuView() {
    int tmp = -1;
    while (tmp > 6 || tmp < 1) {
        cout << "/----------------------Главное Меню----------------------\\" << endl;
        cout << "|                                                        |" << endl;
        cout << "|  1. Создать матрицы                                    |" << endl;
        cout << "|  2. Редактировать 1 матрицу                            |" << endl;
        cout << "|  3. Редактировать 2 матрицу                            |" << endl;
        cout << "|  4. Запуск тестов                                      |" << endl;
        cout << "|  5. Выход                                              |" << endl;
        cout << "|  6. Выход                                              |" << endl;
        cout << "|                                                        |" << endl;
        cout << "\\--------------------------------------------------------/" << endl;
        cout << " >>> ";
        cin >> tmp;
    }
    return tmp;
}

int matrixEditView() {
    int tmp = -1;
    while (tmp > 12 || tmp < 1) {
        cout << "/----------------------Первая матрица--------------------\\" << endl;
        cout << "|                                                        |" << endl;
        cout << "|  1. Заполнить числами из консоли                       |" << endl;
        cout << "|  2. Заполнить случайными числами                       |" << endl;
        cout << "|  3. Поменять местами две строки                        |" << endl;
        cout << "|  4. Умножить строку на число                           |" << endl;
        cout << "|  5. Добавь к строке другую, умноженную на коэффициент  |" << endl;
        cout << "|  6. Умножить матрицу на число                          |" << endl;
        cout << "|  7. Вычесть вторую матрицу с коэффициентом             |" << endl;
        cout << "|  8. Умножить на вторую матрицу                         |" << endl;
        cout << "|  9. Транспонировать                                    |" << endl;
        cout << "|  10. Посчитать определитель                            |" << endl;
        cout << "|  11. Вывести матрицу                                   |" << endl;
        cout << "|  12. Выход                                             |" << endl;
        cout << "|                                                        |" << endl;
        cout << "\\--------------------------------------------------------/" << endl;
        cout << " >>> ";
        cin >> tmp;
    }
    return tmp;
}

void mainLoop(State state) {
    int type;
    Matrix<int> *mat1int;
    Matrix<double> *mat1double;
    Matrix<int> *mat2int;
    Matrix<double> *mat2double;
    while(1) {
        if (state == State::MENU) {
            int userCh = mainMenuView();
            if (userCh == 1) state = State::TYPE;
            if (userCh == 2) state = State::FIRST_ED;
            if (userCh == 3) state = State::SECOND_ED;
            if (userCh == 4) state = State::TESTS;
            if (userCh == 5) state = State::EXIT;
        } else
        if (state == State::TYPE) {
            size_t n1, n2;
            type = typeChoiceView(n1, n2);
            switch (type)
            {
            case 1:
                mat1int = new Matrix<int>(n1);
                mat2int = new Matrix<int>(n2);
                break;
            case 2:
                mat1double = new Matrix<double>(n1);
                mat2double = new Matrix<double>(n2);
                break;
            case 3:
                state = State::MENU;
                break;
            }
            state = State::MENU;
        } else
        if (state == State::FIRST_ED) {
            int userCh = matrixEditView();
        } else
        if (state == State::SECOND_ED) {
            int userCh = matrixEditView();
        } else
        if (state == State::TESTS) {
            mainMenuView();
        } else
        if (state == State::EXIT) {
            break;
        }
    }
}

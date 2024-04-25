#include <iostream>

using namespace std;

double chislosminysom(int** matrix, int m, int n) {
    int count = 0;
    int sum = 0;
    int diagonalLength = min(m, n);

    for (int i = 0; i < diagonalLength; ++i) {
        if (matrix[i][i] < 0) {
            sum += matrix[i][i];
            count++;
        }
    }

    if (count == 0) return 0;

    return static_cast<double>(sum) / count;
}

int firstRow(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > 0) {
                return i + 1;
            }
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int m, n;
    cout << "Введіть кількість рядків та стовпців матриці: ";
    cin >> m >> n;

    int** matrix = new int* [m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Середнє арифметичне від'ємних елементів головної діагоналі: " << chislosminysom(matrix, m, n) << endl;

    int firstPositiveRow = firstRow(matrix, m, n);
    if (firstPositiveRow != -1) {
        cout << "Номер першого рядка з додатнім елементом: " << firstPositiveRow << endl;
    }
    else {
        cout << "В матриці немає жодного рядка з додатнім елементом." << endl;
    }

    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

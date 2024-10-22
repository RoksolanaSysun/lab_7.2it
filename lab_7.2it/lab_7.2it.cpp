#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
bool SearchMinEven(int** a, const int rowCount, const int colCount, int& maxOfMin);

int main() {
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int maxOfMin;
    if (SearchMinEven(a, rowCount, colCount, maxOfMin)) {
        cout << "Max of min elements in even columns = " << maxOfMin << endl;
    }
    else {
        cout << "No even elements in even columns." << endl;
    }

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool SearchMinEven(int** a, const int rowCount, const int colCount, int& maxOfMin) {
    int minEven;


    for (int col = 0; col < colCount; col += 2) {
        int k = -1;
        for (int i = 0; i < rowCount; i++) {
            if (a[i][col] % 2 == 0) {
                k = i;
                minEven = a[i][col];
                break;
            }
        }

        if (k == -1)
            return false;

        for (int i = k + 1; i < rowCount; i++) {
            if (a[i][col] % 2 == 0 && a[i][col] < minEven) {
                minEven = a[i][col];
            }
        }

        if (minEven > maxOfMin) {
            maxOfMin = minEven;
        }
    }

    return true;
}
#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;
void task1() {
    int n;
    cout << "Введите число n (0 <= n <= 31): ";
    cin >> n;
    unsigned int result = 1 << n;
    cout << "2^" << n << " в десятичной системе: " << result << endl;
    cout << "2^" << n << " в восьмеричной системе: " << oct << result << endl;
    cout << "2^" << n << " в шестнадцатеричной системе: " << hex << result << endl;
}
void task2() {
    unsigned int X, n;
    cout << "Введите число X и номер бита n: ";
    cin >> X >> n;
    int bitValue = (X >> n) & 1;
    cout << "Значение бита " << n << ": " << bitValue << endl;
}
void task3() {
    unsigned int X, n;
    cout << "Введите число X и номер бита n: ";
    cin >> X >> n;
    unsigned int result = X | (1 << n);
    cout << "Результат в десятичной системе: " << dec << result << endl;
    cout << "Результат в восьмеричной системе: " << oct << result << endl;
    cout << "Результат в шестнадцатеричной системе: " << hex << result << endl;
}
void task4() {
    unsigned int X, n;
    cout << "Введите число X и номер бита n: ";
    cin >> X >> n;
    unsigned int result = X & ~(1 << n);
    cout << "Результат в десятичной системе: " << dec << result << endl;
    cout << "Результат в восьмеричной системе: " << oct << result << endl;
    cout << "Результат в шестнадцатеричной системе: " << hex << result << endl;
}
void task5() {
    unsigned int X, n;
    cout << "Введите число X и номер бита n: ";
    cin >> X >> n;
    unsigned int result = X ^ (1 << n);
    cout << "Результат в десятичной системе: " << dec << result << endl;
    cout << "Результат в восьмеричной системе: " << oct << result << endl;
    cout << "Результат в шестнадцатеричной системе: " << hex << result << endl;
}
void task6() {
    unsigned int X, Y, M;
    cout << "Введите число X: ";
    cin >> X;
    cout << "Число X в двоичной системе: " << bitset<32>(X) << endl;
    cout << "Введите число Y и длину маски M: ";
    cin >> Y >> M;
    unsigned int mask = (1 << M) - 1;
    unsigned int X_result = (X & ~mask) | (Y & mask);
    cout << "Число Y в двоичной системе: " << bitset<32>(Y) << endl;
    cout << "Результат в двоичной системе: " << bitset<32>(X_result) << endl;
}
void task7() {
    int N, M;
    cout << "Введите числа N и M: ";
    cin >> N >> M;
    if (N && M) cout << "N && M - истина\n";
    else cout << "N && M - ложь\n";
    if (N & M) cout << "N & M - истина\n";
    else cout << "N & M - ложь\n";
    if (N || M) cout << "N || M - истина\n";
    else cout << "N || M - ложь\n";
    if (N | M) cout << "N | M - истина\n";
    else cout << "N | M - ложь\n";
}
void variant4_task1() {
    unsigned int X;
    cout << "Введите шестнадцатеричное число: ";
    cin >> hex >> X;
    int maxCount = 0, currentCount = 0;
    for (int i = 0; i < sizeof(X) * 8; i++) {
        if (X & (1 << i)) {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        } else {
            currentCount = 0;
        }
    }
    cout << "Максимальное количество подряд идущих 1: " << maxCount << endl;
}
void variant4_task2() {
    unsigned int X;
    cout << "Введите шестнадцатеричное число: ";
    cin >> hex >> X;
    for (int i = 2; i < sizeof(X) * 8; i += 3) {
        X ^= (1 << i);
    }
    cout << "Результат: " << bitset<32>(X) << endl;
}
void variant4_task3() {
    uint8_t pattern1 = 0b10011001;
    uint8_t pattern2 = 0b01011010;
    uint8_t pattern3 = 0b00111100;
    cout << bitset<8>(pattern1) << endl;
    cout << bitset<8>(pattern2) << endl;
    cout << bitset<8>(pattern3) << endl;
    cout << bitset<8>(pattern3) << endl;
    cout << bitset<8>(pattern2) << endl;
    cout << bitset<8>(pattern1) << endl;
}
int main() {
    int choice;
    cout << "Выберите задание (1-7 для общих, 8-10 для варианта 4): ";
    cin >> choice;
    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: variant4_task1(); break;
        case 9: variant4_task2(); break;
        case 10: variant4_task3(); break;
        default: cout << "Неверный выбор!" << endl;
    }
    return 0;
}
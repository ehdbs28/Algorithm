#include <iostream>

using namespace std;

int main() {
    string message;

    int column;
    int row;

    while (true) {
        cin >> column;

        if (!column) {
            break;
        }

        cin >> message;
        row = message.size() / column;

        for (int i = 0; i < column; ++i) {
            for (int j = 0; j < row; ++j) {
                if (j % 2) {
                    cout << message[(j + 1) * column - i - 1];
                }
                else {
                    cout << message[j * column + i];
                }
            }
        }

        cout << '\n';
    }
}
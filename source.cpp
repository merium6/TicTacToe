#include <iostream>
#include <windows.h>

using namespace std;

void printBoard(const string arr[3][3]) {
    cout << endl << endl;
    for (int row = 0; row < 3; ++row) {
        cout << arr[row][0] << "  | " << arr[row][1] << "  | " << arr[row][2] << endl;
        if (row < 2) {
            cout << "___|____|___" << endl;
        }
    }
    cout << "   |    |    " << endl;
}

bool isCellValid(const string& cell) {
    return cell != "A" && cell != "B";
}

bool checkWin(const string arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) ||
            (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])) {
            return true;
        }
    }
    return (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) ||
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]);
}

int main() {
    char ch;
    do {
        system("CLS");
        int turn = 0;
        string arr[3][3] = { {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"} };

        do {
            printBoard(arr);

            int cell;
            cout << "\nEnter player " << (turn % 2 == 0 ? "A" : "B") << endl;
            cin >> cell;

            int row = (cell - 1) / 3;
            int col = (cell - 1) % 3;

            if (cell >= 1 && cell <= 9 && isCellValid(arr[row][col])) {
                arr[row][col] = (turn % 2 == 0) ? "A" : "B";
                turn++;
            }
            else {
                cout << "Invalid input, please try again in the next turn" << endl;
                Sleep(1500);
            }

            if (checkWin(arr)) {
                printBoard(arr);
                cout << "***************Congratulations**************\n   Player " << (turn % 2 == 0 ? "B" : "A") << " won the Game" << endl;
                break;
            }

            system("CLS");
        } while (turn < 9);

        cout << "Press Y if you want to continue... " << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}

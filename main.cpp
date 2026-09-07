#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Point {
    int x, y;
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void AnConTro() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

class CONRAN {
public:
    Point A[100];
    int DoDai;

    CONRAN() {
        DoDai = 3;
        A[0].x = 12; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 10; A[2].y = 10;
    }

    void Ve() {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "O";
        }
    }

    void XoaDuoi() {
        gotoxy(A[DoDai - 1].x, A[DoDai - 1].y);
        cout << " ";
    }

    void DiChuyen(int Huong) {
        XoaDuoi();
        for (int i = DoDai - 1; i > 0; i--) {
            A[i] = A[i - 1];
        }
        if (Huong == 0) A[0].x += 1;
        if (Huong == 1) A[0].y += 1;
        if (Huong == 2) A[0].x -= 1;
        if (Huong == 3) A[0].y -= 1;
    }
};

int main() {
    AnConTro();
    system("cls");

    CONRAN r;
    int Huong = 0;
    char t;

    r.Ve();

    while (true) {
        if (kbhit()) {
            t = getch();
            if ((t == 'd' || t == 'D') && Huong != 2) Huong = 0;
            if ((t == 's' || t == 'S' || t == 'x' || t == 'X') && Huong != 3) Huong = 1;
            if ((t == 'a' || t == 'A') && Huong != 0) Huong = 2;
            if ((t == 'w' || t == 'W') && Huong != 1) Huong = 3;
        }

        r.DiChuyen(Huong);
        r.Ve();
        Sleep(120);
    }

    return 0;
}

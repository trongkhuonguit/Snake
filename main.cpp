#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAP_LEFT = 0;
const int MAP_TOP = 1;
const int MAP_RIGHT = 79;
const int MAP_BOTTOM = 23;

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

void VeKhung() {
    for (int x = MAP_LEFT; x <= MAP_RIGHT; x++) {
        gotoxy(x, MAP_TOP);
        cout << "#";
        gotoxy(x, MAP_BOTTOM);
        cout << "#";
    }
    for (int y = MAP_TOP; y <= MAP_BOTTOM; y++) {
        gotoxy(MAP_LEFT, y);
        cout << "#";
        gotoxy(MAP_RIGHT, y);
        cout << "#";
    }
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

bool TrungThanRan(Point Moi, const CONRAN& r) {
    for (int i = 0; i < r.DoDai; i++) {
        if (Moi.x == r.A[i].x && Moi.y == r.A[i].y) return true;
    }
    return false;
}

void TaoMoi(Point& Moi, const CONRAN& r) {
    do {
        Moi.x = rand() % (MAP_RIGHT - MAP_LEFT - 1) + MAP_LEFT + 1;
        Moi.y = rand() % (MAP_BOTTOM - MAP_TOP - 1) + MAP_TOP + 1;
    } while (TrungThanRan(Moi, r));
}

bool VaChamTuong(const CONRAN& r) {
    Point Dau = r.A[0];
    return Dau.x <= MAP_LEFT || Dau.x >= MAP_RIGHT || Dau.y <= MAP_TOP || Dau.y >= MAP_BOTTOM;
}

bool VaChamThan(const CONRAN& r) {
    Point Dau = r.A[0];
    for (int i = 1; i < r.DoDai; i++) {
        if (Dau.x == r.A[i].x && Dau.y == r.A[i].y) return true;
    }
    return false;
}

void VeMoi(Point Moi) {
    gotoxy(Moi.x, Moi.y);
    cout << "*";
}

void VeDiem(int Diem) {
    gotoxy(0, 0);
    cout << "Diem: " << Diem;
}

void GameOver(int Diem) {
    gotoxy(MAP_LEFT, MAP_BOTTOM + 2);
    cout << "GAME OVER! Diem cua ban: " << Diem << endl;
}

void XuLyAnMoi(CONRAN& r, Point& Moi, Point DuoiCu, int& Diem) {
    if (r.A[0].x != Moi.x || r.A[0].y != Moi.y) return;

    if (r.DoDai < 100) {
        r.A[r.DoDai] = DuoiCu;
        r.DoDai++;
    }
    Diem += 10;
    VeDiem(Diem);
    TaoMoi(Moi, r);
    VeMoi(Moi);
}

int main() {
    AnConTro();
    system("cls");

    srand(static_cast<unsigned int>(time(NULL)));

    CONRAN r;
    Point Moi;
    int Huong = 0;
    int Diem = 0;
    char t;

    VeKhung();
    TaoMoi(Moi, r);
    VeMoi(Moi);
    VeDiem(Diem);
    r.Ve();

    while (true) {
        if (kbhit()) {
            t = getch();
            if ((t == 'd' || t == 'D') && Huong != 2) Huong = 0;
            if ((t == 's' || t == 'S' || t == 'x' || t == 'X') && Huong != 3) Huong = 1;
            if ((t == 'a' || t == 'A') && Huong != 0) Huong = 2;
            if ((t == 'w' || t == 'W') && Huong != 1) Huong = 3;
        }

        Point DuoiCu = r.A[r.DoDai - 1];
        r.DiChuyen(Huong);

        if (VaChamTuong(r) || VaChamThan(r)) {
            GameOver(Diem);
            break;
        }

        XuLyAnMoi(r, Moi, DuoiCu, Diem);
        r.Ve();
        Sleep(120);
    }

    return 0;
}

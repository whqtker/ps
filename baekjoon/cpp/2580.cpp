#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Coor {
    int x, y;
    Coor(int x, int y) : x(x), y(y) {}
};

int arr[9][9];
vector<Coor> zeros;

int chk_row[9]; // i번째 행에 방문 체크 비트
int chk_col[9];
int chk_square[9];

int get_square_idx(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}

void printArr() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int cnt) {
    if (cnt == zeros.size()) {
        printArr();
        exit(0);
    }

    int x = zeros[cnt].x;
    int y = zeros[cnt].y;
    int square_idx = get_square_idx(x, y);

    for (int i = 1; i <= 9; i++) {
        int mask = chk_row[x] | chk_col[y] | chk_square[square_idx];
        int cur = 1 << (i - 1);

        if ((mask & cur) == 0) {
            arr[x][y] = i;
            chk_row[x] ^= cur;
            chk_col[y] ^= cur;
            chk_square[square_idx] ^= cur;

            dfs(cnt + 1);

            arr[x][y] = 0;
            chk_row[x] ^= cur;
            chk_col[y] ^= cur;
            chk_square[square_idx] ^= cur;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                zeros.push_back(Coor(i, j));
            }
            else {
                int num = arr[i][j];
                int cur = 1 << (num - 1);
                int square_idx = get_square_idx(i, j);

                chk_row[i] |= cur;
                chk_col[j] |= cur;
                chk_square[square_idx] |= cur;
            }
        }
    }

    dfs(0);
}
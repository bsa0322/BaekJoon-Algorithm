#include<iostream>
using namespace std;
int sdocu[9][9];
int check_w[9][10];
int check_h[9][10];
int check3x3[9][10];
void f(int x,int y)
{
    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sdocu[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    if (sdocu[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check_w[x][i] == 0 && check_h[y][i] == 0 && check3x3[(x / 3) * 3 + y / 3][i] == 0)
            {
                check_w[x][i] = 1;
                check_h[y][i] = 1;
                check3x3[(x / 3) * 3 + y / 3][i] = 1;
                sdocu[x][y] = i;
                if (y == 8) f(x + 1, 0);
                else f(x, y + 1);
                sdocu[x][y] = 0;
                check_w[x][i] = 0;
                check_h[y][i] = 0;
                check3x3[(x / 3) * 3 + y / 3][i] = 0;
            }
        }
    }
    else
    {
        if (y == 8) f(x + 1, 0);
        else f(x, y + 1);
    }
}

/**
 * 9X9의 스도쿠에서 각 행, 열, 3x3 사각형에 1~9가 존재하는지 체크하는 2차원 배열 활용
 * 각 2차원 배열의 행: 어느 부분에 대한 체크인지(행, 열, 3x3)
 * 각 2차원 배열의 열: 1 ~ 9 숫자 체크
 *
 * 3x3 사각형 행의 0번 인덱스 부분
 * (0,0) (0,1) (0,2)
 * (1,0) (1,1) (1,2)
 * (2,0) (2,1) (2,2)
 * -> x를 3으로 나눈 몫(0)과 y를 3으로 나눈 몫(0)의 합 0
 * 3x3 사각형 행의 1번 인덱스 부분
 * (0,3) (0,4) (0,5)
 * (1,3) (1,4) (1,5)
 * (2,3) (2,4) (2,5)
 * -> x를 3으로 나눈 몫(0)과 y를 3으로 나눈 몫(1)의 합 1
 * 3x3 사각형 행의 2번 인덱스 부분
 * (0,6) (0,7) (0,8)
 * (1,6) (1,7) (1,8)
 * (2,6) (2,7) (2,8)
 * -> x를 3으로 나눈 몫(0)과 y를 3으로 나눈 몫(2)의 합 2
 * .
 * .
 * .
 * 다음 칸으로 넘어가는 걸 구분하기 위해 x를 3으로 나눈 몫에 3을 곲함
 *
 * 따라서 3x3 사각형의 구간은 (x/3)*3 + (y/3) = 0 ~ 9인 구간으로 나눌 수 있음
 */

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sdocu[i][j];
            if (sdocu[i][j] != 0)
            {
                check_w[i][sdocu[i][j]] = 1;
                check_h[j][sdocu[i][j]] = 1;
                check3x3[(i/3)*3 + (j/3)][sdocu[i][j]] = 1;
            }
        }
    }
    f(0, 0);
    return 0;
}
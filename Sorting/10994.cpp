#include <iostream>
#include <vector>

using namespace std;

void fillStar(int width, vector <vector <char> > &star, int x, int y)
{
    //width가 1이면 더 이상 동작 수행 불가. 다시 돌아가면서 별 채우기 수행
    if(width == 1)
    {
        star[x][y]='*';
        return;
    }

    //width는 4씩 줄어들고, 시작(왼쪽 위) x, y 위치값은 2씩 증가
    fillStar(width-4, star, x+2, y+2);

    //테두리 별 채우기
    for(int i=x;i<x+width;i++)
    {
        //(i,y): 왼쪽 열 테두리, (x,i): 위쪽 행 테두리, (x+width-1,i): 아래쪽 행 테두리, (i,y+width-1): 오른쪽 열 테두리
        star[i][y]=star[x][i]=star[x+width-1][i]=star[i][y+width-1]='*';
    }

}

int main() {
    int n, width;

    //입력
    cin >> n;
    width = 4*n-3; //출력되는 별의 n값에 따른 가로 세로 길이
    vector <vector <char> > star(width,vector <char>(width,' ')); // 공백으로 찬 width*width 벡터 생성

    //연산
    //별을 자세히 들여다보면 테두리만 그려진 별로 width가 -4씩 줄어드는 것을 알 수 있음
    //3번째와 4번째 인덱스는 각각 시작(왼쪽 위) x, y인덱스 값
    fillStar(width, star,0, 0);

    //출력
    for(int i=0;i<width;i++){
        for (int j = 0; j < width; j++)
            cout << star[i][j];
        cout << '\n';
    }
    return 0;
}

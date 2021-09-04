#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 */

vector<int> calcPlus(vector<int> &a, vector<int> &b, int n) {
    vector<int> plus, result; //plus: 다음 자리수로 넘어가서 더해지는 수
    plus.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int num = plus[i] + a[i] + b[i]; //각 자리수의 값 + 전 자리수에서 넘어온 수 더함
        plus[i + 1] = num / 10; //다음 자리수로 넘어가서 더해지는 수
        result.push_back(num % 10); //현재 자리수 최종 값
    }
    if (plus[n]) result.push_back(plus[n]);
    return result;
}

//string 으로 받은 입력 수를 벡터에 일의 자리 수부터 저장
vector<int> stringToVec(string str, int n) {
    vector<int> arr(n, 0);
    for (int x = 0, i = str.length() - 1; i >= 0; x++, i--)
        arr[x] = str[i] - '0';
    return arr;
}

int main() {
    string str_a, str_b; //길이가 매우 기므로 string 으로 입력
    vector<int> a, b, result; //각 A, B의 각 자리수에 대한 값 저장, 더한 결과 저장하는 result 배열

    //입력
    cin >> str_a >> str_b;
    int n = max(str_a.length(), str_b.length());
    a = stringToVec(str_a, n);
    b = stringToVec(str_b, n);

    //연산
    result = calcPlus(a, b, n);

    //출력
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
    cout << '\n';

    return 0;
}
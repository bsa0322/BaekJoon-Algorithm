#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

// 최대 공약수 구하기
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// 계산
pl calculate(pl& a, pl& b, pl& c) {
	// b / c
	pl bc = { b.first * c.second, b.second * c.first };
	ll bc_gcd = gcd(bc.first, bc.second);
	bc = { bc.first / bc_gcd, bc.second / bc_gcd };

	// a + b / c
	pl result = { a.first * bc.second + a.second * bc.first, a.second * bc.second };
	ll result_gcd = gcd(result.first, result.second);
	result = { result.first / result_gcd, result.second / result_gcd };
	
	return result;
}

// 숫자 꺼낼 때 유효성 확인
bool validate(stack<pl>& st) {
	if (st.empty()) {
		return false;
	}
	if (st.top().first == 0) {
		return false;
	}
	return true;
}

pl solution(int& n, vector<char>& num) {
	stack<pl> st; //first: 분자, second: 분모, {0, 0} : 여는 괄호
	for (int i = 0; i < n; i++) {
		char curr = num[i];
		if (curr == '(') {
			st.push({0, 0});
		}
		else if (curr == ')') {
			// 연산 수행
			vector<pl> temp(3);
			for (int j = 2; j >= 0; j--) {
				if (!validate(st)) {
					return { -1, -1 };
				}
				temp[j] = st.top();
				st.pop();
			}
			if (st.empty() || st.top().first != 0) {
				// 3개 꺼냈는데, 스택 비었거나 그 전이 여는 괄호가 아니라면
				return { -1,-1 };
			}
			pl result = calculate(temp[0], temp[1], temp[2]);

			// 새로운 숫자 넣기
			st.pop(); // 여는 괄호 제거
			st.push(result);
		}
		else {
			// 숫자
			int curr_num = curr - '0';
			// 분수 형태로 바꿔서 넣기
			st.push({ curr_num, 1 });
		}
	}
	if (st.size() != 1 || st.top().first == 0) {
		// 괄호가 아직 남아있거나, st 사이즈가 1이 아니라면 -> -1
		return { -1, -1 };
	}
	return { st.top().first, st.top().second };
}

int main() {
	int n;
	cin >> n;
	vector<char> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	pl result = solution(n, num);

	if (result.first == -1) {
		cout << "-1";
	}
	else {
		cout << result.first << ' ' << result.second;
	}
	
	return 0;
}
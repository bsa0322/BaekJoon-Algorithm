#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    string s;
    int t, n, x;
    cin >> t;
    while (t--) {
        priority_queue<int, vector<int>, greater<int>> pq_min; //최소힙
        priority_queue<int, vector<int>, less<int>> pq_max; //최대힙
        map<int, int> mp_min; //최소힙에서 삭제한 거 기억하는 맵
        map<int, int> mp_max; //최대힙에서 삭제한 거

        cin >> n;
        //삭제한 걸 어떻게 기억해?
        while (n--) {
            cin >> s >> x;
            if (s == "I") { //푸쉬
                pq_min.push(x);
                pq_max.push(x);
            } else { //삭제
                if (pq_min.empty() || pq_max.empty()) continue;
                if (x == 1) { //최댓값 삭제
                    int top = pq_max.top();
                    while (mp_min.find(top) != mp_min.end() && mp_min[top] != 0) {
                        //cout<<"min use: "<<top<<'\n';
                        pq_max.pop();
                        mp_min[top]--;
                        if (pq_max.empty()) break;
                        top = pq_max.top();
                    }
                    if (!pq_max.empty()) {
                        mp_max[top]++;
                        pq_max.pop();
                    }
                } else { //최솟값 삭제
                    int top = pq_min.top();
                    while (mp_max.find(top) != mp_max.end() && mp_max[top] != 0) {
                        //cout<<"max use: "<<top<<'\n';
                        pq_min.pop();
                        mp_max[top]--;
                        if (pq_min.empty()) break;
                        top = pq_min.top();
                    }
                    if (!pq_min.empty()) {
                        mp_min[top]++;
                        pq_min.pop();
                    }
                }
            }
        }
        if (!pq_min.empty()) {
            int top = pq_min.top();
            while (mp_max.find(top) != mp_max.end() && mp_max[top] != 0) {
                //cout<<"max use: "<<top<<'\n';
                pq_min.pop();
                mp_max[top]--;
                top = pq_min.top();
            }
        }
        if (!pq_max.empty()) {
            int top = pq_max.top();
            while (mp_min.find(top) != mp_min.end() && mp_min[top] != 0) {
                //cout<<"min use: "<<top<<'\n';
                pq_max.pop();
                mp_min[top]--;
                top = pq_max.top();
            }
        }
        if (pq_max.empty() || pq_min.empty()) cout << "EMPTY\n";
        else {
            cout << pq_max.top() << ' ' << pq_min.top() << '\n';
        }
    }
    return 0;
}
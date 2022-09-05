#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll>> ci;

bool cmpFirst(const ci &a, const ci &b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }
    return a.second.second > b.second.second;
}


bool cmpSecond(const ci &a, const ci &b) {
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second.second > b.second.second;
}

int main() {
    ll n, l, r, v;
    cin >> n;
    vector<ci> arr;
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> v;
        arr.push_back({l, {r, v}});
    }
    sort(arr.begin(), arr.end(), cmpSecond);
    ci first = arr[0];
    ll ans1 = first.second.second;
    for (int i = 1; i < n; i++) {
        if (first.first <= arr[i].first) {
//            cout << first.first << '\n';
            ans1 += arr[i].second.second;
        } else if (ans1 < arr[i].second.second) {
            ans1 = arr[i].second.second;
            first = arr[i];
        }
    }
    sort(arr.begin(), arr.end(), cmpFirst);
    first = arr[0];
    ll ans2 = first.second.second;
    for (int i = 1; i < n; i++) {
        if (first.second.first >= arr[i].second.first) {
            ans2 += arr[i].second.second;
        } else if (ans2 < arr[i].second.second) {
            ans2 = arr[i].second.second;
            first = arr[i];
        }
    }
    cout << max(ans1, ans2);
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N{};
    vector<int> va;
    vector<int> vb;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        va.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        vb.push_back(b);
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int res = 0;
    for (int i = 0; i < N; i++) {
        res += va[i] * vb[N - i - 1];
    }
    cout << res;
}
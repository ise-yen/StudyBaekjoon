// 스택 수열

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n{};
	cin >> n;

	stack<int> s;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num{};
		cin >> num;
		v.push_back(num);
	}


	int before{}, now = v[0], after = v[1];

	for (int i = 0; i < n; i++) {
		for (int i = 1; i <= now; i++) {
			s.push(i);
			cout << "+" << endl;
		}
	}



	

}
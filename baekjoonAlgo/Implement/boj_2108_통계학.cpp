#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int N{};
	cin >> N;

	double mean{};
	int median{}, mode{}, range{}; // 산술평균, 중앙값, 최빈값, 범위
	
	vector<int> v;

	vector<pair<int, int>> vp; // 숫자, 빈도수

	for (int i = -4000; i <= 4000; i++) {
		vp.push_back({ i, 0 });
	}

	for (int i = 0; i < N; i++) {
		int num{};
		cin >> num;

		mean += num;
		v.push_back(num);

		/*
		vp[-10] vp[-9] vp[-8] vp[-7] vp[-6] vp[-5] vp[-4] vp[-3] vp[-2] vp[-1] vp[0]
		*/
		vp[4000 + num].second = vp[4000 + num].second + 1;
	}


	// 산술평균
	mean = round((double)mean/N);
	
	// 중앙값
	std::sort(v.begin(), v.end());
	median = v[N / 2];
 
	// 최빈값
	std::sort(vp.begin(), vp.end(), compare);
	if (vp[0].second == vp[1].second) mode = vp[1].first;
	else mode = vp[0].first;

	for (int i = 0; i < vp.size(); i++) {
		if (vp[i].second == 0) continue;
		//cout << i << ": " << vp[i].first << " " << vp[i].second << "\n";
	}
	// 범위
	if (N == 1) range = 0;
	else
		range = v[N - 1] - v[0];

	// 출력
	std::cout << (int)mean << "\n" << median << "\n" << mode << "\n" << range;
}
// Ω∫≈√
#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

enum class Order {
	push,
	pop,
	size,
	empty,
	top
};

map<string, Order> orders;

void register_orders() {
	orders["push"] = Order::push;
	orders["pop"] = Order::pop;
	orders["size"] = Order::size;
	orders["empty"] = Order::empty;
	orders["top"] = Order::top;
}

int main() {
	register_orders();

	int N{};
	cin >> N;

	stack<int> s;
	int num{};

	for (int i = 0; i < N; i++) {
		string str{};
		cin >> str;
		
		switch (orders[str])
		{
			case Order::push:
				cin >> num;
				s.push(num);
				break;
			case Order::pop:
				if (s.empty()) cout << -1 << endl;
				else {
					cout << s.top() << endl;
					s.pop();
				}
				break;
			case Order::size:
				cout << s.size() << endl;
				break;
			case Order::empty:
				cout << s.empty() << endl;
				break;
			case Order::top:
				if (s.empty()) cout << -1 << endl;
				else cout << s.top() << endl;
				break;
			default:
				break;
		}

	}
}
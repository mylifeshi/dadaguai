#include <iostream>
long long a;
int main() {
	while (1) {
		std::cin >> a;
		if (a == -1)break;
		std::cout << "你说了：" << a << std::endl;
	}
	return 0;
}
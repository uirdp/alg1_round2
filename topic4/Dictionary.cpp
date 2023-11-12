#include <iostream>
#include <unordered_map>
#include <string>

int main() {

	std::unordered_map < std::string, int> dict;

	int n;
	std::cin >> n;

	std::string command;
	std::string key;

	for (int i = 0; i != n; ++i) {
		std::cin >> command;

		if (command[0] == 'i') {
			std::cin >> key;
			dict.emplace(key, 1);
			dict[key] = 1;
		}
		
		if (command[0] == 'f') {
			std::cin >> key;
			if (dict[key] == 1) std::cout << "yes" << std::endl;
			else std::cout << "no" << std::endl;
		}
	}
}
#include <iostream>
#include <vector>

bool binarySearch(int key, std::vector<int>& list) {
	int left = 0;
	int right = list.size() - 1;
	

	while (left <= right) {
		
		int mid = (right + left) / 2;

		if (list[mid] == key) return true;
		if (list[mid] > key)  right = mid - 1;
		if (list[mid] < key) left = mid + 1;

	}

	return false;
}

int main() {
	
	

	int n;
	std::cin >> n;

	std::vector<int> input_list(n);

	for (int i = 0; i != n; ++i) {
		
		int in_val;
		std::cin >> input_list.at(i);

	}

	std::cin >> n;
	int key;
	int cnt = 0;
	for (int i = 0; i != n; ++i) {
		std::cin >> key;
		if (binarySearch(key, input_list)) cnt++;
	}

	std::cout << cnt << std::endl;

}
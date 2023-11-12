#include <iostream>
#include <vector>
#include <algorithm>

void Allocation() {

	int num_of_packages{ 0 };
	std::cin >> num_of_packages;

	int num_of_trucks{ 0 };
	std::cin >> num_of_trucks;

	std::vector<int> packages;
	int package;
	int sum_of_weight{ 0 };
	int max_weight{ 0 };

	for (int i = 0; i < num_of_packages; i++) {
		std::cin >> package;
		packages.push_back(package);
		
		sum_of_weight += package;
		max_weight = std::max(package, max_weight);
	}

	//P is bigger than the maximum weight, and smaller than sum of the weight
	int left = max_weight - 1;
	int right = sum_of_weight + 1;
	int mid_P;

	while (left + 1 < right) {

		mid_P = (left + right) / 2;
		
		int required_trucks{ 1 };
		int loaded_packages{ 0 };
		
		for (int package : packages) {
			
			if (loaded_packages + package > mid_P) {
				++required_trucks;
				loaded_packages = 0;
			}

		    loaded_packages += package;
		}

		//Current P requires more trucks than provided (P should be bigger)
		if (required_trucks > num_of_trucks) left = mid_P;
		else right = mid_P;
	}

	std::cout << right << std::endl;

}

int main() {
	Allocation();
}
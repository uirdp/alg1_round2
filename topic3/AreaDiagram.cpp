#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct terrain {
	char c;
	int x;
	int y;
};

std::vector<int> CalcArea(std::vector<terrain>& diagram) {

	std::vector<terrain> pool(20000);
	std::vector<int> sub_areas;

	int sub_area = 0;
	int area = 0;
	int cnt = 0;
	int num_of_pool = 0;

	int maxHeight = 0;
	bool flag = false;

	for (int i = 0; i < diagram.size(); i++) {
		if (diagram[i].c == '\\') {
			cnt++;
			pool[diagram[i].y] = diagram[i];
		}
		else if (diagram[i].c == '/' && cnt > 0) {
			cnt--;
			int distance = diagram[i].x - pool[diagram[i].y].x;
			area += distance;
			sub_area += distance;

			maxHeight = 0;

			for (int j = i; j < diagram.size(); j++) {
				if(diagram[j].c == '/') maxHeight = std::max(maxHeight, diagram[j].y);
			}

			if (maxHeight <= (cnt + diagram[i].y)) flag = true;

			if (cnt <= 0 || (diagram[i].y == maxHeight && flag)) {
				num_of_pool++;

				sub_areas.push_back(sub_area);
				sub_area = 0;
				maxHeight = 0;
				flag = false;
				cnt = 0;
			}
		}
		else continue;
	}
	

	std::cout << area << std::endl;

	sub_areas.insert(sub_areas.begin(), num_of_pool);
	return sub_areas;
}

void AreasOnDiagram() {

	std::vector<terrain> diagram;
	
	std::string in;
	std::getline(std::cin, in);


	int height = 20000;

	for (int i = 0; i < in.length(); i++) {
		
		terrain tr;
		tr.c = in[i];

		if (in[i] == '/') height++;

		tr.x = i;
		tr.y = height;

		if (in[i] == '\\') height--;


		diagram.push_back(tr);
	}

	std::vector<int> res = CalcArea(diagram);

	for (int i = 0; i < res.size(); i++) {
		if (i) std::cout << " ";
		std::cout << res[i];
	}
	std::cout << std::endl;
}

int main() {
	AreasOnDiagram();
}
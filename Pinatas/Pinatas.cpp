#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int maxCandies(std::vector<int>& p, int left, int right) {
	if (left > right) return 0;

	int max_candies = 0;
	for (int i = left; i <= right; i++) {
		int candies = p[left - 1] * p[i] * p[right + 1]
			+ maxCandies(p, left, i - 1)
			+ maxCandies(p, i + 1, right);
		max_candies = std::max(max_candies, candies);
	}
	return max_candies;
}

int main() {
    std::cout << "Enter pinata values separated by space: ";
    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    int val;
    std::vector<int> pinatas;

    while (ss >> val) {
        pinatas.push_back(val);
    }

    pinatas.insert(pinatas.begin(), 1);
    pinatas.push_back(1);

    int n = pinatas.size();

    int result = maxCandies(pinatas, 1, n - 2);
    std::cout << "Maximum candies: " << result << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

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
	std::vector<int> pinates = { 1, 3, 1, 5, 8, 1 }; //"1" at the begin and end!
	int result = maxCandies(pinates, 1, 4);

	std::cout << "Maximum candies: " << result << std::endl;

	return 0;
}
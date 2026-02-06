#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;

// std::floor (올림, 내림, 반올림)
// std::advance (이터레이터 이동)
// std::distance (이터레이터 거리 계산)

bool LinearSearch(int target, vector<int>& sequence)
{
	for(auto i : sequence)
	{
		if (i == target)
		{
			return true;
		}
	}

	return false;
}

bool BinarySearch(int target, vector<int>& sequence)
{
	auto first = sequence.begin();
	auto last = sequence.end();

	while (true)
	{
		auto rangeLength = distance(first, last);
		int midElementIndex = floor(rangeLength / 2);
		auto midElement = *(first + midElementIndex);

		if (midElement = target)
		{
			return true;
		}
		else if (midElement > target)
		{
			advance(last, -midElementIndex);
		}

		if (midElement < target)
		{
			advance(first, midElementIndex);
		}

		if (rangeLength <= 1)
		{
			return false;
		}
	}
}

int main()
{
	return 0;
}

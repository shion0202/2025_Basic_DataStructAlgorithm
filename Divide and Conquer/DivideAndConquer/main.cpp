#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<algorithm>
using namespace std;

bool LinearSearch(const vector<int>& array, int target)
{
	for (int i : array)
	{
		if (i == target) return true;
	}

	return false;
}

bool BinarySearch(const vector<int>& array, int target)
{
	if (array.empty()) return false;

	auto first = array.begin();
	auto last = array.end();

	while (first < last)
	{
		auto rangeLength = distance(first, last);
		auto midOffset = rangeLength / 2;
		auto mid = next(first, midOffset);			// midElement의 반복자

		if (*mid == target)
		{
			return true;
		}
		else if (*mid > target)
		{
			// midElement의 반복자가 last, 즉 현재 midElement의 이전까지 왼쪽으로 검색 범위를 좁힘
			last = mid;
		}
		else if (*mid < target)
		{
			// midElement의 반복자가 first, 즉 현재 midElement의 다음부터 오른쪽으로 검색 범위를 좁힘
			first = next(mid);
		}
	}

	return false;
}

void RunSmallSearchTest()
{
	int target = 2;
	vector<int> smallArray{ 1, 3, 2, 4, 5, 7, 9, 8, 6 };
	
	sort(smallArray.begin(), smallArray.end());

	if (LinearSearch(smallArray, target))
	{
		cout << "Linear Search: Found " << target << endl;
	}
	else
	{
		cout << "Linear Search: Not Found " << target << endl;
	}

	if (BinarySearch(smallArray, target))
	{
		cout << "Binary Search: Found " << target << endl;
	}
	else
	{
		cout << "Binary Search: Not Found " << target << endl;
	}
}

void RunLargeSearchTest(int size, int target)
{
	vector<int> largeArray;
	random_device rd;
	mt19937 rand(rd());

	// 1~size 범위의 정수 난수 생성
	uniform_int_distribution<mt19937::result_type> uniformDist(1, size);

	cout << "난수 생성 중..." << endl;
	for (int i = 0; i < size; ++i)
	{
		largeArray.push_back(uniformDist(rand));
	}
	sort(largeArray.begin(), largeArray.end());

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	bool searchResult = BinarySearch(largeArray, target);
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "이진 검색 수행 시간: " << diff.count() << endl;

	if (searchResult)
	{
		cout << "Binary Search: Found " << target << endl;
	}
	else
	{
		cout << "Binary Search: Not Found " << target << endl;
	}
	cout << endl;
}

int main()
{
	RunSmallSearchTest();
	cout << endl;

	RunLargeSearchTest(100000, 36543);
	RunLargeSearchTest(1000000, 36543);
	RunLargeSearchTest(10000000, 36543);

	return 0;
}

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

void printArray(const vector<vector<int>>& numbers)
{
	for (int row = 0; row < numbers.size(); row++)
	{
		for (int col = 0; col < numbers[row].size(); col++)
		{
			cout << numbers[row][col] << " ";
		}
		cout << endl;
	}
}

double averageSales(const vector<vector<int>>& numbers)
{
	int total = 0;
	int count = 0;

	for (int row = 0; row < numbers.size(); row++)
	{
		for (int col = 0; col < numbers[row].size(); col++)
		{
			total += numbers[row][col];
			count++;
		}
	}

	return static_cast<double>(total) / count;
}

int maxRow(const vector<vector<int>>& numbers, int row)
{
	int maximum = numbers[row][0];

	for (int col = 1; col < numbers[row].size(); col++)
	{
		if (numbers[row][col] > maximum)
		{
			maximum = numbers[row][col];
		}
	}

	return maximum;
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 100);

	vector<vector<int>> numbers(4, vector<int>(3));

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			numbers[row][col] = dist(gen);
		}
	}

	cout << "2D Array Contents:" << endl;
	printArray(numbers);

	cout << fixed << setprecision(2);
	cout << "\nAverage Sales: " << averageSales(numbers) << endl;

	int row = 0;
	cout << "Maximum value in row " << row << ": "
		<< maxRow(numbers, row) << endl;

	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int* array;
	cin >> n;;
	array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
			swap(array[j - 1], array[j]);
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
		return 0;
}

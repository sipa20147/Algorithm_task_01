#include <iostream>
#include <ctime>

using namespace std;

void FillArray(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void SortArray(int* arr, int size)
{
	for (int i = size - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int foo = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = foo;
			}
		}
	}
}


void ShowArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void max(int* arr, int size)
{
	int max = arr[0];
	int index = 0;
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}
	cout << "Максимальное значение массива = " << index;
}

void BinSearch(int* arr, int size, int key)
{
	int l = 0;
	int r = size - 1;
	int search = -1;
	
	for (int i = 0; i < size; i++)
	{
		int m = (r - l) / 2;

		if (key == arr[m])
		{
			search = m;
			break;
		}
		if (key < arr[m])
			r = m - 1;
		else
			l = m + 1;
	}
	if (search == -1)
		cout << "Искомый номер элемента не найден";
	else
		cout << "Искомый номер элемента: " << search;
	
}
	
				





int main()
{
	setlocale(LC_ALL, "ru");
	int const size = 10;
	int arr[size];
	int key;

	cout << "Введите искомое число:";
	cin >> key;

	FillArray(arr, size);
	ShowArray(arr, size);
	SortArray(arr, size);
	cout << "==============================" << endl;
	ShowArray(arr, size);
	cout << "==============================" << endl;
	BinSearch(arr, size, key);
}

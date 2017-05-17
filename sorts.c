#include <stddef.h>
#include <stdio.h>

#define ARR_SIZE 10

// 26 65 35 65 48 78 98 15 54 29
// 26 35 65 48 65 78 15 54 29 98

// 9 8 7 6 5 4 3 2 1 0
// 8 7 6 5 4 3 2 1 0 9
// 7 6 5 4 3 2 1 0 8 9
// 6 5 4 3 2 1 0 7 8 9
// 5 4 3 2 1 0 6 7 8 9
// 4 3 2 1 0 5 6 7 8 9 
// 3 2 1 0 4 5 6 7 8 9
// 2 1 0 3 4 5 6 7 8 9
// 1 0 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9


void Swap(int* one, int* two)
{
	int temp = *one;
	*one = *two;
	*two = temp;
}
	


void printArr(int* arr)
{
	for (size_t i = 0; i < ARR_SIZE; ++i)
	{
		printf("%d ", arr[i]);
	}
	puts("");
}



void BubbleSort(int* arr)
{
	for (size_t i = 0; i < ARR_SIZE - 1; ++i)
	{
		for (size_t j = 0; j < ARR_SIZE - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}



void InsertionSort(int *arr)
{
	// 26 65 35 65 48* 78 98 15 54 29
	// 26 35 48 65 65 

	for (size_t i = 1; i < ARR_SIZE; ++i)
	{
		for (size_t j = i; j > 0; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(&arr[j], &arr[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}
     

void ShellSort(int* arr)
{
	for (int step = 5; step >= 1; step -= 2)
	{
		for (size_t start = 0; start < step; ++start)
		{
			for (size_t i = start + step; i < ARR_SIZE; i += step)
			{
				for (size_t j = i; j > start; j -= step)
				{
					if (arr[j] < arr[j - step])
					{
						Swap(&arr[j], &arr[j - step]);
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}



int main()
{
	int arr1[ARR_SIZE] = { 26, 65, 35, 65, 48, 78, 98, 15, 54, 29 };
	int arr2[ARR_SIZE] = { 26, 65, 35, 65, 48, 78, 98, 15, 54, 29 };
	int arr3[ARR_SIZE] = { 26, 65, 35, 65, 48, 78, 98, 15, 54, 29 };

	BubbleSort(arr1);
	printArr(arr1);
	
	InsertionSort(arr2);
	printArr(arr2);

	ShellSort(arr3);
	printArr(arr3);

	return 0;
}

// 26, 65*, 35, 65, 48, 78, 98, 15, 54, 29*
// 26, 29, 35, 15, *48*, 78, 98, 65, 54, 65
// mid = 48, l = , r = 
// 
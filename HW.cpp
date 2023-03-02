#include <iostream>
using namespace std;
//Home work

void showArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
}

void initializeArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> *(arr + i);
	}
}

int getCountEven(int* arr, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			count++;
		}
	}
	return count;
}

int* deleteValues(int* arr, int size, bool choice) 
{
	int n;
	if (choice == true)
	{
		n = size - getCountEven(arr, size); 
	}
	else 
	{
		n = getCountEven(arr, size);
	}
	int* newArr = new int[n];

	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (choice && arr[i]%2!=0)
		{
			newArr[j] = arr[i];
			j++;
		}
		else if(choice==false && arr[i]%2==0)
		{
			newArr[j] = arr[i];
			j++;
		}
	}
	showArray(newArr, n);
	return newArr;
}

void quickSort(int arr[], int size)
{
	long left = 0, right = size;
	int temp, middle;
	middle = arr[size / 2];
	do {
		while (arr[left] < middle)
		{
			left++;
		}
		while (arr[right] > middle)
		{
			right--;
		}
		if (left <= right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (right > 0) quickSort(arr, right);
	if (size > left) quickSort(arr + left, size - left);
}

int main()
{
	const int N= 10;
	int arr[N] = { 4,3,5,3,6,-10,3,5,2,99 };
	quickSort(arr, N-1);
	showArray(arr, N);
	
	cout << "Hello. There was Nazar)";
	


	return 0;

}

#include <iostream>

using namespace std;

int loopNum = 0;

template <typename Type>
void quickSort(Type* desiredArray, int sizeOfArray, int pivotLocation = 1, int locationPtr = 0, bool ascending = false)
{
	if (loopNum == 2)
	{
		return;
	}

	Type pivot = desiredArray[pivotLocation];

	while (locationPtr < pivotLocation)
	{
		if (desiredArray[locationPtr] > pivot)
		{
			desiredArray[pivotLocation] = desiredArray[locationPtr];

			pivotLocation--;

			desiredArray[locationPtr] = desiredArray[pivotLocation];
			desiredArray[pivotLocation] = pivot;
		}
		else if (desiredArray[locationPtr] < pivot)
		{
			locationPtr++;
		}
		else
		{
			;
		}
	}
	loopNum++;

	if (loopNum == 1)
	{
		int lessThanSize = pivotLocation;
		quickSort(desiredArray, sizeOfArray, lessThanSize - 1);
	}
	else if (loopNum == 2)
	{
		int greaterThanSize = sizeOfArray - pivotLocation - 1;
		quickSort(desiredArray, sizeOfArray, sizeOfArray - 1, greaterThanSize - 1);
	}
}

int main()
{
	const int ARRAY_SIZE = 9;
	int myArray[ARRAY_SIZE] = { 3, 7, 8, 5, 2, 1, 9, 5, 4 };

	quickSort(myArray, ARRAY_SIZE, ARRAY_SIZE - 1);

	for (int z = 0; z < ARRAY_SIZE; z++)
	{
		cout << myArray[z] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
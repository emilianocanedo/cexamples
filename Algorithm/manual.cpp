#include <iostream>
#include <array>

void BubbleSort(int* array, int n)
{
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<n-1; y++)
		{
			if(array[y]>array[y+1])
			{
				int temp = array[y+1];
				array[y+1] = array[y];
				array[y] = temp;
			}
		}
	}
}

int main()
{
	int array[7] = { 4, 9, 76, 34, 2, 2, 3 };

	BubbleSort(array, 7);

	for (int item : array)
		std::cout << item << std::endl;
}
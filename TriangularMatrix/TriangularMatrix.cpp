#include <iostream>

int main()
{
    int** TriangularMatrix;
	TriangularMatrix = new int*[5];

	for (int r = 0; r < 5; ++r)
	{
		*(TriangularMatrix+r) = new int[r+1];
		
		for (int c = 0; c < r; ++c)
		{
			TriangularMatrix[r][c] = c+1;
		}
	}

	for (int r = 0; r < 5; ++r)
	{	
		for (int c = 0; c < r; ++c)
		{
			std::cout << *(*(TriangularMatrix+r)+c);	
		}

		std::cout << std::endl;
	}

	for (int r = 0; r < 5; ++r)
	{
		delete[] TriangularMatrix[r];
	}
	delete TriangularMatrix;

	return 0;
}
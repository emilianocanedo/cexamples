#include <iostream>

int Factorial(int integer)
{
	if (integer == 1)
    	return 1;
	else
        return (integer * (Factorial(integer-1)));
} 

int Fibonacci(int n) 
{ 
	if (n==0)
		return 0; 
	if (n==1)
		return 1; 
	
	return( Fibonacci(n-2) + Fibonacci(n-1) ); 
}

bool IsPrime(int p, int i=2) 
{ 
	if (i==p) 
		return 1;
	if (p%i == 0) 
		return 0;

	return IsPrime (p, i+1); 
}

int main()
{
	std::cout << Factorial(5) << std::endl;
	std::cout << Fibonacci(7) << std::endl;
	std::cout << IsPrime(47) << std::endl;
}
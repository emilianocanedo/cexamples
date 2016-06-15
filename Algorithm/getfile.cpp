// Get character by character
#include <iostream>
#include <fstream> 

int main () 
{
	char str[256];

  	std::cout << "Enter the name of an existing text file: ";
  	std::cin.get(str, 256);

  	std::ifstream is(str);

  	std::string word;
  	char c;

  	while (is.get(c)) //loop getting single characters
  	{
    	if (c == ';') {
    		std::cout << word << std::endl;
    		word.clear();
    	} else {
    		word.push_back(c);
    	}
  	}

	is.clear();
	is.seekg(0, is.beg);

	while (getline(is, word))
	{
    	is >> word;
	}

	std::cout << word << std::endl;
  	is.close();

  	return 0;
}
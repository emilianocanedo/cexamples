#include <iostream>
#include <vector>
#include <string>
#include <functional>

int Length(std::string param)
{
    int output = param.length();
    std::cout << param << std::endl;
    std::cout << output << std::endl;
    return output;
}

template<class A, class B>
std::function<std::vector<A>(std::vector<B>)> fmap(std::function<A(B)> function)
{
    //Lambda expression
    return [function](std::vector<B> list) { 
        std::vector<A> output;
        for (B item : list) {
            output.push_back(function(item));
        }
        return output;
    };
}

int main()
{
    std::vector<std::string> VectorString = {"pepe", "bar", "foo", "foobar"};
    std::vector<int> VectorInt = fmap<int, std::string>(Length)(VectorString);
}
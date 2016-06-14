#include <iostream>
#include <list>

template<class Type>
class MyList
{
private:
    std::list<Type> myList;
    
public:
    void Add(Type element)
    {
        myList.push_back(element);   
    }
    
    void Print()
    {
        for(Type item : myList)
        {
            std::cout << item << std::endl;   
        }
    }
};

int main()
{
   MyList<int> instance;
   instance.Add(34);
   instance.Add(23);
   instance.Add(12);
   
   instance.Print();
}
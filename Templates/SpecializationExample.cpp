#include <iostream>
#include <list>

// mylist.h

template<class Type>
class MyList
{
private:
    std::list<Type> myList;
    
public:
    void Add(Type element);
    void Print();
};

// mylist.cpp

template<class Type>
void MyList<Type>::Add(Type element)
{
    myList.push_back(element);   
}
    
template<class Type>
void MyList<Type>::Print()
{
    for(Type item : myList)
    {
        std::cout << item << std::endl;   
    }
}

template<>
void MyList<int>::Print()
{    
    for(int item : myList)
    {
        std::cout << "I'm an integer" << std::endl;
        std::cout << item << std::endl;   
    }
}

// main.cpp

int main()
{
   MyList<int> instance;
   instance.Add(34);
   instance.Add(23);
   instance.Add(12);
   
   instance.Print();
   
   MyList<float> instance2;
   instance2.Add(34);
   instance2.Add(23);
   instance2.Add(12);
   
   instance2.Print();
}
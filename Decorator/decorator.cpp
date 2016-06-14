#include <iostream>

class Computer 
{
public:

    virtual float CalculateCost() = 0;
    
    virtual ~Computer()
    {
        std::cout << "Computer Destructor" << std::endl;   
    }
};

class BaseComputer : public Computer
{
public:  

    float CalculateCost()
    {
        return 4;
    }
    
    ~BaseComputer()
    {
        std::cout << "BaseComputer Destructor" << std::endl;    
    }
};

class Ram : public Computer
{
    Computer* currentComputer;
    
public:

    Ram(Computer* current)
    {
        this->currentComputer = current;   
    }
    
    float CalculateCost()
    {
        return currentComputer->CalculateCost() + 45;
    }
    
    ~Ram()
    {
        std::cout << "Ram Destructor" << std::endl;
        delete currentComputer;
    }
};

class Cpu : public Computer
{
    Computer* currentComputer;
    
public:

    Cpu(Computer* current)
    {
        this->currentComputer = current;   
    }
    
    float CalculateCost()
    {
        return currentComputer->CalculateCost() + 34;
    }
    
    ~Cpu()
    {
        std::cout << "Cpu Destructor" << std::endl;
        delete currentComputer; 
    }
};

int main()
{
    Computer* PC = new BaseComputer();
    PC = new Ram(PC);
    PC = new Cpu(PC);
    
    std::cout << PC->CalculateCost();
    
    delete PC;
}
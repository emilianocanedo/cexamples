#include <iostream>

using namespace std;

class SuperClass
{
public:
	SuperClass() { cout << "Hi SuperClass" << endl; };
	void Print() { cout << "I'm SuperClass" << endl; };
	virtual ~SuperClass() { cout << "Bye SuperClass" << endl; };
};

class DerivedClass : public SuperClass
{
public:
	DerivedClass() { cout << "Hi DerivedClass" << endl; };
	void Print() { cout << "I'm DerivedClass" << endl; };
	~DerivedClass() { cout << "Bye DerivedClass" << endl; };
};

int main()
{
	cout << "####### SuperClass -> DerivedClass" << endl;

	SuperClass *ptr = new DerivedClass();
	ptr->Print();
	delete ptr;

	cout << "####### SuperClass *" << endl;

	SuperClass *ptr2 = new SuperClass();
	ptr2->Print();
	delete ptr2;

	cout << "####### DerivedClass *" << endl;

	DerivedClass *ptr3 = new DerivedClass();
	ptr3->Print();
	delete ptr3;

	cout << "####### SuperClass -> DerivedClass[]" << endl;

	SuperClass *ptr4 = new DerivedClass[5]();
	ptr4[0].Print();
	delete [] ptr4;

	cout << "####### DerivedClass" << endl;

	DerivedClass derived;
	derived.Print();

	cout << "####### SuperClass" << endl;

	SuperClass super;
	super.Print();
}

/*NOTAS DE HERENCIA:
1 - El destructor del padre siempre debe ser virtual. 
De esta manera, se hace el llamado al destructor del hijo cuando la clase padre es utilizada como puntero a una instancia/s del hijo.

2 - Si la clase padre tiene constructor, siempre son llamados ambos, el del hijo y el del padre

3 - Si los metodos de la clase padre no son virtuales, seran llamados cuando se use un puntero de la misma hacia 
la clase derivada (ej. SuperClass *ptr = new DerivedClass();). 
Solo seran llamados los metodos de la clase derivada cuando la instancia y/o puntero sean exclusivamente de la misma 
(ej. DerivedClass *ptr3 = new DerivedClass();)

4 - Una instancia hija, siempre invoca al constructor padre, al de ella misma.
*/


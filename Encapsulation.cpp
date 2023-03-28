#include <string>
#include <iostream>
using namespace std;
class Car {

	//lexical Scope
private:
	string color;
	int capacity;
	string vin;
public:
	//mutators
	//void setColor(str colorArg,const Car* this)
	void setColor(string colorArg) {

		this->color = colorArg;
	}
	string getColor() {
		return this->color;
	}

	//Constructor - Default Constructor , Zero Length Argument Based Constructor , 'has this'
	Car() {
		//Constraints (Obejct Variance Rules)
		//initialization Code 
		//pre Conditions
	}
};

class BankCustomer {

private:
	string name, adhar, panNumber, phoneNumber, emailAddress;
	int age;
public:

	//Function Overloading  (Compliletime Polymorphism)
	BankCustomer(string nameArg, string adharArg, string panNumberArg, int ageArg) {
		//validate the arguments
		this->name = nameArg;
		this->adhar = adharArg;
		this->panNumber = panNumberArg;
		this->age = ageArg;
	}

	BankCustomer(string nameArg, string adharArg, string panNumberArg, int ageArg, string phoneNumberArg, string emailAddressArg) {
		//validate the arguments
		this->name = nameArg;
		this->adhar = adharArg;
		this->panNumber = panNumberArg;
		this->age = ageArg;
		this->phoneNumber = phoneNumberArg;
		this->emailAddress = emailAddressArg;

	}
	string getName() {
		return this->name;
	}

	~BankCustomer() {
		//Destructor
		//Object Cleanup Code 
	}

};



int main()
{
	Car carObject; //stack allocation
	Car* ptrToCarObject = new Car(); // heap Allocation
	carObject.setColor("white"); // Car::setColor("white",carObject);
	ptrToCarObject->setColor("Blue");
	cout << carObject.getColor() << endl << ptrToCarObject->getColor();

	BankCustomer tomObjRef("Tom", "ADYPFFFFFF", "ASE45678", 32);//Static Binding
	cout << tomObjRef.getName() << endl;;
	BankCustomer haryObjRef("Hary", "ADYPFFFFFF", "ASE45678", 32, "123456788", "tom@bosch.in");//Static Binding
}


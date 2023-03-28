#include <string>
#include <iostream>
using namespace std;
//abstract class
class Vehicle {
private:string name;
public:
	//closed Method
	void reverse() {

	}
	//open method
	virtual void start() {
	cout << "Vehicle Started using Key" << endl;
    }
	//open method
	public:virtual void stop() {
	cout << "Vehicle Stoped using Key" << endl;
	}
	virtual void drive() = 0;//template method , abstract method , pure virtual method
};
class Car:public Vehicle {
public:
	void drive() {
		cout << "Car Front Wheel Drive" << endl;
	}
	void start() {
		cout << "Vehicle Started using PushButton Start" << endl;
	}
	void stop() {
		cout << "Vehicle Stoped using PushButton Stop" << endl;
	}
};

class Truck :public Vehicle{
	void drive() {
		cout << "Truck : Rear Wheel Drive" << endl;
	}
};

class Bus:public Vehicle {
	void drive() {
		cout << "Bus : Rear Wheel Drive" << endl;
	}
};

class VehicleSimulator {
public:
	void start_vehicle() {

	}
	void stop_vehicle() {}
	void start_drive(){}
};

int main() {

}

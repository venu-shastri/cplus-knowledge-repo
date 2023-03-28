#include <string>
#include <iostream>
using namespace std;

class IMotorVehicle {
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void drive() = 0;
};
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
class Car:public Vehicle,public IMotorVehicle {
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

class Truck :public Vehicle,public IMotorVehicle{
	void drive() {
		cout << "Truck : Rear Wheel Drive" << endl;
	}
	void start() {
		Vehicle::start();
	}
	void stop() {
		Vehicle::stop();
	}
};

class Bus:public Vehicle,public IMotorVehicle {
	void drive() {
		cout << "Bus : Rear Wheel Drive" << endl;
	}
};

class VehicleSimulator {
	//has-a or depends-on abstarction of vehicles
private: IMotorVehicle* vehicleRef = nullptr;
public:
	VehicleSimulator(IMotorVehicle* vehicleAddress):vehicleRef(vehicleAddress) {

	}
	void set_vehicle(IMotorVehicle* vehicleRef) {
		this->vehicleRef = vehicleRef;
	}
	void start_vehicle() {
		this->vehicleRef->start();
	}
	void stop_vehicle() {
		this->vehicleRef->stop();
	}
	void start_drive(){
		this->vehicleRef->drive();
	}
};

int main() {

	VehicleSimulator _simulator(new Car());
	_simulator.start_vehicle();
	_simulator.start_drive();
	_simulator.stop_vehicle();

	_simulator.set_vehicle(new Truck());
	_simulator.start_vehicle();
	_simulator.start_drive();
	_simulator.stop_vehicle();
	
}



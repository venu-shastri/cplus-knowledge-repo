class Employee {

private: string name, id, bloodGroup;
public:
	Employee(string nameArg,string idArg,string bgArg) {
		cout << "Empployee Constructor Invoked" << endl;
	}

};

class ContractEmployee : Employee {
private: int noOFHours, rateCard;
public:ContractEmployee(
	int noOFHoursArg,
	int  rateCardArg,
	string nameArg,
	string idArg,
	string bgArg) :Employee(nameArg, idArg, bgArg){
	this->noOFHours = noOFHoursArg;
	this->rateCard = rateCardArg;
	cout << "ContractEmployee Constructor Invoked" << endl;
}

};

class PermanentEmployee :Employee {
public:
	PermanentEmployee(
		float ctcArg,
		float daArg,
		float hraArg,
		string nameArg,
		string idArg, 
		string bgArg):Employee(nameArg,idArg,bgArg) {
		this->CTC = ctcArg;
		this->da = daArg;
		this->hra = hraArg;
		cout << "PermanentEmployee Constructor Invoked" << endl;
	}

private:

	float CTC, da, hra;


};

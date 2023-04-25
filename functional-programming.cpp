#include <iostream>
#include<string>
#include<vector>
#include<memory>
#include <thread>
#include <functional>
using namespace std;

//predicate
auto isStringLengthGreaterThanQuntifier(int maxlength) {

	auto predicate = [maxlength](string item)->bool {
		return item.length() > maxlength;
	};
	return predicate;

}

vector<string> query(string source[], function<bool(string)> predicate) {
	vector<string> result;
	for (int i = 0; i < 4; i++) {
		if (predicate(source[i])) {
			result.push_back(source[i]);
		}
	}
	return result;
}


int main() {
	//1.source
	//2.interator
	//3.predicate/s : condition
	string names[4] = { "Bosch","Bangalore","Mysore","Chennai" };
	auto predicate = isStringLengthGreaterThanQuntifier(3);
	vector<string> result = query(names, predicate);
	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) << endl;
	}

	auto predicate2 = isStringLengthGreaterThanQuntifier(6);
	result = query(names, predicate2);
	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) << endl;
	}

	

}

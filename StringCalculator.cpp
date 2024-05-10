#include<iostream>
#include<string>

using namespace std;
class GetNegatives {
private:
	string negatives;

public:
	void operator()(int i) {
		if (i < 0)
			negatives.append(to_string(i) + ",");
	}

	operator string() {
		if (negatives.length() > 0)
			negatives.pop_back();

		return negatives;
	}
};

void check_for_negatives(const vector<int> &numbers) {
	string negatives = for_each(numbers.begin(), numbers.end(), GetNegatives());

	if (negatives.size() > 0) {
		throw invalid_argument("Negatives not allowed: " + negatives);
	}
}

void add_if_valid(vector<int> &numbers, string number_string) {
	int number = stoi(number_string);
	if (number <= 1000)
		numbers.push_back(number);
}

vector<int> get_numbers(const string &input) {
	regex numbers_only("(-?\\d+)+");

	vector<int> numbers;
	for_each(sregex_token_iterator(input.begin(), input.end(), numbers_only),
				sregex_token_iterator(),
				[&numbers](string s) { add_if_valid(numbers, s); });

	return numbers;
}
class StringCalculator{
    public:
    int add(string input){
        if (input.empty())
		return 0;

	vector<int> numbers = get_numbers(input);

	check_for_negatives(numbers);

	return accumulate(numbers.begin(), numbers.end(), 0);
    }
};

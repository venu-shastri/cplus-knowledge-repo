#include <string>
#include <iostream>
using namespace std;

class TextBox {
private :
	string content;
public:
	void onKeyPress(int scanCode){
		cout << "TextBox Accepts Al type of values" << endl;
	}
	void clear(){
		cout << "TextBox Content Cleared" << endl;
	}
	void focus() {
		cout << "TextBox Received Focus" << endl;
	}
};

class NumericTextBox :public TextBox{
public:
	void onKeyPress(int scanCode) {
		//accept numeric values and set content
		//New Behavior
		cout << "TextBox Accepts Numeric Values" << endl;
	}
};

int main() {
	NumericTextBox numericTextBoxobj;
	numericTextBoxobj.focus();
	numericTextBoxobj.onKeyPress(12);
	numericTextBoxobj.clear();
	


	TextBox  textBoxObj;
	textBoxObj.focus();
	textBoxObj.onKeyPress(1234);
	textBoxObj.clear();
}

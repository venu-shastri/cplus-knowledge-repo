#include <iostream>
#include <vector>

class Device {
private :
     //Braces can also be used to specify default initialization values for non - static data members
        
    int deviceId {0};
    int price = 0;
    //Not Allowed
    //int code(0);
   
public:

    Device() {  // default ctor
        std::cout << "Device()" << std::endl;
    };
    Device(int id) {

    }

    Device(std::initializer_list<int> il) {  // std::init_list ctor
        std::cout << "Device(std::initializer_list<int>)" << std::endl;
    };

    // ...                                   // no implicit
                                             // conversion funcs
};

int main() {

	/* “confusing mess”
	int x(0); // initializer is in parentheses
	int y = 0; // initializer follows "="
	int z{ 0 }; // initializer is in braces
	int z = { 0 }; // initializer uses "=" and braces

	Device d1; // call default constructor
	Device d2 = d1; // not an assignment; calls copy ctor
	d1 = d2; // an assignment; calls copy operator=
	*/

	Device d1;    // calls default ctor

	Device d2{};  // also calls default ctor

	Device d3();  // most vexing parse! declares a function!

	Device d4({});  // calls std::init_list ctor
					// with empty list

	Device d5{ {} };  // ditto

	//A novel feature of braced initialization is that it prohibits implicit narrowing conversions among built - in types
	double x, y, z;

   //int sum1{ x + y + z }; // error! sum of doubles may  not be expressible as int
	return 0;
}

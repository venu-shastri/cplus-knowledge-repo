class Point {
private :
	int x, y;
public:
	Point(int xValue, int yValue) :x{ xValue }, y{ yValue }{
	
		std::cout << "Point Resource Created" << std::endl;
	}
	void print() {
		std::cout << "Hello" << std::endl;
	}
	friend std::ostream& operator <<(std::ostream& out, const Point& instance) {
		out << instance.x << ',' << instance.y;
		return out;
	}
	~Point() {
		std::cout << "Point Resource Destroyed" << std::endl;
	}
};

template<typename T>
class SmartPointer {

	T* ptr;
public:
	SmartPointer(T* ptrArg=nullptr) :ptr{ ptrArg } {

	}
	~SmartPointer() {
		delete ptr;
	}
	T& operator*() const {
		return *ptr;
	}
	T* operator->() const {
		return ptr;
	}
	// A copy constructor that implements move semantics
	SmartPointer(SmartPointer& source) {
		ptr = source.ptr;//transfer our dumb pointer from the source to our local object
		source.ptr = nullptr; // make sure the source no longer owns the pointer
	}
	// An assignment operator that implements move semantics
	SmartPointer& operator=(SmartPointer& source) // note: not const
	{
		if (&source == this) {
			return *this;
		}

		delete ptr; // make sure we deallocate any pointer the destination is already holding first
		ptr = source.ptr; // then transfer our dumb pointer from the source to the local object
		source.ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}
	bool isNull() const { return ptr == nullptr; }

};

//Pass By Value
void passSmartPointerAsArgument(SmartPointer<Point> ref) {


}


int main()
{
 

  Point* ptr = new Point { 10,20 };

  SmartPointer<Point> res1(new Point{ 10,20 });
  SmartPointer<Point> res2;


  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

  res2 = res1; // res2 assumes ownership, res1 is set to null

  std::cout << "Ownership transferred\n";

  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
  passSmartPointerAsArgument(res1);
 res1->print();

 
  

}

#include<iostream>
class myclass {
	static int objectcount;
	public:
		myclass(){
			++objectcount;
		}
		static void showcount(){
			std::cout << " number of objects created: " << objectcount <<std::endl;
			
		}
};
int myclass::objectcount = 0;
int main(){
	myclass obj1;
	myclass obj2;
	myclass obj3;
	myclass::showcount();
	return 0;
}

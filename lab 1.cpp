#include<iostream>
class myclass{
	private:
		static int count;
		public:
			myclass() {
				count++;
			}
			static void showcount(){
				std::cout << " number of the objects created: "<<count << std::endl;
				
			}
};
int myclass :: count = 0;
int main(){
	myclass obj1;
	myclass obj2;
	myclass obj3;
	myclass::showcount();
	return 0;
}

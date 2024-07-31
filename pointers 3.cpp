#include <iostream>
using namespace std;
int main(){
	double num=3.14592653;
	double *ptr=&num;
	cout<<"Value of num: "<<num<<endl;
	cout<<"Address of num: "<<ptr<<endl;
	cout<<"Value of *ptr: "<<*ptr<<endl;	
}

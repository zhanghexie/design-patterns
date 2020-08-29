#include<iostream>
#include<vector>
using namespace std;
class A{
    public:
	static int a;
        virtual void fun(){
            cout<<"A.fun()"<<endl;
        }
};
int A::a = 0;
class B:public A{
    public:
        void fun(){
            cout<<"B.fun()"<<endl;
        }
};
int main(){
    A a = B();
    a.fun();
    cout<<A::a<<endl;
}


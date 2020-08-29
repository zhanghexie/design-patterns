#include<iostream>
using namespace std;

// 特殊类，需要被适配。
class Adaptee{
	public:
		virtual void specific_request(){
			cout<<"特殊请求"<<endl;
		}
};

// 客户端所需要的接口
class Target{
	public:
		void request(){
			cout<<"普通请请求"<<endl;
		}
};

// 适配器
class Adapter:public Target{
	private:
		Adaptee *adaptee=nullptr;
	public:
		void request(){
			this->adaptee->specific_request();
		}
		
		Adapter(){
			this->adaptee = new Adaptee();
		}

		Adapter(Adaptee* adaptee){
			this->adaptee=adaptee;
		}

};

int main(){
	Adapter a;
	a.request();
	return 0;
}

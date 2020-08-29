/*
 * 职责链模式
 * 张鹤轩
 * 2020-8-17
 * */

#include<iostream>
using namespace std;

// 定义一个处理请示的接口。
class Hander{
	protected:
		Hander* successor;
	public:
		void set_successor(Hander* successor){
			this->successor=successor;
		}
		virtual void handle_request(int request){}
};

// 具体处理者1
class ConcreteHander1:public Hander{
	public:
		void handle_request(int request){
			if(request<10){
				cout<<"处理者1来解决此问题。"<<endl;
			}else if(nullptr!=successor) {
				successor->handle_request(request);
			}else{
				cout<<"对不起，无法处理此问题，也没有上级可以处理！！！"<<endl;
			}
		}
};

// 具体处理者2
class ConcreteHander2:public Hander{
	public:
		void handle_request(int request){
			if(request<20){
				cout<<"处理者2来解决此问题。"<<endl;
			}else if(nullptr!=successor) {
				successor->handle_request(request);
			}else{
				cout<<"对不起，无法处理此问题，也没有上级可以处理！！！"<<endl;
			}
		}
};

// 具体处理者3
class ConcreteHander3:public Hander{
	public:
		void handle_request(int request){
			cout<<"小弟都不行了，还是大哥来吧！"<<endl;
		}
};

int main(){
	Hander *h1 = new ConcreteHander1();
	Hander *h2 = new ConcreteHander2();
	Hander *h3 = new ConcreteHander3();
	
	h1->set_successor(h2);
	h2->set_successor(h3);

	int a[]={8,6,17,45,20,100};
	for (int i=0;i<sizeof(a)/sizeof(*a);i++){
		h1->handle_request(a[i]);
	}
	return 0;
}

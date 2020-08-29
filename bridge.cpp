/*
 * 桥接模式
 * 张鹤轩
 * 2020-8-16
 * */

#include <iostream>
using namespace std;

// 实现的抽象类
class Implementor{
	public:
		virtual void operation(){
			cout<<"抽象实现"<<endl;
		}
};

// 具体实现类A
class ConcreteImplementorA:public Implementor{
	public:
		void operation(){
			cout<<"具体实现A。"<<endl;
		}
};

// 具体实现类B
class ConcreteImplementorB:public Implementor{
	public:
		void operation(){
			cout<<"具体实现B。"<<endl;
		}
};

// 抽象
class Abstraction{
	protected:
		Implementor* implementor;
	public:
		Abstraction(){}
		void set_implementor(Implementor* implementor){
			this->implementor=implementor;
		}
		virtual void operation(){};
};

// 被提炼的抽象
class RedefineAbstriaction:public Abstraction{
	public:
		void operation(){
			this->implementor->operation();
		}
};


int main(){
	Abstraction *a = new RedefineAbstriaction();
	a->set_implementor(new ConcreteImplementorA());
	a->operation();
	a->set_implementor(new ConcreteImplementorB());
	a->operation();
	return 0;
}

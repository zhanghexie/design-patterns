/*
 * 访问者模式
 * 张鹤轩
 * 2020-8-18
 * */

#include <iostream>
#include <string>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

// 抽象访问者
class Visitor{
	public:
		virtual void visit_concrete_element_a(ConcreteElementA *concreteElementA)=0;
		virtual void visit_concrete_element_b(ConcreteElementB *concreteElementB)=0;
};

// 抽像元素
class Element{
	public:
		virtual void accept(Visitor* vistor)=0;
};

// 具体元素A
class ConcreteElementA:public Element{
	public:
		void accept(Visitor *vistor){
			vistor->visit_concrete_element_a(this);
		}
		string operation(){
			return "欢迎参观A！！！";
		}
};

// 具体元素B
class ConcreteElementB:public Element{
	public:
		void accept(Visitor *vistor){
			vistor->visit_concrete_element_b(this);
		}
		string operation(){
			return "欢迎参观B！！！";
		}
};

// 具体观察者1
class ConcreteVistor1:public Visitor{
	public:
		void visit_concrete_element_a(ConcreteElementA *concreteElementA){
			cout<<"具体访问者1访问A，看到"<<concreteElementA->operation()<<endl;
		}
		void visit_concrete_element_b(ConcreteElementB *concreteElementB){
			cout<<"具体访问者1访问A，看到"<<concreteElementB->operation()<<endl;
		}
};


// 具体观察者2
class ConcreteVistor2:public Visitor{
	public:
		void visit_concrete_element_a(ConcreteElementA *concreteElementA){
			cout<<"具体访问者2访问A，看到"<<concreteElementA->operation()<<endl;
		}
		void visit_concrete_element_b(ConcreteElementB *concreteElementB){
			cout<<"具体访问者2访问A，看到"<<concreteElementB->operation()<<endl;
		}
};


int main(){
	ConcreteElementA *ea = new ConcreteElementA();
	ConcreteElementB *eb = new ConcreteElementB();
	Visitor *v1 = new ConcreteVistor1();	
	Visitor *v2 = new ConcreteVistor2();	
	v1->visit_concrete_element_a(ea);
	v1->visit_concrete_element_b(eb);
	v2->visit_concrete_element_a(ea);
	v2->visit_concrete_element_b(eb);
	return 0;
}

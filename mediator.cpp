/*
 * 中介者模式
 * 张鹤轩
 * 2020-8-17
 * */

#include <iostream>
#include <set>
#include <string>
using namespace std;

class Colleague;

// 中介者类，定义了同事对象到中介者对象的接口。
class Mediator{
	public:
		virtual void send(string message, Colleague* colleague)=0;	
		virtual void add_colleague(Colleague* colleague)=0;
};

// 抽象同时类
class Colleague{
	protected:
		string name;
		Mediator* meditor;
	public:
		Colleague(Mediator *meditor,string name){
			this->name = name;
			this->meditor = meditor;
		}
		void send(string message){
			this->meditor->send(message,this);
		}
		virtual void notify(string message){}
		virtual void add_to_mediator(){}
};

// 具体的同事类
class ConcreteColleague:public Colleague{
	public:
		ConcreteColleague(Mediator *meditor,string name):Colleague(meditor,name){
			this->add_to_mediator();
		}
		void notify(string message){
			cout<<name<<"收到消息："<<message<<endl;
		}
		void add_to_mediator(){
			this->meditor->add_colleague(this);
		}
};

// 具体的中介者
class ConcreteMeditor:public Mediator{
	private:
		set<Colleague*> colleagues;
	public:
		void add_colleague(Colleague *colleague){
			colleagues.insert(colleague);
		}
		void send(string message, Colleague* colleague){
			for(set<Colleague*>::iterator it = colleagues.begin();it!=colleagues.end();it++){
				if (colleague!=*it){
					(*it)->notify(message);
				}
			}

		}

};

int main(){
	Mediator* m = new ConcreteMeditor();
	Colleague* c1 = new ConcreteColleague(m,"c1");	
	Colleague* c2 = new ConcreteColleague(m,"c2");	
	Colleague* c3 = new ConcreteColleague(m,"c3");	
	c1->send("大家好！！我是C1。");
	cout<<"============"<<endl;
	c2->send("大家好！！我是C2。");
	cout<<"============"<<endl;
	c3->send("大家好！！我是C3。");
	return  0;
}

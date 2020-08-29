/*
 * 享元模式
 * 张鹤轩
 * 2020-8-17
 * */

#include<iostream>
#include <iterator>
#include <unordered_map>
#include <string>
using namespace std;

// 具体享元类的接口
class Flyweight{
	public:
		Flyweight(){}
		Flyweight(string name){}
		virtual void operation(int extrinsictate)=0;
};

// 具体的享元类
class ConcreateFlyweight:public Flyweight{
	private:
		string name;
	public:
		ConcreateFlyweight(string name){
			this->name=name;
		}
		void operation(int extrinsictate){
			cout<<"具体的Flyweight,"<<name<<",状态："<<extrinsictate<<endl;
		}
};

// 不需要共享的Flyweight
class UnshareConcreateFlyweight:public Flyweight{
	public:
		void operation(int extrinsictate){
			cout<<"不公共享的具体的Flyweight,状态："<<extrinsictate<<endl;
		}
};

// 享元工厂用来创建并管理Flyweight对象。
class FlyweightFactory{
	private:
		unordered_map<string,Flyweight*> flyweights;
	public:
		FlyweightFactory(){
			this->flyweights.insert(pair<string,Flyweight*>("x",new ConcreateFlyweight("x")));
			this->flyweights.insert(pair<string,Flyweight*>("y",new ConcreateFlyweight("y")));
			this->flyweights.insert(pair<string,Flyweight*>("z",new ConcreateFlyweight("z")));
		}

		Flyweight* get_flyweight(string key){
			return flyweights[key];
		}


};
int main(){
	int i = 20;
	FlyweightFactory f;
	Flyweight* fx1 = f.get_flyweight("x");
	fx1->operation(--i);
	Flyweight* fx2 = f.get_flyweight("x");
	fx2->operation(--i);
	Flyweight* fy = f.get_flyweight("y");
	fy->operation(--i);
	Flyweight* fz = f.get_flyweight("z");
	fz->operation(--i);

	UnshareConcreateFlyweight* uf = new UnshareConcreateFlyweight();
	uf->operation(i);
	return 0;
}

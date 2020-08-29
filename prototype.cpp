/*
* 原型模式
* 张鹤轩
* 2020-8-6
*/

#include<iostream>
#include<string>
using namespace std;

// 原型类，声明一个克隆自身的接口。
class Prototype{
    private:
        string id;
    public:
        Prototype(string id){
            this->id = id;
        }
        Prototype(){} // 子类有无参数构造方法，父类必须有。
        string get_id(){
            return this->id;
        }
        virtual Prototype* clone()=0;
};

// 具体的原型类
class ConcretePrototype:public Prototype{
    public:
        ConcretePrototype(string s):Prototype(s){} // 使用父类构造方法。
        ConcretePrototype(){} // 创建无参数构造方法
        Prototype* clone(){
            ConcretePrototype* p = new ConcretePrototype();
            *p = *this;
            return p;
        }

};
int main(){
    Prototype* c = new ConcretePrototype("s1");
    cout<<c->get_id()<<endl;
    Prototype* b = c->clone();
    cout<<b->get_id()<<endl;

}
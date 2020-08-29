/*
* 装饰模式
* 张鹤轩
* 2020-8-3
*/

#include<iostream>
using namespace std;

// 定义一个对象接口，可以给这些对像动态的添加职责。
class Component{
    public:
        virtual void operation(){}
};

// 定义了一个具体的对象，也可以给对象添加一些职责。
class ConcreteComponent:public Component{
    public:
        void operation(){
            cout<<"这是一个具体的操作"<<endl;
        }
};

// 装饰抽象类，继承Compontent，从外类扩展它。
class Decorator:public Component{
    protected:
        Component* component;
    
    public:
        void setComponent(Component* component){
            this->component=component;
        }
        
        void operation(){
            if (this->component != NULL){
                this->component->operation();
            }
        }
};

// 具体Decorator类，起到给Component添加职责的作用。
class ConcreteDecoratorA:public Decorator{
    public:
        void operation(){
            AddedBehavior();
            Decorator::operation();
            AddedBehavior();
        }
    private:
        void AddedBehavior(){
            cout<<"aaaaaa"<<endl;
        }
};

// 具体Decorator类，起到给Component添加职责的作用。
class ConcreteDecoratorB:public Decorator{
    public:
        void operation(){
            AddedBehavior();
            Decorator::operation();
            AddedBehavior();
        }
    private:
        void AddedBehavior(){
            cout<<"bbbbbbbb"<<endl;
        }
};

// 客户端
int main(){
    cout<<"\n\n=========="<<endl;
    ConcreteComponent c;
    c.operation();


    cout<<"\n\n=========="<<endl;
    ConcreteDecoratorA da;
    da.setComponent(&c);
    da.operation();
    
    cout<<"\n\n=========="<<endl;
    ConcreteDecoratorB db;
    db.setComponent(&da);
    db.operation();

    return 1;
}
#include<iostream>
using namespace std;

// 抽象模板
class AbstractClass{
    public:
        // 一些抽象行为，放到子类去实现。
        virtual void primitive_operation1()=0;
        virtual void primitive_operation2()=0;

        // 方法的步骤。
        void TemplateMethod(){
            this->primitive_operation1();
            this->primitive_operation2();
        }
};

// 具体实现类A
class ConcreteClassA:public AbstractClass{
    public:
        // A具体的操作1。
        void primitive_operation1(){
            cout<<"A的操作1"<<endl;
        }
        
        // A具体的操作2。
        void primitive_operation2(){
            cout<<"A的操作2"<<endl;
        }
};

// 具体实现类B
class ConcreteClassB:public AbstractClass{
    public:
        // B具体的操作1。
        void primitive_operation1(){
            cout<<"B的操作1"<<endl;
        }

        // B具体的操作2。
        void primitive_operation2(){
            cout<<"B的操作2"<<endl;
        }
};

int main(){
    AbstractClass* a;
    
    a = new ConcreteClassA();
    a->TemplateMethod();

    a = new ConcreteClassB();
    a->TemplateMethod();

}
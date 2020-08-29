#include<iostream>
using namespace std;


// 子系统1
class SubSystem1{
    public:
        void method1(){
            cout<<"子系统方法1"<<endl;
        }
};

// 子系统2
class SubSystem2{
    public:
        void method2(){
            cout<<"子系统方法2"<<endl;
        }
};

// 子系统3
class SubSystem3{
    public:
        void method3(){
            cout<<"子系统方法3"<<endl;
        }
};


// 外观类，知道哪些子系统负责处理请求，将客户端的请求代理给适当子系统对象。
class Facade
{
    public:
        // 外观类需要了解所有子系统的方法和属性，进行组合，以备外界调用。
        SubSystem1 *one;
        SubSystem2 *two;
        SubSystem3 *three;

        Facade(){
            this->one = new SubSystem1();
            this->two = new SubSystem2();
            this->three = new SubSystem3();
        }

        void method_a(){
            this->one->method1();
            this->two->method2();
            this->three->method3();
        }

        void method_b(){
            this->three->method3();
            this->one->method1();
            this->two->method2();
        }
};

// 客户端
int main(){
    Facade f;
    cout<<"method_a:"<<endl;
    f.method_a();
    cout<<"method_b:"<<endl;
    f.method_b();
    return 1;
}
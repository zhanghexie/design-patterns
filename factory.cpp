/*
* 工厂模式
* 张鹤轩
* 2020-8-5
*/ 
#include<iostream>
using namespace std;

// 运算父类
class Operator {
    private:
        double _numberA;
        double _numberB;
    public:
        double getA(){
            return _numberA;
        }
        void setA(double number){
            _numberA = number;
        }
        double getB(){
            return _numberB;
        }
        void setB(double number){
            _numberB = number;
        }
        virtual double getResult(double A, double B){
            return 0;
        }
};

// +运算具体实现
class OperatorAdd:public Operator{
    public:
        double getResult(double A,double B){
            this->setA(A);
            this->setB(B);
            return this->getA()+this->getB();
        }
};

// -运算具体实现
class OperatorSub:public Operator{
    public:
        double getResult(double A,double B){
            this->setA(A);
            this->setB(B);
            return this->getA()-this->getB();
        }
};

// ×运算具体实现
class OperatorMul:public Operator{
    public:
        double getResult(double A,double B){
            this->setA(A);
            this->setB(B);
            return this->getA()*this->getB();
        }
};

// /运算具体实现
class OperatorDev:public Operator{
    public:
        double getResult(double A,double B){
            if(B==0){
                throw"除数不能为零";
            }
            this->setA(A);
            this->setB(B);
            return this->getA()/this->getB();
        }
};

// 工厂类
class Factory{
    public:
        virtual Operator* createOperation(){
            return NULL;
        }
};


// 加法操作符工厂类
class AddFactory:public Factory{
    public:
        Operator* createOperation(){
            return new OperatorAdd();
        } 
};

// 减法操作符工厂类
class SubFactory:public Factory{
    public:
        Operator* createOperation(){
            return new OperatorSub();
        } 
};

// 乘法操作符工厂类
class MulFactory:public Factory{
    public:
        Operator* createOperation(){
            return new OperatorMul();
        } 
};

// 除法操作符工厂类
class Devactory:public Factory{
    public:
        Operator* createOperation(){
            return new OperatorDev();
        } 
};

// 客户端程序
int main(){
    Factory* a = new AddFactory();
    Operator* ao = a->createOperation();
    cout<<ao->getResult(3,5)<<endl;
}

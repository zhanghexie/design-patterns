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
            cout<<"wi"<<endl;
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

// 操作符工厂类
class OperationFactory{
    public:
        static Operator*  OperatorCreate (char c){
            Operator* op;
            switch (c)
            {
            case '+':
                op = new OperatorAdd;
                break;
            case '-':
                op = new OperatorSub;
                break;
            case '*':
                op = new OperatorMul;
                break;
            case '/':
                op = new OperatorDev;
                break;    
            default:
                throw"出现错误";
                return NULL;
                break;
            } 
            return op;
        }
};

// 客户端程序
int main(){
    cout<<"+:"<<OperationFactory::OperatorCreate('+')->getResult(8,4)<<endl;
    cout<<"-:"<<OperationFactory::OperatorCreate('-')->getResult(8,4)<<endl;
    cout<<"*:"<<OperationFactory::OperatorCreate('*')->getResult(8,4)<<endl;
    cout<<"/:"<<OperationFactory::OperatorCreate('/')->getResult(8,4)<<endl;
    cout<<"a:"<<OperationFactory::OperatorCreate('a')->getResult(8,4)<<endl;
}

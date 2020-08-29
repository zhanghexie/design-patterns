#include<iostream>
using namespace std;

// 定义RealSubject和Proxy的公共接口。
class Subject{
    public:
        virtual void request(){}
};

// 定义Proxy所代表的真实实体。
class RealSubject:public Subject{
    public:
        void request(){
            cout<<"实体Proxy回应"<<endl;
        }
};

// Proxy类,保存一个引用使得代理可以访问实体。并提供一个与subject相同的接口。
class Proxy:public Subject{
    private:
        RealSubject* realSubject = NULL; //不符空值会随便指向一个个地址。
    public:
        void request(){
            if (!this->realSubject){//直接用p或!p。不要用逻辑比较符号。
                this->realSubject=new RealSubject();
            }
            this->realSubject->request();
        }
};

// 客户端代码
int main(){
    Proxy p;
    p.request();
    return 1;
}
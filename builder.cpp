#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 具体产品
class Product{
    private:
        vector<string> parts;

    public:
        void add_part(string str){
            this->parts.push_back(str);
        }

        void show_result(){
            for(int i=0; i<this->parts.size(); i++){
                cout<<this->parts[i]<<endl;
            }
        }
}; 

// 为创建一个product对象的各个部件指定抽象接口。
class Builder{
    public:
        Product *p;

        Builder(Product* p){
            this->p = p;
        }

        Builder(){
            this->p = new Product();
        }

        virtual void builder_a(){}
        virtual void builder_b(){}
        virtual Product* get_result(){
            return this->p;
        }
};

//具体构造者，实现Builder接口，构造和装配各个部件。、
class ConcreteBuilderA:public Builder{
    public:
        ConcreteBuilderA():Builder(){}  
        ConcreteBuilderA(Product *p):Builder(p){}        
        void builder_a(){
            this->p->add_part("部件A");
        }
        
        void builder_b(){
            this->p->add_part("部件B");
        }

        Product* get_result(){
            return this->p;
        }
};

//具体构造者，实现Builder接口，构造和装配各个部件。、
class ConcreteBuilderB:public Builder{
    public:
        ConcreteBuilderB():Builder(){}  
        ConcreteBuilderB(Product *p):Builder(p){}        
        void builder_a(){
            this->p->add_part("部件x");
        }
        
        void builder_b(){
            this->p->add_part("部件y");
        }

        Product* get_result(){
            return this->p;
        }
};

// 构建一个使用Builder接口的对象。
class Director{
    public:
        void construct(Builder *b){
            b->builder_a();
            b->builder_b();
        }
};

int main(){
    ConcreteBuilderA *b1 = new ConcreteBuilderA();
    Director *d = new Director();
    d->construct(b1);
    Product *p = b1->get_result();
    cout<<"A构建："<<endl;
    p->show_result();

    ConcreteBuilderB *b2 = new ConcreteBuilderB(p);
    d->construct(b2);
    cout<<"B构建："<<endl;
    p->show_result();
}
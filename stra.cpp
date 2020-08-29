/*
* 策略模式
* 张鹤轩
* 2020-8-2
*/

#include<iostream>
using namespace std;

// 抽象策略类
class Strategy{
public:
    virtual void AlgorithmInterface(){};
};

// 具体策略A
class ConcreteStrategyA:public Strategy{
public:
    void AlgorithmInterface(){
        cout << "具体方法A" << endl;
    }
};

// 具体策略B
class ConcreteStrategyB:public Strategy{
public:
    void AlgorithmInterface(){
        cout << "具体方法A" << endl;
    }
};

// 具体策略C
class ConcreteStrategyC:public Strategy{
public:
    void AlgorithmInterface(){
        cout << "具体方法A" << endl;
    }
};

// 上下文
class Context{
public:
    Strategy* s;
    Context(Strategy* s){
        this->s = s;
    }
    void ContextInterface(){
        this->s->AlgorithmInterface(); //直接调用相应方法。
    }
};
int main(){
    // 逻辑判断放到了客户端。
    Context* c = new Context(new ConcreteStrategyA());
    Context& b = *new Context(new ConcreteStrategyA());
    Context s = Context(new ConcreteStrategyA());
    c->ContextInterface();
    b.ContextInterface();
    s.ContextInterface();
}

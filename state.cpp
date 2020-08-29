/*
* 状态模式
* 张鹤轩
* 2020-8-12
*/

#include<iostream>
using namespace std;

// 类前声明。下一个类要用到这个类
class State;

// 维护一个具体的状态实例，这个实例定义当前状态。
// 这里将声明与实现分开，因为实现时会用到State方法，而通过类前声明无法访问。
class Context{
    private:
        State* state;
    public:
        State* get_state();
        void set_state(State *state);
        void request();
};

// 状态类的接口
class State{
    public:
        virtual void handle(Context *context){}
};

// 具体状态类
class ConcreteStateA:public State{
    public:
        void handle(Context *context);
};

// 具体状态类声明 
class ConcreteStateB:public State{
    public:
        void handle(Context *context);
};

// 具体状态类声明
class ConcreteStateC:public State{
    public:
        void handle(Context *context);
};

// Context类的实现
State* Context::get_state(){
    return this->state;
}
void Context::set_state(State *state){
    this->state = state;
}
void Context::request(){
    state->handle(this);
}

// ConcreteStateA的实现
void ConcreteStateA::handle(Context *context){
    cout<<"当前状态A，这里可加一些逻辑判断，不过我就不加直接进入状态B了。"<<endl;
    context->set_state(new ConcreteStateB());
}

// ConcreteStateB的实现
void ConcreteStateB::handle(Context *context){
    cout<<"当前状态B，这里可加一些逻辑判断，不过我就不加直接进入状态C了。"<<endl;
    context->set_state(new ConcreteStateC());
}

// ConcreteStateB的实现
void ConcreteStateC::handle(Context *context){
    cout<<"当前状态C，这里可加一些逻辑判断，不过我就不加直接进入状态A了。"<<endl;
    context->set_state(new ConcreteStateA());
}


int main(){
    Context c;
    c.set_state(new ConcreteStateA());
    c.request();
    c.request();
    c.request();
    return 0;
}
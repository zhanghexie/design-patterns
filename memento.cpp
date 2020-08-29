#include<iostream>
#include<string>
using namespace std;

// 负责存储Originator对象的内部状态，并防止Originator以外的其他对象访问备忘录。
class Memento{
private:
    string state;
public:
    Memento();
    Memento(string state);
    ~Memento();
    string get_state();
    // 怎么保存自己说了算。
    void set_state(string state);
};
Memento::Memento(){}
Memento::Memento(string state){
    this->state=state;
}
Memento::~Memento(){}
string Memento::get_state(){
    return this->state;
}
void Memento::set_state(string state){
    this->state=state;
}

// Originator发起人类。负责创建一个备忘录。
class Originator{
private:
    string state;
public:
    Originator();
    ~Originator();
    string get_state();
    void set_state(string state);
    Memento cteate_memento();
    void set_memento(Memento memento); 
    void show();
};
Originator::Originator(/* args */){
}
Originator::~Originator(){
}
string Originator::get_state(){
    return this->state;
}
void Originator::set_state(string state){
    this->state=state;
}
Memento Originator::cteate_memento(){
    return Memento(this->state);
}
void Originator::set_memento(Memento memento){
    this->state = memento.get_state();
} 
void Originator::show(){
    cout<<"当前状态："<<this->state<<endl;
}

// 管理者类，加入有好多份备忘录，这个管理类就很有用。
class Caretaker
{
private:
    Memento memento;
public:
    ~Caretaker();
    Memento get_memento();
    void set_memento(Memento memento);
};
Caretaker::~Caretaker(){
}
Memento Caretaker::get_memento(){
    return this->memento;
}
void Caretaker::set_memento(Memento memento){
    this->memento=memento;
}

int main(){
    Originator o;
    o.set_state("on");
    o.show();

    Caretaker c;
    c.set_memento(o.cteate_memento());

    o.set_state("off");
    o.show();

    o.set_memento(c.get_memento());
    o.show();

    return 0;
}
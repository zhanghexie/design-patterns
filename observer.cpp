#include<iostream>
#include<set>
#include<string>
using namespace std;

// 抽象观察者，为所有具体观察者定义一个接口，在的到主题的通知时更新自己。
class Observer{
    public:
        virtual void update(){
            cout<<"fulei"<<endl;
        }
};

class Subject{
    private:
        set<Observer*> observers;

    public:
        void Attach(Observer *observer){
            if (observers.find(observer)==observers.end()){
                observers.insert(observer);
            }
        }

        void Detach(Observer *observer){
            if (observers.find(observer)!=observers.end()){
                observers.erase(observer);
            }
        }

        void notify(){
            for(set<Observer*>::iterator it = observers.begin(); it != observers.end(); it++){
                // 一定要加括号，->优先级高于*。
                (*it)->update();
            }
        }
};

// 具体主题类。
class ConcreteSubject:public Subject{
    private:
        string subjectSate;
    
    public:
        void set_subject_state(string s){
            this->subjectSate = s;
        }
        string get_subject_state(){
            return this->subjectSate;
        }
};

// 具体观察者类。
class ConcreteObserver:public Observer{
    private:
        ConcreteSubject *sub;
        string substate="";
        string name;
    
    public:
        ConcreteObserver(ConcreteSubject *sub, string name){
            this->sub = sub;
            this->name = name;
        }

        void update(){
            this->substate = this->sub->get_subject_state();
            cout<<this->name<<"关注的s的状态："<<this->substate<<endl;
        }
};

// 客户端程序
int main(){
    ConcreteSubject s;
    s.Attach(new ConcreteObserver(&s,"xiaoming"));
    s.Attach(new ConcreteObserver(&s,"xiaozhang"));
    s.set_subject_state("up");
    s.notify();
}

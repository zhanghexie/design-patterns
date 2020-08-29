#include<iostream>
#include<string>
#include<set>
using namespace std;


class Component{
    public:
        string name;
    public:
        int depth;
        virtual void add(Component *component){}
        virtual void remove(Component *component){}
        virtual void display (){
            for (int i=0;i<this->depth;i++){
                cout<<"-";
            }
            cout<<this->name<<endl;

        }
        Component(){}
        Component(string name,int depth){
            this->name=name;
            this->depth=depth;
        }
        Component(string name){
            this->name=name;
        }
};

class Leaf:public Component{
    public:
        void add(Component *component){
            cout<<"叶子节点，不能添加。"<<endl;
        }
        void remove(Component *component){
            cout<<"叶子节点，不能删除。"<<endl;
        }
        void display (){
            Component::display();
        }
        Leaf(){}
        Leaf(string name, int depth):Component(name,depth){}    
        Leaf(string name):Component(name){}    
};

class Composite:public Component{
    private:
        set<Component*> components;
    public:
        void  add(Component *component){
            components.insert(component);
            component->depth=this->depth+1;
        }
        void remove(Component *component){
            components.erase(component);
        }
        void display(){
            Component::display();
            for(set<Component*>::iterator it=components.begin();it!=components.end();it++){
                (*it)->display();
            }
        }
        Composite(){}
        Composite(string name, int depth):Component(name,depth){}    
        Composite(string name):Component(name){}    
};
int main(){
    Composite root = Composite("root",0);
    Leaf *leaf1 = new Leaf("leaf1");
    root.add(leaf1);

    Leaf *leaf2 = new Leaf("leaf2");
    root.add(leaf2);
    
    Composite *c1 = new Composite("c1");
    root.add(c1);

    Leaf *leaf2_1 = new Leaf("leaf2_1");
    c1->add(leaf2_1);

    Leaf *leaf3 = new Leaf("leaf3");
    root.add(leaf3);
    root.display();
    return 0;

}
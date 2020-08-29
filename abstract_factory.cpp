/*
* 抽象工厂模式
* 张鹤轩
* 2020-8-11
*/

#include<iostream>
#include<string>
using namespace std;

// 用户类
class User{
    private:
        string name;
        string id;
    
    public:
        
        User(string id,string name){
            this->id = id;
            this->name = name;
        }

        string get_name(){
            return this->name;
        }

        void set_name(string name){
            this->name = name;
        }
        
        string get_id(){
            return this->id;
        }

        void set_id(string id){
            this->id = id;
        }
};

// 用户表类的接口
class IUser{
    public:
        virtual void insert(User* user){}
        virtual void remove(User* user){}
};

// SqalserverUser用户表
class SqlUser:public IUser{
    public:
        void insert(User* user){
            cout<<"sql添加用户："<<user->get_name()<<",id为："<<user->get_id()<<endl;
        }
        
        void remove(User* user){
            cout<<"sql删除用户："<<user->get_name()<<",id为："<<user->get_id()<<endl;
        }
}; 

// AccUser用户表
class AccUser:public IUser{
    public:
        void insert(User* user){
            cout<<"Acc添加用户："<<user->get_name()<<",id为："<<user->get_id()<<endl;
        }
        
        void remove(User* user){
            cout<<"Acc删除用户："<<user->get_name()<<",id为："<<user->get_id()<<endl;
        }
}; 


// 部门类的接口
class IDepartment{
    public:
        virtual void insert(string department){}
        virtual void remove(string department){}
};

// SqalserverUser用户表
class sqlDepartment:public IDepartment{
    public:
        void insert(string department){
            cout<<"sql插入部门："<<department<<endl;
        }

        void remove(string department){
            cout<<"sql删除部门："<<department<<endl;
        }
}; 

// AccUser部门表
class AccDepartment:public IDepartment{
    public:
        void insert(string department){
            cout<<"Acc插入部门："<<department<<endl;
        }
        
        void remove(string department){
            cout<<"Acc删除部门："<<department<<endl;
        }
}; 

// 工厂类接口
class IFactory{
    public:
        virtual IUser* create_user()=0;
        virtual IDepartment* create_department()=0;
};

// sql数据库工厂类
class SqlFactory:public IFactory{
    public:
        IUser* create_user(){
            return new SqlUser();
        } 

        IDepartment* create_department(){
            return new sqlDepartment();
        }
};

// Acc数据库工厂类
class AccFactory:public IFactory{
    public:
        IUser* create_user(){
            return new AccUser();
        }

        IDepartment* create_department(){
            return new AccDepartment();
        }
};

// 客户端程序
int main(){
    User* zhang = new User("123","zhang");

    // 创建工厂，更改数据库类形时只需要更改new后面的一个词就可以。
    IFactory *ifactory = new SqlFactory();

    // 创建用户表
    IUser* iuser = ifactory->create_user();
    iuser->insert(zhang);
    iuser->remove(zhang);

    // 创建部门表
    IDepartment *idepartment = ifactory->create_department(); 
    idepartment->insert("行政部");
    idepartment->remove("行政部");

    return 0;
}
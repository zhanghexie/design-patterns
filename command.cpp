/*
 * 命令模式
 * 张鹤轩
 * 2020-8-16
 * */

#include<iostream>
using namespace std;


// 接受者，知道如何执行一个命令。
class Reciver{
	public:
		void action(){
			cout<<"执行命令"<<endl;
		}
};

// 用来声明操作的接口
class Command{
	protected:
		Reciver* reciver;
	public:
		Command(Reciver *reciver){
			this->reciver = reciver;
		}
		virtual void excute(){}
};

// 具体操作
class ConcreteCommand:public Command{
	
	public:
		ConcreteCommand(Reciver* reciver):Command(reciver){}
		void excute(){
			this->reciver->action();
		}
};

// 要求该命令执行者个请求
class Invoker{
	private:
		Command* command;
	public:
		void set_command(Command* command){
			this->command = command;
		}
		void execute_command(){
			this->command->excute();
		}

};

int main(){
	Invoker i;
	Reciver* r = new Reciver();
	Command* c = new ConcreteCommand(r);
	i.set_command(c);
	i.execute_command();

}

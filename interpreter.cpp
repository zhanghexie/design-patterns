/*
 * 解释模式
 * 张鹤轩 
 * 2020-8-17
 * */

#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

class Expression{
	public:
		virtual bool interpret(string info)=0;
};

// 终结字符表达式类
class TerminalExperssion:public Expression{
	private:
		set<string> terminalSet;
	public:
		TerminalExperssion(vector<string> data){
			vector<string>::iterator it = data.begin();
			for(;it!=data.end();it++){
				terminalSet.insert(*it);
			}
		}
		bool interpret(string info){
			if(1==terminalSet.count(info)){
				return true;
			}
			return false;
		}
};

// 非终结字符表达式类
class NonTerminalExpersion:public Expression{
	private:
		Expression *city = nullptr;
		Expression *person = nullptr;
	public:
		NonTerminalExpersion(Expression *city,Expression *person){
			this->city=city;
			this->person=person;
		}
		bool interpret(string info){
			int i = info.find("的");
			return city->interpret(info.substr(0,i))&&person->interpret(info.substr(i+3,info.size()));
		}
};

class Context{
	private:
		vector<string> citys = {"天津","邢台","保定"};
		vector<string> persons = {"老人","妇女","儿童"};
		Expression *cityPerson;
	public:
		Context(){
			Expression *city = new TerminalExperssion(citys);
			Expression *person = new TerminalExperssion(persons);
			cityPerson = new NonTerminalExpersion(city,person);
		}
		void free_ride(string info){
			bool ok = cityPerson->interpret(info);
			if(ok){
				cout<<"您是"<<info<<"，可以免费。"<<endl;
			}else {
				cout<<"您不可以免费!"<<endl;
			}
		}

};
int main(){
	string citys[3] = {"天津","邢台","保定"};
	Context* c = new Context();
	string s;
	cout<<"请输入你的身份：";
	// 使用getline输入字符串
	getline(cin,s);
	c->free_ride(s);
	return 0;
}

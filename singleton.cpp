/*
 * 单例模式
 * 张鹤轩
 * 2020-8-16
 * */

#include<iostream>
using namespace std;

class Singleton;
class Singleton{
	private:
		static Singleton* instance;
		Singleton(){
			cout<<"创建一个实例。"<<endl;;
		}
	public:
		static Singleton* get_instance(){
			if(nullptr==Singleton::instance){
				// 如果要这样是使用要在类之前声明该类，直接使用instance不用声明。
				Singleton::instance = new Singleton();
			}
			return Singleton::instance;
		}
		void say_hello(){
			cout<<"hello"<<endl;
		}
};
// 必须实例化。
Singleton* Singleton::instance=nullptr;

int main(){
	Singleton* s1 = Singleton::get_instance();
	Singleton* s2 = Singleton::get_instance();
	if(s1==s2){
		cout<<"s1==s2"<<endl;
	}	
	return 0;
}

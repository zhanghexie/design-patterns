#include <iostream>
#include <vector>
using namespace std;

// 迭代抽象类。
template < class T >
class Iterator{
	public:
		Iterator(){}
		Iterator(T(&t)[]){}
		virtual T* first(){return nullptr;}
		virtual T* next(){return nullptr;}
		virtual T* current_item(){return nullptr;}
		virtual bool is_end(){return false;}
};

// 聚焦抽象类
template < class T >
class Aggreate{
	public:
		virtual Iterator<T>* create_iterator()=0;

};

template<class T>
class ConcteteAggragate;

// 具体迭代类。
template < class T >
class ConcteteIterator:public Iterator<T>{
	private:
		int current;
	public:
		ConcteteAggragate<T> *aggrate;
		ConcteteIterator();
		ConcteteIterator(ConcteteAggragate<T> *aggrate);
		T* first();
		T* next();
		bool is_end();
		T* current_item();
};

// ConcteteAggragate
template < class T >
class ConcteteAggragate:public Aggreate<T>{
	public:
		vector<T> items = vector<T>();
	public:
		Iterator<T>* create_iterator();
		int count();
		T* operator[](int a);
		void add(T n);
};


template < class T >
ConcteteIterator<T>::ConcteteIterator(){
	this->aggrate=ConcteteAggragate<T>();
}
template < class T >
ConcteteIterator<T>::ConcteteIterator(ConcteteAggragate<T> *aggrate){
	this->aggrate=aggrate;	
}
template < class T >
T* ConcteteIterator<T>::first(){
	current=0;
	return this->current_item();
}
template < class T >
T* ConcteteIterator<T>::next(){
	current++;
	return this->current_item();
}
template < class T >
bool ConcteteIterator<T>::is_end(){
	if (current>=aggrate->count()-1){
		return true;
	}else{
		return false;
	}
}
template < class T >
T* ConcteteIterator<T>::current_item(){
	return (*(this->aggrate))[current];
}

template<class T>
Iterator<T>* ConcteteAggragate<T>::create_iterator(){
	return new ConcteteIterator<T>(this);		
}
template<class T>
int ConcteteAggragate<T>::count(){
	return items.size();
}
template<class T>
T* ConcteteAggragate<T>::operator[](int a){
	return &(this->items[a]);
}
template<class T>
void ConcteteAggragate<T>::add(T i){
	this->items.push_back(i);
}

int main(){
	ConcteteAggragate<int> a;
	for (int i=0;i<10;i++){
		a.add(i);
	}
	Iterator<int>* i = a.create_iterator();
	cout<<*(i->first())<<endl;
	while(!(i->is_end())){
		cout<<*(i->next())<<endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
class shape{
    private:
	    float high;
	    float width;
    public:
	    float getHigh(){
		return high;
	    }
	    void setHigh(float h){
		high = h;
	    }

	    float getWidth(){
		return width;
	    }
	    void setWidth(float w){
		width=w;
	    }
};

class Trangle: public shape{};
int main(){
	Trangle s;
	s.setHigh(1.14);
	cout<<s.getHigh()<<endl;
	return 0;

}

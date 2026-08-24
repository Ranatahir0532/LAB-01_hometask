#include<iostream>
#include<cstring>
using namespace std;
class dynamicString{
private:
char* data;
public:
    dynamicString(const char* text){
    	cout<<"constructor called"<<endl;
    	data = new char[strlen(text) + 1];
    	int i; 
		int len = strlen(text);
    	for(i=0 ; i<len ; i++){
    		data[i] = text[i];
		}
		data[len] = '\0';
    	}
    dynamicString(){
    	 cout << "Default constructor called" << endl;
    	data = new char[1];
    	data[0] = '\0';
	}
	void print(){
	cout<<"text:"<<data<<endl;	
	}
	dynamicString(const dynamicString &other){
		cout<<"copy constructor called"<<endl;
		this->data = new char[strlen(other.data) + 1];
		int i;
			for(i=0 ; i<strlen(other.data) ; i++){
    		this->data[i] = other.data[i];
		}
		this->data[strlen(other.data)] = '\0';
		}
	dynamicString& operator=(const dynamicString &other){
		cout<<"copy assigment operator called"<<endl;
		if(this == &other){
			return *this;
		}
		delete[] data;
		int i,len;
		data  = new char[strlen(other.data) + 1];
		len = strlen(other.data);
		for(i=0;i<len;i++){
			data[i] = other.data[i];
		}
		data[len] = '\0';
		return *this;
	}
	~dynamicString(){
		cout<<"destructor called"<<endl;
		delete[] data;
	}
	int lenght(){
		return strlen(data);
	}
	void changeOneChar(char letter,int index){
		int i;
		if(index>=0 && index<lenght()){
			for(i=0;i<lenght();i++){
				if(i == index){
					data[i] = letter;
				}
			}
		}
		
	}
			
};
int main(){
	dynamicString s1("hello");
	//simple constructor
	s1.print();
	//copy constructor
	dynamicString s2 = s1;
	
	s2.print();
	dynamicString s3("rabiya");
	//copy assigment
	s2 = s3;
	//default constructor
	dynamicString s4;
	s3.print();
	s2.print();
	s3.changeOneChar('T',1);
	s3.print();
	
	
	
}

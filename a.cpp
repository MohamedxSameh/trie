
#include <iostream>
using namespace std;

class Box{
	int width;
	int lenght;
public: 
	Box(int l , int w){
		lenght = l;
		width = w;
	}
	void getb(){
		cout<<lenght<<" , "<<width;
	}
	void gete(char c){
		cout<<c;
	}
};

int main(){
	cout<<"UNTITLED X MOHAMED"<<endl;
	int index =  'e';
	int y =  index - 'a';
	string c = "mohamed";
	bool s = 0;
	int x [26]= {0};
	// for(int i = 0 ; i < 26 ; i++){
	// 	cout<<x[i]<<endl;
	// }
	// Box b(3,44) ;
	// b.getb();
	// b.gete('c');


	// string * ar [30]={0};

	// for(int i = 0 ; i<30 ; i++ )
	// {
	// 	cout<<i << " : " <<ar[i]<<endl;
	// }

cout<<'d'-'a'<<endl;
cout<<'o'-'a'<<endl;
cout<<'g'-'a'<<endl;
}
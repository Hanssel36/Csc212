#include <iostream>
#include <stdio.h> 
#include <assert.h>
using namespace std;
void binary_print(ostream& outs, unsigned int n){
	if(n == 0){
		outs << 0;
	}else if(n == 1){
		outs << 1;
	}else{
		binary_print(cout,n/2);
		outs << n%2;

	}

}

void triangle(ostream& outs, unsigned int m, unsigned int n){

		if(m <= n){
			for(int i = 0; i< m; i++){
				outs << "*";
				
			}
			outs << "\n";
			triangle(cout, m+1,n);
		for(int i = 0; i < m; i++){
				outs << "*";
			}
			outs << "\n";
		}
}
double pow(double x, int n){
	if (x == 0)
	{
	assert(n > 0);
	return 0;
	}
	else if (n == 0){
		return 1;
	}
	else if (n > 0 &&(n%2 == 0)){
		return pow(x,n/2)*(pow(x, n/2));
	}
	else if(n > 0 &&(n%2 == 1)){ 
		return x*pow(x,n/2)*pow(x,n/2);
	}else{
		return 1/pow(x,-n);
	}
}

 void indented_sentences(size_t m, size_t n){
 	if(m <= n){
			
		}

 }
int main(){

	cout << indented_sentences(cout,3,4) << endl;

}
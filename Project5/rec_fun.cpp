#include <iostream>
#include <stdio.h> 
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

	
}

int main(){

	

}
#include<stdio.h>
#include<Windows.h>

		//Lösung 1a)

int fib(int n);

int main(void){
	int n;
	scanf("%i", &n);
	printf("%i", fib(n));
	Sleep(1000);
}

int fib(int n){
	int i, f=0, g=1, z; 
	for(i=0; i<n; i++){
		z=f+g;
		f=g;
		g=z;
	}
	return f;
}
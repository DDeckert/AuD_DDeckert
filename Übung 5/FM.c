#include<stdio.h>
#include<Windows.h>

		//Lösung 1c)

int f(int n), m(int n);

int main(void){
	int n;
	scanf("%i", &n);
	printf("%i \n  %i", f(n), m(n));
	Sleep(5000);
	return 0;
}

int f(int n){
	if(n==0) return 1;
	else return n - m(f(n-1));
}

int m(int n){
	if(n==0) return 0;
	else return n - f(m(n-1));
}
#include<stdio.h>
#include<Windows.h>

		//Lösung 1b)

int g(int n);

int main(void){
	int n;
	scanf("%i", &n);
	printf("%i", g(n));
	Sleep(5000);
	return 0;
}

int g(int n){
	if(n==0) return 0;
	return n - g(g(n-1));
}
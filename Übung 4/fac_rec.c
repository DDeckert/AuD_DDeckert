#include <stdio.h>
#include <Windows.h>

		//Lösung zur 3) - rekursiv

int fac_rec(int n);

int main(void){
	int i;
	scanf("%i", &i);
	printf("%d", fac(i));
	Sleep(10000);
	return 0;
}

int fac_rec(int n){
	if(n==0) return 1;
	else return n*fac(n-1);
}
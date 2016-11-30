#include <stdio.h>
#include <Windows.h>

int fac(int n);

int main(void){
	int i;
	scanf("%i", &i);
	printf("%d", fac(i));
	Sleep(10000);
	return 0;
}

int fac(int n){
	int i, ret = 1;
	for(i=1; i<=n; i++)ret=ret*i;
	return ret;
}
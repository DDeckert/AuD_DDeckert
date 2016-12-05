#include <stdio.h>
#include "wait.h"

int fac(int n);

int main(void){
	int i;
	scanf("%i", &i);
	printf("%d", fac(i));
	wait(3); //Wait 3 seconds.
	return 0;
}

int fac(int n){
	int i, ret = 1;
	for(i=1; i<=n; i++)ret=ret*i;
	return ret;
}

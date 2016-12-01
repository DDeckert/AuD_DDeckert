#include <stdio.h>
#include <Windows.h>

		//Loesung 2c)

/*########################################*/
int s(int n){
	int s=0, i=0;
	while(i<=n){
		if(i%3==0 || i%5==0)s += i;
		i++;
	}
	return s;
}
/*########################################*/
int main(void){
	int n;
	scanf("%i", &n);
	printf("%i\n", s(n));
	Sleep(10000);
	return 0;
}


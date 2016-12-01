#include <stdio.h>
#include <Windows.h>

		//Loesung 1a)

/*########################################*/
void factorize(int n){
	int t=2;
	while(n>=t){
		if(n%t == 0){
			printf("%i ", t);
			n = n/t;
		}
		else t++;
	}
}
/*########################################*/

int main(void){
	int i;
	scanf("%i", &i);
	factorize(i);
	Sleep(10000);
	return 0;
}


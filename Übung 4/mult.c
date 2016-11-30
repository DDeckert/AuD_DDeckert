#include <stdio.h>
#include <Windows.h>

		//Lösung zur 2b)

int main(void){
	int i, j, k;
	scanf("%i", &i);
	printf("\n");
	for(j=1; j<=i; j++){
		for(k=1; k<=i; k++){
				printf("%d ", j*k);
		}
		printf("\n");
	}
	Sleep(10000);
	return 0;
}


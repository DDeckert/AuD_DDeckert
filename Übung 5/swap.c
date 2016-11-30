#include<stdio.h>
#include<Windows.h>

		//Lösung 3)

void swap(int* x, int* y){	//Tausch ausserhalb des eigenen Speichers: mit Pointern
	int g = *x;
	if(g%2 == 1) *y = *y +1;
	*x = *y;
	*y = g;
}

int main(void){
	int x, y;
	printf("x:");
	scanf("%i", &x);
	printf("\n y:");
	scanf("%i", &y);
	swap(&x, &y);
	printf("\n x: %i, y: %i", x, y);
	Sleep(5000);
	return 0;
}




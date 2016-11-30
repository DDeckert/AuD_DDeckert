#include <stdio.h>
#include <Windows.h>

		//Lösung der 2c) - naiver Ansatz

int main(void){
	int p, i, check;
	for(p=2; p<1001; p++){
		check = 1;
		for(i=2; i<p; i++{
			if(p%i==0)check = 0;
		}
		if(check) printf("%i ", p);
	}
	
	Sleep(10000);
	return 0;
}


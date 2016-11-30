#include <stdio.h>
#include <Windows.h>

		//Lösung der 2c) - Sieb des Erasthostenes

int main(void){
	int i,j, sieve[1001];		//Sieb von 0 bis 1000, Zahlen von 1 bis 1000
	for(i=0; i<=1000; i++)sieve[i]=1;
	for(i=2; i<=1000; i++){
		if(sieve[i]){
			j=2;
			while(i*j<=1000){
				sieve[i*j]=0;
				j++;
			}
		}
	}
	for(i=2; i<=1000; i++){
		if(sieve[i])printf("%d ", i);
	}
	
	Sleep(10000);
	return 0;
}


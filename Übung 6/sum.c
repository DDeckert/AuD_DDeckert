#include<stdio.h>
#include<Windows.h>

		//Lösung 2a)
				
typedef struct element *list;
struct element{
	int value;
	list next;
};

list make_list(int n);
void list_print(list l);
void delete(list l);

int sum_rec(list l){
	if(l == NULL)return 0;
	return l->value + sum_rec(l->next);
}

int sum_it(list l){
	int res =0;
	while(l!=NULL){
		res = res + l->value;
		l = l->next;
	}
	return res;
	
}


int main(){
	int n;
	printf("Bitte geben Sie die Laenge der Liste an:\n");
	scanf("%i", &n);
	list l = make_list(n);
	printf("Ergebnis rekursiv: %i\n", sum_rec(l));
	printf("Ergebnis iterativ: %i\n", sum_it(l));
	
	delete(l);
	Sleep(15000);
	return 0;
}

list make_list(int n){	//erzeugt Liste der Zahlen von 0 bis n
	list l=NULL, g=NULL;
	int i;
	for(i = 0; i<=n; i++){
		g = malloc(sizeof(*g));
		g->value = i;
		g->next = l;
		l = g;
	}
	return g;
}

void list_print(list l){	//druckt Listenelemente der Reihe nach
	while(l!=NULL){
		printf("%i ", l->value);
		l = l->next;
	}
	printf("\n");
}

void delete(list l){
	if(l == NULL) return;
	delete(l->next);
	free(l);
}


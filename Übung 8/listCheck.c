#include<stdio.h>
#include<Windows.h>

		//Lösung 1a)
				
typedef struct element *list;
struct element{
	int value;
	list next;
};

list make_list(int n);
void list_print(list l);
void delete(list l);

//########################
int f(list l){
	if(l == NULL) return 1;
	
	while(l->next != NULL){
		if(abs(l->value - l->next->value)>1) return 0;
		l = l->next;
	}
	return 1;
}
//########################

int main(){
	int n;
	printf("Bitte geben Sie die Laenge der Liste an:\n");
	scanf("%i", &n);
	list l = make_list(n);
	printf("Ergebnis: %i\n", f(l));
	
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


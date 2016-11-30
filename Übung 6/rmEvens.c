#include<stdio.h>
#include<Windows.h>

		//Lösung 2b)
				
typedef struct element *list;
struct element{
	int value;
	list next;
};

list make_list(int n);
void list_print(list l);
void delete(list l);

void rmEvens_rec(list* l){
	if(*l == NULL)return;
	rmEvens_rec(&((*l)->next));
	if((*l)->value%2==0){
		list temp = *l;
		*l = (*l)->next;
		free(temp);
	}
}

void rmEvens_it(list* head){
	list temp;
	while(*head!=NULL){
		if((*head)->value%2 == 0){
			temp = *head;
			*head = (*head)->next;
			free(temp);
		}
		else head = &((*head)->next);
	}
}


int main(){
	int n;
	list l, m;
	printf("Bitte geben Sie die Laenge der rekursiven Liste an:\n");
	scanf("%i", &n);
	
	l = make_list(n);
	printf("Ergebnis rekursiv: \n");
	rmEvens_rec(&l);
	list_print(l);
	delete(l);
	
	m = make_list(n);
	printf("Ergebnis iterativ: \n");
	rmEvens_it(&m);
	list_print(m);
	delete(m);
	
	Sleep(15000);
	return 0;
}

list make_list(int n){	//erzeugt Liste der Zahlen von n bis 0
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
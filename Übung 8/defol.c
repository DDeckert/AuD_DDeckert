#include<stdio.h>
#include<Windows.h>

		//Loesung 1b)

typedef struct node *tree;
typedef struct node{
	int value;
	tree left, right;
} node;

tree make_tree(int n);
void tree_print(tree t);
void delete(tree t);

/*########################################*/
void defol(tree *p){
	if((*p)==NULL)return;
	if((*p)->left == NULL && (*p)->right == NULL){
		tree temp = *p;
		*p= NULL;
		free(temp);
	}
	else{
		defol(&((*p)->left));
		defol(&((*p)->right));
	}
}
/*########################################*/

int main(){
	int n;
	tree t;
	
	printf("Bitte geben Sie die Groesse des Baumes an:\n");
	scanf("%i", &n);
	t=make_tree(n);
	printf("defol: ");
	defol(*t)
	tree_print(t);
	//delete(t);
	
	Sleep(15000);
	return 0;
}

tree make_tree(int n){
	tree t=NULL, g=NULL;
	int i;
	for(i = 1; i<=n; i++){
		g = malloc(sizeof(*g));
		g->value = i;
		g->left = t;
		g->right = t;
		t = g;
	}
	return g;
}


void tree_print(tree t){
	if(t == NULL) {
		printf("N ");
		return;
	}
	printf("%i ", t->value);
	tree_print(t->left);
	tree_print(t->right);
}

void delete(tree t){
	if(t == NULL) return;
	delete(t->left);
	delete(t->right);
	free(t);
}
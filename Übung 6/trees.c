#include<stdio.h>
#include<Windows.h>

typedef struct node *tree;
typedef struct node{
	int value;
	tree left, right;
} node;

tree make_tree(int n);
void tree_print(tree t);
void delete(tree t);

int help(int n, tree t){
	if(t==NULL)return 0;
	if(t->value == n) return 1 + help(n, t->left) + help(n, t->right);
	else return help(n, t->left) + help(n, t->right);
}

tree baz(tree s, tree t){
	if(s==NULL) return NULL;
	tree u = malloc(sizeof(*u));
	u->value=help(s->value, t);
	u->left = baz(s->left, t);
	u->right = baz(s->right, t);
	return u;
}

int leaf_prod(tree t){
	if(t==NULL)return 1;
	if(t->left ==NULL && t->right==NULL)return t->value;
	return leaf_prod(t->left)*leaf_prod(t->right);
	
}

int main(){
	int n;
	tree t, s;
	
	printf("Bitte geben Sie die Groesse des Baumes an:\n");
	scanf("%i", &n);
	t=make_tree(n);
	t = baz(t, make_tree(2));
	tree_print(t);
	printf("\n");
	delete(t);
	
	printf("Bitte geben Sie die Groesse des Baumes an:\n");
	scanf("%i", &n);
	s = make_tree(n);
	printf("%i", leaf_prod(s));
	delete(s);
	
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
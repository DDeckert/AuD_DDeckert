#include<stdio.h>
#include<Windows.h>

		//Loesung 1b), 1c)

typedef struct node *tree;
typedef struct node{
	int value;
	tree left, right;
} node;

tree make_tree(int n);
void tree_print(tree t);
void delete(tree t);


/*########################################*/
int rank(tree t){
	if(t == NULL)return 0;
	if(t->right == NULL) {
		if(t->left != NULL)return rank(t->left)+1;
		return 1;
	}
	else return rank(t->right)+1;
}

int isLeftist(tree t){
	if(t == NULL) return 1;
	return isLeftist(t->left) && isLeftist(t->right) && (rank(t->left) >= rank(t->right));
}
/*########################################*/


int main(){
	int n;
	tree t;
	
	printf("Bitte geben Sie die Groesse des Baumes an:\n");
	scanf("%i", &n);
	t=make_tree(n);
	printf("Rank:%i\nIsLeftist:%i\n", rank(t), isLeftist(t));
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
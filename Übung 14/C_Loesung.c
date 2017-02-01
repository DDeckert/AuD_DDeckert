#include<stdio.h>

typedef struct node *tree;
struct node{
	int value;
	tree left, right;
};

int ident(tree t1, tree t2){
	if(t1 == t2) return 1;
	if(t1 == NULL || t2 == NULL) return 0;
	return (t1->value == t2->value) &&
		ident(t1->left, t2->left) &&
		ident(t1->right, t2->right);
}

int internal(tree t){
	if(t == NULL) return 0;
	if(t->left != NULL || t->right !=NULL){
		return 1 + internal(t->left) + internal(t->right);
	}
	else return 0;
}

void lRot(tree* tp){
	tree t = (*tp)->right;
	(*tp)->right = t->left;
	t->left = *tp;
	*tp = t;
}

int main(){
	return 0;
}
	
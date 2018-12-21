#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	struct tree *left;
	struct tree *right;
	int value;
}tree;

void add(tree **head, int x){
	if (*head == NULL) {
		*head = (tree*)malloc(sizeof(tree));
		(*head)->left = NULL;
		(*head)->right = NULL;
		(*head)->value = x;
	}
	if (x > (*head)->value){
		add(&((*head)->right), x);
	}
	if (x < (*head)->value){
		add(&((*head)->left), x);
	}
}

int find (tree *head, int x){
	if (head == NULL) return 0;
	if (head->value == x) return 1;
	if (head->value < x) return find(head->right, x);
	else return find(head->left, x);
}

int rank(tree *leaf){
	int r = 0;
	if (leaf->right != NULL) r++;
	if (leaf->left != NULL) r++;
	return r;
}

void print(tree *head){
	if (head == NULL) return;
	print(head->left);
	printf("%d ", head->value);
	print(head->right);
}

int main(){
	tree *head = NULL;
	int x;
	while (scanf("%d", &x) > 0){
		add(&head, x);
	}
	print(head);
	return 0;
}
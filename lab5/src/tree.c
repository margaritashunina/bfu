#include"tree.h"

void add(tree **head, void *x, fType compare, size_t size){
	if (*head == NULL) {
		*head = (tree*)malloc(sizeof(tree));
		(*head)->left = NULL;
		(*head)->right = NULL;
		(*head)->value = malloc(size);
		(*head)->size = size;
		memcpy((*head)->value, x, size);
	}
	if (compare(x, (*head)->value) == 1) 
			add(&((*head)->right), x, compare, size);
	if (compare(x, (*head)->value) == -1) 
			add(&((*head)->left), x, compare, size);
	if (compare(x, (*head)->value) == 0) 
			return;
}

int find (tree *head, void *x, fType compare){
	if (head == NULL) return 0;
	if (compare(x, head->value) == 0) 
			return 1;
	if (compare(x, head->value) == -1) 
			return find(head->right, x, compare);
	else return find(head->left, x, compare);
}

int rank(tree *head, fType compare, void *x){
	int k = 0;
	if (head == NULL) return -1;
	if (compare(x, head->value) == 0) return 0;
	if (compare(x, head->value) == 1) k = rank(head->right, compare, x);
	if (compare(x, head->value) == -1) k = rank(head->left, compare, x);
	if (k == -1) return -1;
	return k+1;
}

tree* minimum(tree *root){
	if (root->left == NULL) 
		return root;
	return minimum(root->left);
}

tree* delete(tree *root, void* x, fType compare){
	if (root == NULL) return root;
	if (compare(x, root->value) == -1) 
			root->left = delete(root->left, x, compare);
	else if (compare(x, root->value) == 1) 
			root->right = delete(root->right, x, compare);
	else {
		if (root->left != NULL && root->right !=NULL){
			tree *p = minimum(root->right);
			memcpy(root->value, p->value, p->size);
			root->right = delete(root->right, root->value, compare);
		}
		else if(root->left == NULL && root->right == NULL){
			free(root->value);
			free(root);
			return NULL;
		}
		else if (root->left != NULL) {
			tree *p = (tree*)malloc(sizeof(tree));
			memcpy(p, root->left, sizeof(tree));
			p->value = malloc(p->size);
			memcpy(p->value, (root->left)->value, p->size);
			free((root->left)->value);
			free(root->left);
			free(root->value);
			free(root);
			return p;
		}
		else if (root->right != NULL) {
			tree *p = (tree*)malloc(sizeof(tree));
			memcpy(p, root->right, sizeof(tree));
			p->value = malloc(p->size);
			memcpy(p->value, (root->right)->value, p->size);
			free((root->right)->value);
			free(root->right);
			free(root->value);
			free(root);
			return p;
		}
	}
	return root;
}

void clean(tree *root, fType compare){
	while (root != NULL){
		root = delete(root, root->value, compare);
	}
}
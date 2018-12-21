#ifndef tree_h
#define tree_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*fType)(void *, void *);

typedef struct tree{
	struct tree *left;
	struct tree *right;
	void* value;
	size_t size;
}tree;

void add(tree **head, void *x, fType compare, size_t size);
int find (tree *head, void *x, fType compare);
int rank(tree *head, fType compare, void *x);
tree* minimum(tree *root);
tree* delete(tree *root, void* x, fType compare);
void clean(tree *root, fType compare);

#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

int StringCompare(void *a, void *b){
	return strcmp((char*)a, (char*)b);
}

void print(tree *head){
	if (head == NULL) return;
	print(head->left);
	printf("%s\n", (char*)head->value);
	print(head->right);
}

int main(){
	tree *head = NULL;
	char x[20];
	while (scanf("%s", &x) > 0){
		add(&head, &x, StringCompare, 20);
	}
	print(head);
	printf("rank = %d", rank(head, StringCompare, (head->right)->value));
	printf("\n");
	clean(head, StringCompare);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int len=0;
	if(head!=NULL){

		while(head!=NULL){
			head = head->next;
			len++;
		}	
	}
	return len;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head){
	int len = length(head);
	char * strptr = (char*)malloc((len + 1)*sizeof(char));
		while(head!=NULL && strptr !=NULL){
			for(int i= 0; i<len; i++){
				strptr[i] = head->letter;
				head= head->next;

			}
		}	
	return strptr;
	
	
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	
	node * temp = (node*)malloc(sizeof(node));
	node * current;
	temp->letter= c;
	temp->next=NULL;
	
	if(*pHead == NULL){
		*pHead=current=temp;
	}
	else{
		current->next = temp;
		current = temp;
	}
	
	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while (*pHead!=NULL){
		node *current;
		current = *pHead;
		*pHead = current->next;
		free(current);
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
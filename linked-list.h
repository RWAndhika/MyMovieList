#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// ==================== DECLARATIONS ====================

void enqueue(WLNodePtr *, WLNodePtr *, int);
void dequeue(WLNodePtr *, WLNodePtr *);
void deletePos(WLNodePtr *, int);
int isEmpty(WLNodePtr);

// ==================== DEFINITIONS =====================

void enqueue(WLNodePtr *headPtr, WLNodePtr *tailPtr, int select) {
	WLNodePtr newPtr;
	
	newPtr = (WLNode *)malloc(sizeof(WLNode));
	
	if(newPtr != NULL) {
		strcpy(newPtr->title, mv[select].title);
        newPtr->year = mv[select].year;
		newPtr->nextPtr = NULL;
		
		if(isEmpty(*headPtr)) *headPtr = newPtr;
		else (*tailPtr)->nextPtr = newPtr;
		
		*tailPtr = newPtr;
	} else {
		printf("\nSelected movie not inserted. No memory available.");
		holdScreen();
	}
}

void dequeue(WLNodePtr *headPtr, WLNodePtr *tailPtr) {
	WLNodePtr tempPtr;
	
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;
	
	if(*headPtr == NULL) *tailPtr = NULL;
	
	free(tempPtr);
	tempPtr = NULL;
}

void deletePos(WLNodePtr *headPtr, int position) {
	WLNodePtr current = *headPtr;
	WLNodePtr previous = *headPtr;

	if(*headPtr == NULL) {
		return;
	} else if(position == 1) {
		*headPtr = current->nextPtr;
		free(current);
		current = NULL;
	} else {
		while(position != 1) {
			previous = current;
			current = current->nextPtr;
			position--;
		}
		previous->nextPtr = current->nextPtr;
		free(current);
		current = NULL;
	}
}

int isEmpty(WLNodePtr headPtr) {
	return headPtr == NULL;
}

#endif
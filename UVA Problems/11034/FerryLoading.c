/**********************************************************************
Program: UVA Problem 11034
Author: Yorgo A. Kennos
Date: 3/17/2019
Purpose: The purpose of this program is to implement a linkedlist based queue to determine the number of trips a Ferry needs to make. 
The Ferry length is specified and then the Cars and queued onto either side of a river and their car lengths are specified. Once all 
of the vehicles are queued the ferry then loads as many as possible in order, dequeues them and moves to the other side of the river 
to queue more cars. Each time the Ferry unloades the counter is incremented. After each case the number of trips needed to make is 
printed followed by a newline.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node;
typedef struct node Node;

struct node {
	int data;
	Node* next;

};

void enqueue(Node**, int);
void dequeue(Node**);
void print_list(Node*);
void destory(Node**);
int top(Node**);


int main(int argc, char* argv[]) {

	/*initialize left and right queues for cars*/
	Node* leftQueue = NULL;
	Node* rightQueue = NULL;

	int i, j;
	int index = 0;
	int output[100];
	int count = 0;
	int c;
	int l, m;  /*l: length of ferry in m   m: # of cars*/
	char side[100]; /*reading which side of the river*/
	int size; /*vehicle size*/

	/*c determines the number of test cases to run*/
	/*printf("# of Test Cases: ");*/
	scanf("%d", &c);


	/*keep looping for every test case*/
	for (j = 0; j < c; j++) {

		count = 0; /*reset ferry count for each case*/

		/*l: length of ferry      m: # of cars*/
		/*printf("Length of Ferry, # of cars: ");*/
		scanf("%d %d", &l, &m);

		int temp = l * 100; /*temp to reset after each unload*/
		l *= 100; /*getting length of Ferry in cm since car lengths are in cm*/

		/*queueing the entered car lengths and side of the river into each respective queue*/
		for (i = 0; i < m; i++) {
			
			scanf("%d %s", &size, side);


			/*left side of the river*/
			if (strcmp(side, "left") == 0) {
				if (size > l) {
					printf("Cannot transport a vehicle larger than the Ferry!\n");
					exit(1);
				}
				enqueue(&leftQueue, size);

			}

			/*right side of the river*/
			if (strcmp(side, "right") == 0) {
				if (size > l) {
					printf("Cannot transport a vehicle larger than the Ferry!\n");
					exit(1);
				}
				enqueue(&rightQueue, size);
			}



		}

		/*section that determines the number of trips the ferry needs to make*/
		while (leftQueue != NULL || rightQueue != NULL) {

			/*if there are only cars on the right side of the river*/
			if (leftQueue == NULL && rightQueue != NULL) {

				/*move to the right side of the river*/
				count++;

				while ( l - (top(&rightQueue)) >= 0 && (top(&rightQueue) != 0)) {
					l -= top(&rightQueue);
					dequeue(&rightQueue);
				}

				if (top(&rightQueue) == 0) {
					count++;
				}

				else {
					count++;
					l = temp;
				}
			}

			/*if there are only cars on the left side of the river*/
			else if (rightQueue == NULL && leftQueue != NULL) {

				while (l - top(&leftQueue) >= 0 && top(&leftQueue) != 0) {
					l -= top(&leftQueue);
					dequeue(&leftQueue);
				}

				/*if there are no more cars to load*/
				if (top(&leftQueue) == 0) {
					count++;
				}

				else {
					/*move the ship twice*/
					count += 2;
					/*reset cargo size*/
					l = temp;
				}

			}

			/*the case where neither pier is empty*/
			else if(rightQueue != NULL && leftQueue != NULL){

				while (l - top(&leftQueue) >= 0 && top(&leftQueue) != 0) {
					l -= top(&leftQueue);
					dequeue(&leftQueue);
				}
				count++;
				l = temp;

				while (l - top(&rightQueue) >= 0 && top(&rightQueue) != 0) {
					l -= top(&rightQueue);
					dequeue(&rightQueue);
				}
				count++;
				l = temp;


			}




		}

		printf("%d\n", count);

	}



	/*destory the left and right queues after program before the end of main*/
	destory(&leftQueue);
	destory(&rightQueue);




	return 0;
}

int top(Node** pHead) {
	Node* temp = *pHead;

	if (temp == NULL) {
		return 0;
	}

	return temp->data;
}

void enqueue(Node** pHead, int item) {
	Node* temp;

	/*if list is empty*/
	if (*pHead == NULL) {
		*pHead = (Node*)malloc(sizeof(Node));
		(*pHead)->data = item;
		(*pHead)->next = NULL;
	}
	else {
		temp = *pHead;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = (Node*)malloc(sizeof(Node));

		if (temp->next == NULL) {
			printf("Error allocating memory for node.\n");
			exit(EXIT_FAILURE);
		}

		temp->next->data = item;
		temp->next->next = NULL;
	}
}

void dequeue(Node** pHead) {
	if (*pHead == NULL) {
		return;
	}

	Node* temp = *pHead;
	*pHead = (*pHead)->next;

	free(temp);

}

void print_list(Node* head) {

	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}

}

void destory(Node** pHead) {
	Node* temp;

	while (*pHead != NULL) {
		temp = *pHead;
		*pHead = (*pHead)->next;
		free(temp);
	}
}

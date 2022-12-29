#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

typedef struct{
	int cnt;
	struct node *front,*rear;
}queue;

struct node{
	
	int data;
	struct node *next;
};

void initialize(queue *q){
	q->cnt=0;
	q->front=q->rear=NULL;
}

int isFull(queue *q){
	if(q->cnt==QUEUE_SIZE)
		return 1;
	else
		return 0;
		
}

int isEmpty(queue *q){
	if(q->cnt==0)
		return 1;
	else
		return 0;
}

void enqueue(queue *q,int x){
	if(isFull(q))
		printf("queue is full");
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node*));
		temp->data=x;
		temp->next=NULL;
		
		if(isEmpty(q)) // hic deger yoksa
			q->front=q->rear=temp;
		else{
			q->rear->next=temp;
			q->rear=temp;
		}
		q->cnt++;
		
	}
}

int dequeue(queue *q){
	if(isEmpty(q)){
	
		printf("queue is empty"); 
		return -100;
	}else{
		int x=q->front->data;
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp=q->front;
		q->front=temp->next;
		free(temp);
		q->cnt--;
		
		return x;
	}
}

void print(queue *q){
//	int i =q->front;
	
/*	while(q->rear!=QUEUE_SIZE+1){
		printf("%d",q->rear->data);
		q->rear=q->rear->next;
	} */
	printf("values of queue\n");
	while(q->front!=QUEUE_SIZE){
		printf("\n\t%d\n",q->front->data);
		q->front=q->front->next;
	} 
}

int main(){
	
	queue *q=malloc(sizeof(q));
	initialize(q);
	enqueue(q,5);
	enqueue(q,7);
	enqueue(q,9);
		
	dequeue(q);
	
	print(q);
}



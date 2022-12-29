#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5


typedef struct{
	
	int cnt;
	int front,rear;
	int data[QUEUE_SIZE];
}queue;

struct node{
	
	int data;
	struct node *next;
};

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

void initialize(queue *q){
	int cnt=0;
	q->front=0;
	q->rear=-1;
	
}

void enqueue(queue *q,int x){
	if(isFull(q))
		printf("queue is full");
	else{
		q->cnt++;
		q->rear++;
		
		if(q->rear==QUEUE_SIZE)
			q->rear=0;
		x = q->data[q->rear];
		
	}
	
}

int dequeue(queue *q){
	if(isEmpty(q))
		printf("queue is empty");
	else{
		int x=q->data[q->front];
		q->front++;
		q->cnt--;
		
		if(q->front==QUEUE_SIZE)
			q->front=0;  	// ???????????????
			
		return x;
	}

	
}

void print(queue *q){
	
	int cnt=0;
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	temp=q->front;
	
	while(temp!=QUEUE_SIZE){
		printf("\n\t%d",q->data[q->cnt]);
		cnt++;
		temp=temp->next;
	}
}

int main(){
	
	queue *q=malloc(sizeof(q));
	enqueue(q,8);
	enqueue(q,4);
	enqueue(q,3);
	enqueue(q,1);
	enqueue(q,6);
	
	dequeue(q);
	dequeue(q);
	dequeue(q);
	
	print(q);
}

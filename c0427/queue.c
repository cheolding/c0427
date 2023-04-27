#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;
// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1); // [juht] ���α׷� ����� ������ ���� ó��
}
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		//error("ť�� ��ȭ�����Դϴ�.");
		//return; // [juht] �ǹ� ����
		fprintf(stderr, "ť�� ��ȭ�����Դϴ�\n");
		return;
	}
	q->data[++(q->rear)] = item;
}
int dequeue(QueueType* q) // [juht] element dequeue(QueType *q)
{
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ��������Դϴ�\n");
		return;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main(void)
{
	
	QueueType q;
	init_queue(&q);
	int item = 0;
	int input;
	while (1)
	{
		printf("\n\n1.Input data and Enqueue\n2.Dequeue and print data\n3.Print Queue\n4.Exit\nSelect number :");
		scanf("%d", &input);


		if (input == 1)
		{
			int num;
			printf("Input the Data : ");
			scanf("%d",&num);

			enqueue(&q, num);
			printf("Enqueue : %d", num);
		}
		else if (input == 2)
		{
			item = dequeue(&q);
			printf("Dequeue : %d", item);

		}
		else if (input == 3)
		{
			printf("front = %d  rear = %d\n", q.front+1, q.rear+1);
			for (int i = q.front+1; i <=q.rear; i++)
			{
				printf("%d ", q.data[i]);
			}
			printf("\n");
		}
		else if (input == 4)
		{
			printf("Exit the Program");
			break;
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

/* 定义节点结构体 */
typedef struct node {
    int data;  // 数据
    struct node* next;  // 指向下一个节点的指针
} Node;

/* 定义队列结构体 */
typedef struct queue {
    Node* front;  // 队头指针
    Node* rear;  // 队尾指针
} Queue;

/* 初始化队列 */
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

/* 判断队列是否为空 */
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

/* 入队 */
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

/* 出队 */
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Error: Queue is empty!\n");
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    return data;
}

/* 打印队列 */
void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    Node* temp = q->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printQueue(&q);

    dequeue(&q);

    printQueue(&q);

    return 0;
}


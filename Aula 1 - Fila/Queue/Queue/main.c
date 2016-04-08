//
//  main.c
//  Queue
//
//  Created by Fabricio Serralvo on 4/4/16.
//  Copyright © 2016 Fabricio Serralvo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int capacity;
    int size;
    int first;
    int last;
    int *elements;
};

typedef struct queue Queue;

Queue* createQueue(int maxElements) {
    
    // Criação e alocação da fila
    Queue *newQueue = NULL;
    newQueue = (Queue *)malloc(sizeof(Queue));
    
    // Definição dos atributos
    // É necessário reservar espaço para os elementos da fila
    newQueue->elements = (int *)malloc((int)maxElements);
    newQueue->size = 0;
    newQueue->capacity = maxElements;
    newQueue->first = 0;
    newQueue->last = -1;
    
    return newQueue;
}

void enqueueElement(Queue* q, int element) {
    
    // Antes de adicionar um novo elemento na fila é necessário
    // checar se a mesma possui
    if (q->size == q->capacity) {
        printf("A fila está cheia 😕\n");
        return;
    }
    
    q->size++;
    q->last = q->last + 1;
    
    if (q->last == q->capacity) {
        q->last = 0;
    }
    
    q->elements[q->last] = element;
    
}

void dequeueElement(Queue* q) {
    
    // É necessário verificar se a fila possui algum elemento antes
    // de tentar remover
    
    if (q->size == 0) {
        printf("A fila está vazia, não é possível remover elementos");
        return;
    }

    q->size--;
    q->first++;
    
    if (q->first == q->capacity) {
        q->first = 0;
    }
    
}

void printQueue(Queue *q) {
    
    if (q->size <= 0) {
        printf("A fila está vazia\n");
        return;
    }
    
    printf("Conteúdo da fila: \n");
    
    for (int i = 0; i < q->size; i++) {
        printf("Valor: %d\n", q->elements[i]);
    }
    
}

int main(int argc, const char * argv[]) {
    
    Queue *q = createQueue(5);
    enqueueElement(q, 5);
    enqueueElement(q, 10);
    enqueueElement(q, 12);
    enqueueElement(q, 25);
    enqueueElement(q, 30);
    printQueue(q);
    dequeueElement(q);
    dequeueElement(q);
    printQueue(q);
    
    return 0;
}

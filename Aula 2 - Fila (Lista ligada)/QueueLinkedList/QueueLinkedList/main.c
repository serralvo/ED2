//
//  main.c
//  QueueLinkedList
//
//  Created by Fabricio Serralvo on 4/12/16.
//  Copyright © 2016 Fabricio Serralvo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[30];
    struct Item* next;
};

struct Item* first = NULL;
struct Item* last = NULL;

void enqueue(char itemName[30]) {
    
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    
    // Atribuição de valores
    strcpy(newItem->name, itemName);
    newItem->next = NULL;
    
    if (first == NULL && last == NULL) {
        // Se a fila ainda não possuir nenhum item, tanto o primeiro
        // quanto o último valor receberá o novo carro
        first = newItem;
        last = newItem;
        return;
    }
    
    last->next = newItem;
    last = newItem;
}

void dequeue() {
    
    struct Item* selectedItem = first;
    
    if (first == NULL) {
        printf("O lava rápido está vazio");
        return;
    }
    
    if (first == last) {
        first = last = NULL;
    } else {
        first = first->next;
    }
    
    // Após a remoção é necessário desalocar a memória reservada para o primeiro elemento da fila
    free(selectedItem);
}

void printQueue() {
    
    struct Item* itemToBePrinted = first;
    
    while(itemToBePrinted != NULL) {
        printf("Item na fila: %s \n", itemToBePrinted->name);
        // Após exibir o item é necessário apontar para o próximo item da fila
        itemToBePrinted = itemToBePrinted->next;
    }
    
}

int main(){
    enqueue("Brazil");
    enqueue("Argentina");
    enqueue("Peru");
    enqueue("Colombia");
    printQueue();
    dequeue();
    printQueue();
}
//
//  main.c
//  Stack
//
//  Created by Fabricio Serralvo on 4/2/16.
//  Copyright © 2016 Fabricio Serralvo. All rights reserved.
//

#include <stdio.h>

#define kStackMaxSize 10

struct stack {
    int data[kStackMaxSize];
    int size;
};

typedef struct stack stack;

void push(stack *s, int value) {
    
    // É necessário verificar se a pilha não está cheia antes
    // de fazer a inserção do novo valor
    
    if (s->size < kStackMaxSize) {
        s->data[s->size++] = value;
    } else {
        // A pilha já esta cheia, nada para fazer aqui
    }
}

void pop(stack *s) {
    
    // Antes de remover um item da pilha é necessário checar
    // se a mesma possui algum item
    
    if (s->size == 0) {
        // Pilha vazia, nada para fazer aqui
    } else {
        s->size--;
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

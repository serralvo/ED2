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

typedef struct stack Stack;
Stack myStack;

void push(int value) {
    
    // É necessário verificar se a pilha não está cheia antes
    // de fazer a inserção do novo valor
    
    if (myStack.size < kStackMaxSize) {
        printf("Adição do valor %d na pilha\n", value);
        myStack.data[myStack.size++] = value;
    } else {
        printf("Pilha cheia 😕 - Nenhum elemento será adicionado\n");
    }
}

void pop() {
    
    // Antes de remover um item da pilha é necessário checar
    // se a mesma possui algum item
    
    if (myStack.size == 0) {
        printf("Pilha vazia 😕 - Nenhum elemento para remover\n");
    } else {
        myStack.size--;
    }
}

void print() {
    
    if (myStack.size > 0) {
        printf("Conteúdo da pilha: \n");
        for (int i = 0; i < myStack.size; i++) {
            printf("Valor: %d\n", myStack.data[i]);
        }
    } else {
        printf("Pilha vazia 😕\n");
    }
    
}

int main(int argc, const char * argv[]) {
    
    // Inclusão de alguns valores
    push(1);
    push(2);
    push(3);
    push(5);
    push(8);
    
    // Remoção do último valor (8)
    pop();
    
    // Exibição do conteúdo da pilha
    print();
    
    return 0;
}

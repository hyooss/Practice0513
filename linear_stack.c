#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

void linear_stack_push(stackType*stack) {

    // push 연산
    //스택의 top을 증가시킨 후 top의 위치에 item 설정

    //스택이 가득 찼을 경우
    if (stack->top==MAX_SIZE-1) {
        printf("Stack is Full\n");
        return;
    }

    stack->top++; //top = top + 1
    stack->data[stack->top]=item;

}

void linear_stack_pop(stackType*stack) {
    int popItem;

    //pop
    popItem = stack->data[stack->top];
    stack->top--;
    printf("Pop Item: %d\n,popItem");
}

typedef stack{
    int data[MAX_SIZE];
    int top;
}stackType;

void linear_stack_display(stackType*stack) {
    //배열에 있는 데이터를 top의 위치까지 탐색하여 출력
    int index;
    printf("Linear Stack= [");
    for (index = 0; index <= stack->top; index++) {
        printf("%d, ", stack->data[index]);
        if (index!=stack->top) {
            printf(" | ");
        }
    }
    printf("]");
}

void linear_stack_menu(stackType*stack) {
    while (1) {
        printf("Linear Stakc: 1. Push , 2. Pop , 3. Display 4.Exit\n");
        printf("Input Menu ? ");
        int menu;
        int item;

        scanf("%d",&menu);

        if (menu == 1) {
            printf("Push Item?");
            scanf("%d",&item);
            linear_stack_push(stack,item);
        }
        else if (menu == 2) {
            linear_stack_pop(stack);
        }
        else if (menu == 3) {
            linear_stack_display(stack);
        }
        else if (menu == 4) {
            printf("Exit\n");
            break;
        }
        else {
            printf("Menu error\n");
        }
    }
}

stackType* linear_stack_init(void) {
    stackType*stack=(stackType*)malloc(sizeof(stackType));
    stack->top=-1;    // 스택의 초기화(비어있음)
    return stack;
}

int main(void) {
    //배열을 사용한 스택
    stackType* stack=linear_stack_init();
    linear_stack_menu(stack);
    free(stack);

    return 0;
}

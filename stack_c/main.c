#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// global variables and static variables are all in static area, .bss
struct simple_stack {
   int* data;    //栈底指针？
   int size;
   int capacity;
};
//把n进栈
void _push(struct simple_stack* s, int n) {
   if (s->size > s->capacity) {
       realloc(s->data, s->capacity << 1);
       s->capacity *= 2;
   }

   *(s->data + s->size) = n;
   s->size++;
}


void push(struct simple_stack* s, int n){
    if(s->size>s->capacity){
        realloc(s->data, s->capacity<<1);
        s->capacity *= 2;
    }
    *(s->data + s->size) = n;
    s->size++;
}


int* pop(struct simple_stack* s) {
   if (s->size <= 0) {
     return NULL;
   }
   --s->size;
   return s->data + s->size;
}

int* _pop(struct simple_stack*s){
    if(s->size <=0){
        return NULL;
    }
    --s->size;
    return s->data + s->size;
}


void print_stack(struct simple_stack* s) {
   int l = s->size - 1;
   while (l >= 0) {
      printf("%d, ", *(s->data + l));
      l--;
   }
}

void _int_stack(struct simple_stack* s) {
    int l = s->size-1;
    while (l >= 0) {
       printf("%d ", *(s->data+l));
       l--;
    }

}

//如何用o(1)时间判断出一个栈的最小最大值
struct el {
   int data;
   int min;
   int max;
};

struct min_max_stack {
   struct el* arr;
   int size;
   int capacity;
};

int stack_min(struct min_max_stack* s) {
   return (s->arr + (s->size - 1))->min;
}

int stack_max(struct min_max_stack* s) {
    return (s->arr + (s->size - 1))->max;
}

void stack_push(struct min_max_stack* s, struct el* n) {
   *(s->arr + s->size) = *n;
   s->size++;
}

struct el* stack_pop(struct min_max_stack* s){
    --(s->size);
    return (s->arr + s->size);
};

struct _el {
    int data;
    int min;
    int max;
};

struct _min_max_stack {
    struct el* arr;
    int size;
    int capacity;
};

int _stack_min(struct min_max_stack* s) {
    return (s->arr + (s->size - 1))->min;
}

int _stack_max(struct min_max_stack* s) {
    return (s->arr + s->size - 1)->max;
}

int _stack_push (struct min_max_stack* s , struct el* n) {
     *(s->arr + s->size) = *n;
     s->size++;
}

int main()
{
    struct simple_stack s;
    s.data = (int*)malloc(2 * sizeof(int));
    s.size = 0;
    s.capacity = 2;

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    print_stack(&s);
    printf("\n");

    int* e = pop(&s);
    printf("Popped: %d\n", *e);

    print_stack(&s);

    printf("Hello world!\n");
    return 0;
}

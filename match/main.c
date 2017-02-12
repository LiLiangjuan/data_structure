#include <stdio.h>
#include <stdlib.h>

struct match_stack {
   char* data;
   int size;
   int capacity;
};

void push_char(struct match_stack* s, char c) {
    if (s->size >= s->capacity) {
        s->data = (char*)realloc(s->data, s->capacity * 2);
        if (s->data) {
            s->capacity = s->capacity * 2;
        }
    }
   *(s->data + s->size) = c;
   s->size++;
}

char pop_char(struct match_stack* s) {
    s->size--;
    return *(s->data + s->size);
}

int main()
{
    char* s = "{{}{}{()[](()}{[][()]}}";

    struct match_stack ss;
    ss.capacity = 2;
    ss.data = (char*) malloc(2 * sizeof(char));
    ss.size = 0;
    char* p = s;
    while(*p != '\0') {
        char c = *p;
        p++;
        if (c == '(' || c == '[' || c == '{') {
           push_char(&ss, c);
        } else {
           char left = pop_char(&ss);
           if (left == '(' && c == ')') {
               printf("matched\n");
               continue;
           }

           if (left == '[' && c == ']') {
               printf("matched\n");
               continue;
           }

           if (left == '{' && c == '}') {
               printf("matched\n");
               continue;
           }

           printf("Mismatch found: left: %c, right: %c", left, c);
           break;
        }
    }

    printf("Hello world!\n");
    return 0;
}

#include <iostream>
using namespace std;

typedef char element;

class stack {
  private:
    element data; // 담을 데이터, 요소값
    stack *link;  // 다음 링크

  public:
    stack *top, *prev, *ptr; // 탑 노드, 현재 노드

    stack() {
        link = NULL;
        top = NULL;
        ptr = NULL;
    }

    void push(element datum) {
        stack *newStack = new stack();
        newStack->data = datum;
        newStack->link = top;
        top = newStack;
    }

    void pop() {
        element datum;
        stack *temp = top;

        if (ptr == NULL) { // 스택이 비었을 경우
            cout << "stack is empty!" << endl;
            exit(0);
        }
        else { // 스택에 요소가 있는 경우
            datum = temp->data;
            top = temp->link;
            free(temp);
            // return datum;
        }
    }
};

void stack::in2post(char *strings) {
    element datum;
    stack newStack;

    newStack.push('#');
    for (int i = 0; i < sizeof(*strings); i += 1) {
        newStack.push(strings[i]);
    }

    ptr = top;
    while (ptr != NULL) {
        if ()
            datum = newStack.pop();
    }
}

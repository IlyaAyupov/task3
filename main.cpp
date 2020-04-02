#include <iostream>
struct Node {
    int value;
    struct Node *next;
};

struct Node* cycleStart(struct Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    else if (head->next == head) return head;
    struct Node* pointer1 = head;
    struct Node* pointer2 = head;
    while (pointer2 != NULL) {
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
        if (pointer2 != NULL) pointer2 = pointer2->next;
        if (pointer1 == pointer2) break;
    }
    if (pointer2 == NULL) return NULL;
    while (head != pointer2) {
        head = head->next;
        pointer2 = pointer2->next;
    }
    return head;
}

int main() {
    auto* head=new Node{0,NULL};
    struct Node* itter=head;
    void* start;
    for(int i=1;i<10;i++){
        itter->next=new Node{i,NULL};
        itter=itter->next;
        if(i==5)start=itter;
    }
    itter->next=(Node*)start;

    std::cout<<cycleStart(head)->value;
    return 0;
}

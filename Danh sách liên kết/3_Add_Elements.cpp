
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// tạo danh sách liên kết đơn

struct linkedList {
    Node *head; // phần tử đầu
    Node *tail; // phần tử cuối
};

void createList(linkedList &l) {
    l.head = NULL; // vì mới tạo danh sách nên chưa có phần tử nào
    l.tail = NULL;
}

linkedList list;
createList(list); // gán head và tail bằng NULL



// Thêm phần tử vào danh sách liên kết trong C++


//! thêm vào đầu danh sách:

void addHead() {

}





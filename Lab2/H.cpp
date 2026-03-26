#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

// вставка узла node в позицию p
Node* insert(Node* head, Node* node, int p){
    if (p == 0){            // вставка в начало
        node->next = head;
        return node;
    }
    Node* cur = head;
    for (int i=0; i<p-1 && cur; i++) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;
}

// удаление узла в позиции p
Node* remove(Node* head, int p){
    if (!head) return nullptr;
    if (p == 0){
        Node* tmp = head->next;
        delete head;
        return tmp;
    }
    Node* cur = head;
    for (int i=0; i<p-1 && cur; i++) cur = cur->next;
    Node* del = cur->next;
    cur->next = del->next;
    delete del;
    return head;
}

// перемещение узла с позиции p1 в позицию p2
Node* replace(Node* head, int p1, int p2){
    if (!head || p1 == p2) return head;
    // 1. Вырезаем узел p1
    Node* extracted;
    if (p1 == 0){
        extracted = head;
        head = head->next;
    } else {
        Node* cur = head;
        for (int i=0; i<p1-1; i++) cur = cur->next;
        extracted = cur->next;
        cur->next = extracted->next;
    }
    // 2. Вставляем узел в p2 (позиция после удаления!)
    if (p2 == 0){
        extracted->next = head;
        head = extracted;
    } else {
        Node* cur = head;
        for (int i=0; i<p2-1; i++) cur = cur->next;
        extracted->next = cur->next;
        cur->next = extracted;
    }
    return head;
}

// реверс всего списка
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    while (cur){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// печать списка
void print(Node* head){
    if (!head){
        cout << -1 << '\n';
        return;
    }
    Node* cur = head;
    while (cur){
        cout << cur->val;
        if (cur->next) cout << ' ';
        cur = cur->next;
    }
    cout << '\n';
}

// циклический сдвиг влево на x
Node* cyclic_left(Node* head, int x){
    if (!head || !head->next || x==0) return head;
    // находим длину и хвост
    int n = 1;
    Node* tail = head;
    while (tail->next){
        tail = tail->next;
        n++;
    }
    x %= n;
    if (x == 0) return head;
    // делаем список кольцом
    tail->next = head;
    // находим новый хвост (n - x) раз от начала? (для left: x от начала)
    Node* newTail = head;
    for (int i=0; i<x-1; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

// циклический сдвиг вправо на x
Node* cyclic_right(Node* head, int x){
    if (!head || !head->next || x==0) return head;
    // посчитаем длину
    int n = 1;
    Node* tail = head;
    while (tail->next){
        tail = tail->next;
        n++;
    }
    x %= n;
    if (x == 0) return head;
    // сдвиг вправо на x = сдвиг влево на n - x
    int left = n - x;
    tail->next = head;
    Node* newTail = head;
    for (int i=0; i<left-1; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

int main(){
    Node* head = nullptr;
    while (true){
        int command; 
        if(!(cin >> command)) break;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}

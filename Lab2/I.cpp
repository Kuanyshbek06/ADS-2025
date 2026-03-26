#include <bits/stdc++.h>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node* prev;
    Node(const string &v): val(v), next(nullptr), prev(nullptr) {}
};

struct Deque {
    Node* head = nullptr;
    Node* tail = nullptr;
    int sz = 0;

    void add_front(const string &x){
        Node* node = new Node(x);
        if (!head){
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        sz++;
        cout << "ok\n";
    }

    void add_back(const string &x){
        Node* node = new Node(x);
        if (!tail){
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz++;
        cout << "ok\n";
    }

    void erase_front(){
        if (!head){
            cout << "error\n";
            return;
        }
        cout << head->val << '\n';
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        sz--;
    }

    void erase_back(){
        if (!tail){
            cout << "error\n";
            return;
        }
        cout << tail->val << '\n';
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
        sz--;
    }

    void front(){
        if (!head) cout << "error\n";
        else cout << head->val << '\n';
    }

    void back(){
        if (!tail) cout << "error\n";
        else cout << tail->val << '\n';
    }

    void clear(){
        while (head){
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        sz = 0;
        cout << "ok\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Deque dq;
    string cmd;
    while (cin >> cmd){
        if (cmd == "add_front"){
            string x; cin >> x;
            dq.add_front(x);
        } else if (cmd == "add_back"){
            string x; cin >> x;
            dq.add_back(x);
        } else if (cmd == "erase_front"){
            dq.erase_front();
        } else if (cmd == "erase_back"){
            dq.erase_back();
        } else if (cmd == "front"){
            dq.front();
        } else if (cmd == "back"){
            dq.back();
        } else if (cmd == "clear"){
            dq.clear();
        } else if (cmd == "exit"){
            cout << "goodbye\n";
            break;
        }
    }
    return 0;
}

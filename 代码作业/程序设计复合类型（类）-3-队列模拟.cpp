#include <iostream>
#include <string>
using namespace std;
class MyQueue {
private:
    int data[25]; 
    int front, rear; 
public:
    MyQueue() {
        front = 0;
        rear = 0;
    }
    bool empty() const {
        return front == rear;
    }
    bool full() const {
        return (rear - front) >= 20;
    }
    void push(int x) {
        if (full()) return;
        data[rear++] = x;
    }
    void pop() {
        if (empty()) {
            cout << "Error" << endl;
        } else {
            cout << data[front++] << endl;
        }
    }
    void getMax() const {
        if (empty()) {
            cout << "Error" << endl;
            return;
        }
        int m = data[front];
        for (int i = front + 1; i < rear; i++) {
            if (data[i] > m) m = data[i];
        }
        cout << m << endl;
    }
    void getMin() const {
        if (empty()) {
            cout << "Error" << endl;
            return;
        }
        int m = data[front];
        for (int i = front + 1; i < rear; i++) {
            if (data[i] < m) m = data[i];
        }
        cout << m << endl;
    }
    void search(int x) const {
        for (int i = front; i < rear; i++) {
            if (data[i] == x) {
                cout << "true" << endl;
                return;
            }
        }
        cout << "false" << endl;
    }
};
int main() {
    MyQueue q;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (cmd == "pop") {
            q.pop();
        } else if (cmd == "max") {
            q.getMax();
        } else if (cmd == "min") {
            q.getMin();
        } else if (cmd == "search") {
            int x;
            cin >> x;
            q.search(x);
        } else if (cmd == "quit") {
            break;
        }
    }
    return 0;
}

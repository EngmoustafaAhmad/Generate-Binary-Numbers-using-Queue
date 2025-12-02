#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        // Step 1: push to q2
        q2.push(x);

        // Step 2: move everything from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: swap q1 and q2
        swap(q1, q2);
    }

    // Remove top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    // Return top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // 30

    s.pop(); // pops 30

    cout << "Top: " << s.top() << endl; // 20

    return 0;
}

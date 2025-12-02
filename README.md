Generate Binary Numbers Using a Queue
📝 Problem Description

Given a number N, generate and print all binary numbers from 1 to N in increasing order.

Example:

For N = 5, the output should be:

1  
10  
11  
100  
101

🎯 Goal

Use a queue to generate binary numbers in sequence without converting numbers manually.

💡 Algorithm Explanation

We use a queue of strings:

Start by pushing "1" into the queue.

Repeat the steps below N times:

Pop the front of the queue → this is the next binary number.

Print it.

Attach "0" to it and push back into the queue.

Attach "1" to it and push back into the queue.

This produces a perfect binary sequence like a binary tree.

🧠 Why This Works

This method is based on generating numbers level-by-level—similar to Breadth-First Search (BFS) on a binary tree:

        "1"
       /   \
    "10"   "11"
     / \      / \
 "100" "101" "110" "111"


A queue naturally handles this BFS order.

🧾 C++ Implementation
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinary(int N) {
    queue<string> q;

    q.push("1");  // first binary number

    for (int i = 1; i <= N; i++) {
        string current = q.front();
        q.pop();

        cout << current << endl;

        // Generate next two numbers
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    generateBinary(N);

    return 0;
}

▶️ Sample Run

Input:

5


Output:

1
10
11
100
101

📚 Time Complexity

O(N) for generating numbers

Each operation is constant because string operations are small

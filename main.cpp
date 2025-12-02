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

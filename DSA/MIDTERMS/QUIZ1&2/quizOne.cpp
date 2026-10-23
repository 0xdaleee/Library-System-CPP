#include <iostream>
#include <queue>

int main() {
    std::queue<int> studentQueue;

    studentQueue.push(101);
    studentQueue.push(102);
    studentQueue.push(103);

    std::cout << "Next student to be served: "
              << studentQueue.front() << '\n';

    studentQueue.pop();

    std::cout << "Next student in line: "
              << studentQueue.front() << '\n';

    return 0;
}

#include <iostream>
using namespace std;

    class OrderQueue {
    private:
    string orders[5];
    int front;
    int rear;

    public:
    OrderQueue() {
    front = 0;
    rear = -1;

    }


    void removeOrder() {
    if (front > rear) {
    cout << "No orders available." << endl;
    } else
     {
    cout << "Preparing: " << orders[front] << endl;
    front++;

    void showNextOrder() {
    if (front > rear) {
    cout << "No orders available." << endl;
    } else 
    cout << "Next order: " << orders[front] << endl;
}
    


    }

    bool isEmpty() {
    return front > rear;
    }

int main(){
    return 0;
}
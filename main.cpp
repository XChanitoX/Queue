#include "Queue.h"
using namespace std;

int main() {
    Queue<int> cola = Queue<int>();
    cola.insertElement(1);
    cola.insertElement(2);
    cola.insertElement(3);
    cola.insertElement(4);
    cola.insertElement(5);
    cola.printQueue();
    cola.popElement();
    cola.printQueue();
    cola.insertElement(4);
    cola.insertElement(5);
    cola.printQueue();
    return 0;
}
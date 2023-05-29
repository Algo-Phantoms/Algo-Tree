#include<iostream>
using namespace std;

// Structure for Queue
class Queue {
    private:
        int front;
        int rear;
        int size;
        int* arr = new int [size];
    
    public:
        // Default constructor
        Queue(){}

        // initializing the variables
        Queue(int capacity) {
            front = -1;
            rear = -1;
            size = capacity;
            for (int i = 0; i < size; i++) {
                arr[i] = 0;
            }
        }

        bool isEmpty() {
            // if values are -1 means no element yet
            if(front == -1 && rear == -1)
                return true;
            else    
                return false;
        }
        
        bool isFull() {
            if(rear == size-1)
                return true;
            else    
                return false;
        }

        void enqueue(int val) {
            if(isFull()) {
                // check if the Q is already full or not 
                cout << "Queue is full" << endl;
                return;
            }
            else if(isEmpty()) {
                // adding to the queue first time 
                front = 0;
                rear = 0; 
            }
            else {
                // general case
                rear++;
            }
            // assign the value
            arr[rear] = val;
        }
        
        int dequeue() {
            int temp;
            if(isEmpty()) {
                // check if the Q is already empty or not 
                cout << "Queue is empty" << endl;
                return 0;
            }
            else if(front == rear) {
                // we only have a single element **** !important case
                temp = arr[rear];
                arr[rear] = 0;
                front = rear = -1;
                return temp;
            }
            else {
                // remove the first and move front to next
                temp = arr[front];
                arr[front] = 0;
                front++;
                return temp;
            }
        }

        // returns number of elements at any given instance
        int count() {
            if(isEmpty()) 
                return 0;
            else
                return (rear-front+1);
        }
        
        void display() {
            for (int i = 0; i <= size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // Destructor
        ~Queue() {}
};

int main(){
    
    // input the maximum size
    int n;
    cout << "Enter the maximum capacity of queue: ";
    cin >> n;
    
    // Initializing the object for using Queue
    Queue q = Queue(n);

    // For dynamic interface see the driver program below     
    int option, value;
    
    do {
        cout << "Enter 0 to exit" << endl;
        cout << "1. Enqueue()" << endl; 
        cout << "2. Dequeue()" << endl; 
        cout << "3. isEmpty()" << endl; 
        cout << "4. isFull()" << endl; 
        cout << "5. count()" << endl; 
        cout << "6. display()" << endl; 
        cout << "7. Clear Screen" << endl;

        cin >> option;
        switch(option){
            case 0:
                break;
            case 1:
                cout << "Enter item to enqueue" << endl;
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                cout << "Dequeue called. Dequeued value: " << q.dequeue() << endl;
                break;
            case 3:
                if(q.isEmpty())
                    cout << "Queue empty" << endl;
                else 
                    cout << "Queue NOT empty" << endl;
                break;
            case 4:
                if(q.isFull())
                    cout << "Queue full" << endl;
                else 
                    cout << "Queue NOT full" << endl;
                break;
            case 5: 
                cout << "Count called - Number of items: " << q.count() << endl;
                break;
            case 6:
                cout << "Display called" << endl;
                q.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter proper option" << endl;
        } 
    }while(option != 0);
    
    // Test case:
    /*
        1. Enter size: 5
        2. Call display() --> Q => 0 0 0 0 0 
        4. Call isEmpty() => True
        5. Enqueue(1) 
        6. Enqueue(2) 
        7. Enqueue(3) 
        8. Enqueue(4) 
        9. Enqueue(5)
        10. Call display() --> Q => 1 2 3 4 5
        11. Call Count() --> 5
        12. Call isFull() => True
        13. Call Dequeue() --> Q => 0 2 3 4 5 
        14. Call Count() --> 4
        15. Call isFull() => True **Disadvantage of Queue

    */
    /*   
        Time Complexity:
        Enqueue() --> O(1)
        Dequeue() --> O(1)
        isEmpty() --> O(1)
        isFull() --> O(1)
        count() --> O(1)
        display() --> O(n)
    */

    return 0;
}
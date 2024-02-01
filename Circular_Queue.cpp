#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    CircularQueue()
    {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    // 1. isEmpty Function
    bool isEmpty()
    {
        if ((front == -1) && (rear == -1))
        {
            return true;
        }
        else
            return false;
    }

    // 2. isFull Function
    bool isFull()
    {
        if ((rear + 1) % 5 == front) // % 5 is modulo by size of array
        {
            return true;
        }
        else
            return false;
    }

    // 3. Enqueue Function
    void enQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }
        arr[rear] = value;
        cout << "Value Enqueued." << endl;
        itemCount++;
    }

    // 4.Dequeue Function
    int deQueue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else if (rear == front)
        {
            x = arr[front];
            rear = front = -1;
            // arr[front] = 0;
            // rear = front = 0;
            // front = 0;
            // rear--;
            itemCount--;
            return x;
        }

        else
        {
            cout << "front value : " << front << endl;
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % 5;
            // rear--;
            itemCount--;
            return x;
        }
    }

    // 5. count Function
    int count()
    {
        return itemCount;
    }

    // 6. Display Function
    void display()
    {
        cout << "All values inthe Queue are : " << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    CircularQueue cq1;
    int option, value;

    do
    {
        cout << "\nWhat Operation do you want to perform? Select Option Number.\nEnter 0 to exist." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            /* code */
            break;
        case 1:
            cout << "Enqueue Operation called. \nEnter an item in the Queue : " << endl;
            cin >> value;
            cq1.enQueue(value);
            break;
        case 2:
            cout << "Dequeue Operation Called. \nDequeued value : " << cq1.deQueue() << endl;
            break;
        case 3:
            if (cq1.isEmpty())
            {
                cout << "Queue is Empty." << endl;
            }
            else
            {
                cout << "Queue is not Empty." << endl;
            }
            break;
        case 4:
            if (cq1.isFull())
            {
                cout << "Queue is Full." << endl;
            }
            else
            {
                cout << "Queue is not Full. " << endl;
            }
            break;
        case 5:
            cout << "Count Operation called.\nTotal items in Queue are : " << cq1.count() << endl;
            break;
        case 6:
            cq1.display();
            break;
        default:
            cout << "Enter valid Option number." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
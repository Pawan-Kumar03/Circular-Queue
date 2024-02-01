#include <iostream>
using namespace std;

// node class
class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};
// Circular Linked List Class
class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = NULL;
    }

    // Check if Node Exist
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;

            } while (ptr != head);
            return temp;
        }
    }

    // Append a Node to the List
    void appendNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node already exists with key value : " << new_node->key << ". Append another node with different key value. " << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node Appended at first Head Position." << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;
                cout << "Node Appended." << endl;
            }
        }
    }

    // Prepend Node - Attach a Node at first Position
    void prependNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node already exists with key value : " << new_node->key << ". Append another node with different key value. " << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node preppended at first Head Position." << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;
                head = new_node;
                cout << "Node preppended." << endl;
            }
        }
    }

    // Insert a Node after a particular Node in the List
    void insertNodeAfter(int k, Node *new_node)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists wiht key value " << k << endl;
        }
        else
        {
            if (nodeExists(new_node->key) != NULL)
            {
                cout << "Node Already exist with Key value " << new_node->key << ". Insert another node with different value" << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    new_node->next = head;
                    ptr->next = new_node;
                    cout << "Node Inserted at the End." << endl;
                }
                else
                {
                    new_node->next = ptr->next;
                    ptr->next = new_node;
                    cout << "Node inserted in Between." << endl;
                }
            }
        }
    }

    // Delete Node by Unique Key
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exist with key : " << k << endl;
        }
        else
        {
            if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head == NULL;
                    cout << "Head Node Unlinked." << endl;
                }
                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "Node Unlinked with key value." << k << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                prevptr->next = temp->next;
                cout << "Node UnLinked with key value." << k << endl;
            }
        }
    }

    // Update Node
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated succesfully" << endl;
        }
        else
        {
            cout << "Node doesn't exists with key value " << k << endl;
        }
    }

    // Printing list
    void printList()
    {
        if (head == NULL)
        {
            cout << "No any Node in Circular Linked List." << endl;
        }
        else
        {
            cout << endl
                 << "Head Address : " << head << endl;
            cout << "Circular Linked list values are : " << endl;
            Node *temp = head;
            do
            {
                cout << "( " << temp->key << "," << temp->data <<" , "<< temp->next << " )-->";
                temp = temp->next;
            } while (temp != head);
        }
    }
};

int main()
{
    CircularLinkedList cl;
    int option;
    int key1, k1, data1;
    do
    {
        cout << endl<< "What Operation do you want to perform?\nSelect Option number.Enter 0 to exist" << endl;
        cout << "1. Append Node() ." << endl;
        cout << "2. PrePend Node() ." << endl;
        cout << "3. InsertNodeAfter() ." << endl;
        cout << "4. DeleteNodeBykey() ." << endl;
        cout << "5. UpdateNodeByKey() ." << endl;
        cout << "6. Print() ." << endl;
        // cout << "7. Clear Screen ." << endl;
        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            /* code */
            break;
        case 1:
            cout << "Append Node Operation \nEnter key value & Data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            cl.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the node to be Prepended." << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            cl.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node After Operation \nEnter key of existing node after which you want to insert this Node: " << endl;
            cin >> k1;
            cout << "Enter Key and Data of new Node that You are Inserting : " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            cl.insertNodeAfter(k1, n1);
            break;
        case 4:
            cout << "Delete Node Operation \nEnter key of node that you want to Delete: " << endl;
            cin >> k1;
            cl.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Update Node Operation \nEnter key and new Data to be updated:" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            cl.updateNodeByKey(key1, data1);
            break;
        case 6:
            cl.printList();
            break;
        //  case 7:
        //      system("cls");
        //      break;
        default:
            cout << "Enter proper Option Number." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}

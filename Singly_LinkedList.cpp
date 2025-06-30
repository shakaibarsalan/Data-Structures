#include <iostream>
#include <string>
#include <windows.h>
#include <stdexcept>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
};

int getSize(Node *&head)
{
    int size = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "Currently List is Empty." << endl
             << endl;
        return;
    }
    Node *temp = head;
    cout << "===================================\nList: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "===================================\n";
}

void insertAthead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        system("CLS");
        // print(head);
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    system("CLS");
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        system("CLS");
        // print(head);
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
    system("CLS");
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (head == NULL)
    {
        insertAthead(head, tail, data);
        return;
    }
    if (position == 1)
    {
        insertAthead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    system("CLS");
}

void deleteHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (head == tail)
    {
        cout << "There's only one node in the list." << endl;
        delete head;
        head = NULL;
        tail = NULL;
        cout << "Done deletion." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    cout << "Done deletion." << endl;
}

void deleteTail(Node *&head, Node *&tail)
{
    if (tail == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (head == tail)
    {
        cout << "There's only one node in the list." << endl;
        delete head;
        head = NULL;
        tail = NULL;
        cout << "Done deletion." << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
    // system("CLS");
    cout << "Done deletion." << endl;
}

void deleteFromPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        deleteHead(head, tail);
        return;
    }

    Node *current = head;
    Node *previous = NULL;

    int count = 1;
    while (count < position)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        deleteTail(head, tail);
        return;
    }

    previous->next = current->next;
    current->next = NULL;
    delete current;
    system("CLS");
}

int midElement(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    int length = getSize(head);
    int answer = (length / 2);
    Node *temp = head;
    int count = 0;
    while (count < answer)
    {
        temp = temp->next;
        count++;
    }
    return temp->data;
    system("CLS");
}

void deleteAllOccurrences(Node *&head, Node *&tail, int element)
{
    Node *temp = head;
    int found = 0;
    int position = 0;

    while (temp != NULL)
    {
        position++;
        if (temp->data == element)
        {
            deleteFromPosition(head, tail, position);
            temp = head;
            found++;
        }
        temp = temp->next;
    }

    if (found == 0)
    {
        system("CLS");
        cout << "Element Not Found." << endl
             << endl;
    }
}

Node *reverseList(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Their is no element in List." << endl;
        system("CLS");
        print(head);
        return head;
    }

    Node *previous = NULL;
    Node *current = head;
    Node *forward = NULL;

    while (current != NULL)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}

Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }
    return prev;
}

void searchElement(Node *&head, int search)
{
    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }
    int index = 0, cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == search)
        {
            cout << " -> Found at index " << index + 1 << endl
                 << endl;
            cnt++;
        }
        temp = temp->next;
        index++;
    }
    if (cnt == 0)
    {
        cout << " -> \"" << search << "\"Not Found." << endl
             << endl;
    }
}

void updateAllOccurrences(Node *&head, int then, int now)
{
    Node *temp = head;
    int fun = 0;
    while (temp != NULL)
    {
        if (temp->data == then)
        {
            temp->data = now;
            fun++;
        }
        temp = temp->next;
    }
    system("CLS");
    print(head);
    if (fun == 0)
    {
        cout << "  \"" << then << "\" not exist in list." << endl
             << endl;
    }
}

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    Node *ans = new Node(-1); // dummy node
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node *sortLinkedList(Node *head, Node *&tail)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = sortLinkedList(left, tail);
    right = sortLinkedList(right, tail);

    Node *result = merge(left, right);
    Node *temp = result;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
    return result;
}

int main()
{
    Node *node;
    Node *head = NULL;
    Node *tail = NULL;

    string input;
    int num, index, choice, run = 0;
    while (true)
    {
        cout << "  Choose an operation:" << endl
             << "    1. Add to the head" << endl
             << "    2. Add to the tail" << endl
             << "    3. Add at a specific location" << endl
             << "    4. Delete from head" << endl
             << "    5. Delete from tail" << endl
             << "    6. Deleting specific element" << endl
             << "    7. Delete from a specific location" << endl
             << "    8. Update Element in List" << endl
             << "    9. Sort the List" << endl
             << "    10. Reverse List" << endl
             << "    11. KReverse List" << endl
             << "    12. Find middle(R) element in List" << endl
             << "    13. Search in List" << endl
             << "    14. Check Current State of array" << endl
             << "    15. Quit" << endl;

        while (true)
        {
            cout << "Enter Choice: ";
            try
            {
                getline(cin, input);
                choice = stoi(input);
                if (choice < 1 || choice > 15)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid Choice Range." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    break;
                }
            }
            catch (const invalid_argument &e)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Invalid input. Please enter an integer." << endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
        cout << endl;

        switch (choice)
        {
        case 1:
            while (true)
            {
                cout << "Enter the number to add to head: ";
                try
                {
                    getline(cin, input);
                    num = stoi(input);
                    break;
                }
                catch (const invalid_argument &e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid input. Please enter an integer." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            insertAthead(head, tail, num);
            print(head);
            break;

        case 2:
            while (true)
            {
                cout << "Enter the number to add to the tail: ";
                try
                {
                    getline(cin, input);
                    num = stoi(input);
                    break;
                }
                catch (const invalid_argument &e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid input. Please enter an integer." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            insertAtTail(head, tail, num);
            print(head);
            break;

        case 3:
            while (true)
            {
                cout << "Enter the number to add: ";
                try
                {
                    getline(cin, input);
                    num = stoi(input);
                    break;
                }
                catch (const invalid_argument &e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid input. Please enter an integer." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            if (getSize(head) == 0)
            {
                index = 1;
                run++;
            }
            else
            {
                while (true)
                {

                    cout << "Enter the index from 1 to " << getSize(head) + 1 << ": ";
                    try
                    {
                        getline(cin, input);
                        index = stoi(input);
                        if (index < 1 || index > getSize(head) + 1)
                        {
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, 12);
                            cout << "Invalid Index Range." << endl;
                            SetConsoleTextAttribute(hConsole, 7);
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
            }
            insertAtPosition(head, tail, index, num);
            if (run == 1)
            {
                cout << "List is Empty. So value placed at 1st." << endl;
                run = 0;
            }
            print(head);
            break;

        case 4:
            system("CLS");
            deleteHead(head, tail);
            print(head);
            break;

        case 5:
            system("CLS");
            deleteTail(head, tail);
            print(head);
            break;

        case 6:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                while (true)
                {
                    cout << "Enter the number to Delete: ";
                    try
                    {
                        getline(cin, input);
                        num = stoi(input);
                        break;
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
                deleteAllOccurrences(head, tail, num);
            }
            print(head);
            break;

        case 7:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                while (true)
                {
                    cout << "Enter the index from 1 to " << getSize(head) << " to delete: ";
                    try
                    {
                        getline(cin, input);
                        index = stoi(input);
                        if (index < 1 || index > getSize(head))
                        {
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, 12);
                            cout << "Invalid Index Range." << endl;
                            SetConsoleTextAttribute(hConsole, 7);
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
                system("CLS");
                deleteFromPosition(head, tail, index);
            }
            print(head);
            break;

        case 8:
            if (getSize(head) == 0)
            {
                index = 1;
                run++;
                system("CLS");
                cout << "\tList is Empty.\n\n";
            }
            else
            {
                int then, now;
                while (true)
                {
                    cout << "Enter number to Replace: ";
                    try
                    {
                        getline(cin, input);
                        then = stoi(input);
                        break;
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
                while (true)
                {
                    cout << "Enter number to Replace with: ";
                    try
                    {
                        getline(cin, input);
                        now = stoi(input);
                        break;
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
                updateAllOccurrences(head, then, now);
            }
            break;

        case 9:
            // cout << "======" << head->data << "=======" << endl;
            // cout << "======" << tail->data << "=======" << endl;
            head = sortLinkedList(head, tail);
            // cout << "======" << head->data << "=======" << endl;
            // cout << "======" << tail->data << "=======" << endl;
            system("CLS");
            print(head);
            break;

        case 10:
            system("CLS");
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                cout << "List before Reverse:" << endl;
                print(head);
                cout << endl;
                head = reverseList(head);
                cout << "List after Reverse:" << endl;
            }
            print(head);
            cout << endl;
            break;

        case 11:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "List is Empty." << endl
                     << endl;
                break;
            }
            else
            {

                while (true)
                {
                    cout << "Enter number of nodes from 2 to " << getSize(head) << " you want to Reverse: ";
                    try
                    {
                        getline(cin, input);
                        num = stoi(input);
                        if (num < 2 || num > getSize(head))
                        {
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, 12);
                            cout << "Invalid Index Range." << endl;
                            SetConsoleTextAttribute(hConsole, 7);
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
                system("CLS");
                cout << "List before K Revers:" << endl;
                print(head);
                cout << endl;
                head = kReverse(head, num);
                cout << "List after K Revers:" << endl;
            }
            print(head);
            cout << endl;
            break;

        case 12:
            system("CLS");
            print(head);
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                cout << " -> Middle Element is " << midElement(head) << endl
                     << endl;
            }
            break;

        case 13:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "List is Empty." << endl
                     << endl;
                break;
            }
            else
            {

                while (true && getSize(head) != 0)
                {
                    cout << "Enter number to Search: ";
                    try
                    {
                        getline(cin, input);
                        num = stoi(input);
                        break;
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
                system("CLS");
                print(head);
                searchElement(head, num);
            }
            break;

        case 14:
            system("CLS");
            cout << "Number of elements in List: " << getSize(head) << endl;
            print(head);
            break;

        case 15:
            cout << "\n\t\tGood Bye :)\n\n";
            exit(0);

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
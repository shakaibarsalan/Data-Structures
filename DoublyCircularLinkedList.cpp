#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }

    ~Node() {}
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = temp;
        head->next = head;
        head->previous = head;
    }
    else
    {
        temp->next = head;
        temp->previous = head->previous;
        head->previous->next = temp;
        head->previous = temp;
        head = temp;
    }

    system("CLS");
}

void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        head->previous = head;
        return;
    }

    Node *tail = head->previous;

    tail->next = newNode;
    newNode->previous = tail;

    newNode->next = head;
    head->previous = newNode;

    system("CLS");
}

void insertAtPosition(Node *&head, int addAfter, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        return;
    }

    Node *current = head;
    while (current->data != addAfter)
    {
        current = current->next;

        if (current == head)
        {
            std::cout << "Node with value " << addAfter << " not found in the list." << std::endl;
            return;
        }
    }

    Node *newNode = new Node(data);
    newNode->next = current->next;
    newNode->previous = current;
    current->next->previous = newNode;
    current->next = newNode;

    system("CLS");
}

void deleteFromHead(Node *&head)
{
    if (head == nullptr)
    {
        std::cout << "The list is already empty." << std::endl;
        return;
    }

    Node *temp = head;

    if (head->next == head)
    {
        head = nullptr;
    }
    else
    {
        Node *previousNode = head->previous;
        Node *newHead = head->next;

        previousNode->next = newHead;
        newHead->previous = previousNode;
        head = newHead;
    }

    delete temp;
}

void deleteFromTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node *tail = head->previous;
        tail->previous->next = head;
        head->previous = tail->previous;
        delete tail;
    }
}

void deleteFromPosition(Node *&head, int data)
{
    if (head == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    if (head->data == data)
    {
        Node *temp = head;

        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *prev = head->previous;
            Node *nextNode = head->next;

            prev->next = nextNode;
            nextNode->previous = prev;

            head = nextNode;
        }

        delete temp;
        return;
    }

    Node *current = head->next;

    while (current != head)
    {
        if (current->data == data)
        {
            Node *prev = current->previous;
            Node *nextNode = current->next;

            prev->next = nextNode;
            nextNode->previous = prev;

            delete current;
            return;
        }

        current = current->next;
    }

    cout << "Node with data " << data << " not found in the list." << endl;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        std::cout << "\n\tCurrently List is Empty." << std::endl
                  << std::endl;
        return;
    }

    Node *temp = head;
    std::cout << "===================================\nList: ";

    do
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    std::cout << std::endl;
    std::cout << "===================================\n\n";
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

    do
    {
        if (temp->data == search)
        {
            cout << " -> Found at index " << index + 1 << endl
                 << endl;
            cnt++;
        }
        temp = temp->next;
        index++;
    } while (temp != head);

    if (cnt == 0)
    {
        cout << " -> \"" << search << "\" Not Found." << endl
             << endl;
    }
}

void searchAndUpdate(Node *&head, int search, int newData)
{
    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    int index = 0, cnt = 0;
    Node *temp = head;

    do
    {
        if (head->data == search)
        {
            head->data = newData;
            cout << " -> " << search << " Found at index " << index + 1 << ". \"" << search << "\" changed with \"" << newData << "\"" << endl
                 << endl;
            cnt++;
        }
        head = head->next;
        index++;
    } while (head != temp);

    if (cnt == 0)
    {
        cout << " -> \"" << search << "\" Not Found." << endl
             << endl;
    }
}

int getSize(Node *&head)
{
    int size = 0;
    Node *temp = head;

    if (temp != NULL)
    {
        do
        {
            temp = temp->next;
            size++;
        } while (temp != head);
    }

    return size;
}

void sort(Node *&head)
{
    if (head != NULL && head->next != head)
    {
        Node *current = head;
        Node *index = NULL;

        while (current->next != head)
        {
            index = current->next;

            while (index != head)
            {
                if (current->data > index->data)
                {
                    int temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }

                index = index->next;
            }

            current = current->next;
        }
    }
}

int main()
{
    Node *head = NULL;

    string input;
    int num, index, choice, run = 0;
    while (true)
    {
        cout << "  Choose an operation:" << endl
             << "    1. Add to the head" << endl
             << "    2. Add to the tail" << endl
             << "    3. Add after specific Node" << endl
             << "    4. Delete from head" << endl
             << "    5. Delete from tail" << endl
             << "    6. Delete specific Node" << endl
             << "    7. Display Circular Link list" << endl
             << "    8. Sort the Circular Link List" << endl
             << "    9. Search data from the Circular Link List" << endl
             << "    10. Search and Update the Circular Link List" << endl
             << "    11. Quit" << endl;

        while (true)
        {
            cout << "Enter Choice: ";
            try
            {
                getline(cin, input);
                choice = stoi(input);
                if (choice < 1 || choice > 11)
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
            insertAtHead(head, num);
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
            insertAtTail(head, num);
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
                    // cout << "Please enter the data of the node that will come BEFORE the new node you want to insert: ";
                    cout << "Enter Data After: ";
                    try
                    {
                        getline(cin, input);
                        index = stoi(input);
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

                insertAtPosition(head, index, num);
            }
            if (run == 1)
            {
                cout << "List is Empty. So value placed at 1st." << endl;
                run = 0;
                insertAtHead(head,num);
            }
            print(head);
            break;

        case 4:
            system("CLS");
            if (getSize(head) == 0)
            {
                cout << "\n\tCurrently List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                cout << "Before:" << endl;
                print(head);
                cout << endl;
                deleteFromHead(head);
                cout << "After:" << endl;
                print(head);
            }
            break;

        case 5:
            system("CLS");
            if (getSize(head) == 0)
            {
                cout << "\n\tCurrently List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                cout << "Before:" << endl;
                print(head);
                cout << endl;
                deleteFromTail(head);
                cout << "After:" << endl;
                print(head);
            }
            break;

        case 6:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "\n\tCurrently List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                while (true)
                {

                    cout << "Enter the data you want to delete from List: ";
                    try
                    {
                        getline(cin, input);
                        index = stoi(input);
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
                deleteFromPosition(head, index);
            }
            print(head);
            break;

        case 7:
            system("CLS");
            cout << "Number of elements in List: " << getSize(head) << endl;
            print(head);
            break;

        case 8:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "\n\tCurrently List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                sort(head);
                system("CLS");
                print(head);
                break;
            }

        case 9:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "\n\tCurrently List is Empty." << endl
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

        case 10:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "\n\tCurrently List is Empty." << endl
                     << endl;
                break;
            }
            else
            {
                int from, to;
                while (true && getSize(head) != 0)
                {
                    cout << "Enter number you want to update: ";
                    try
                    {
                        getline(cin, input);
                        from = stoi(input);
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
                while (true && getSize(head) != 0)
                {
                    cout << "Enter new data for node: ";
                    try
                    {
                        getline(cin, input);
                        to = stoi(input);
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
                searchAndUpdate(head, from, to);
                print(head);
            }
            break;

        case 11:
            cout << "\n\t\tGood Bye :)\n\n";
            exit(0);

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
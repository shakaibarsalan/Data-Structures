#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }

    ~Node() {}
};

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "\n\tCurrently List is Empty." << endl
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
    cout << "===================================\n\n";
}

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        system("CLS");
        return;
    }
    else
    {
        temp->next = head;
        head->previous = temp;
        head = temp;
        system("CLS");
    }
}

void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        cout << "The list is Empty." << endl;
        system("CLS");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *nodeToInsert = new Node(data);
    temp->next = nodeToInsert;
    nodeToInsert->previous = temp;
    system("CLS");
}

void insertAtPosition(Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
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
        insertAtTail(head, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->previous = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->previous = temp;
    system("CLS");
}

void deleteFromHead(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;

    if (head->next != NULL)
    {
        temp->next->previous = NULL;
        head = temp->next;
    }
    else
    {
        head = NULL;
    }

    temp->next = NULL;
    delete temp;
}

void deleteFromTail(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->previous != NULL)
    {
        temp->previous->next = NULL;
        delete temp;
    }
    else
    {
        delete head;
        head = NULL;
    }
}

void deleteFromPosition(Node *&head, int position)
{
    if (position == 1)
    {
        deleteFromHead(head);
        return;
    }
    else
    {
        Node *current = head;
        Node *previous = NULL;

        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }

        if (current->next == NULL)
        {
            deleteFromTail(head);
            return;
        }

        current->previous = NULL;
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
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
    while (head != NULL)
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
    }
    if (cnt == 0)
    {
        cout << " -> \"" << search << "\" Not Found." << endl
             << endl;
    }
    head = temp;
}

void swapNodes(Node *&head, int phala, int dusra)
{
    Node *phalaNode = head;
    Node *phalaPrevious = NULL;
    for (int i = 1; phalaNode != NULL && i < phala; ++i)
    {
        phalaPrevious = phalaNode;
        phalaNode = phalaNode->next;
    }

    Node *dusrayNode = head;
    Node *dusrayPrevious = NULL;
    for (int i = 1; dusrayNode != NULL && i < dusra; ++i)
    {
        dusrayPrevious = dusrayNode;
        dusrayNode = dusrayNode->next;
    }

    if (phalaPrevious != NULL)
        phalaPrevious->next = dusrayNode;
    else
        head = dusrayNode;

    if (dusrayPrevious != NULL)
        dusrayPrevious->next = phalaNode;
    else
        head = phalaNode;

    Node *tempNext = phalaNode->next;
    phalaNode->next = dusrayNode->next;
    dusrayNode->next = tempNext;

    Node *tempPrev = phalaNode->previous;
    phalaNode->previous = dusrayNode->previous;
    dusrayNode->previous = tempPrev;
}

int getDataFromIndex(Node *&head, int index)
{
    if (index == 1)
    {
        return head->data;
    }

    Node *temp = head;

    int count = 1;
    while (count < index)
    {
        temp = temp->next;
        count++;
    }

    return temp->data;
}

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

void sort(Node *&head)
{
    for (int i = 0; i < getSize(head); ++i)
    {
        for (int j = 0; j < getSize(head); ++j)
        {
            if (getDataFromIndex(head, j) > getDataFromIndex(head, j + 1))
            {
                swapNodes(head, j, j + 1);
            }
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
             << "1. Add to the head" << endl
             << "2. Add to the tail" << endl
             << "3. Add at specific location" << endl
             << "4. Delete from head" << endl
             << "5. Delete from tail" << endl
             << "6. Deletion from specific Position" << endl
             << "7. Display Doubly Link list" << endl
             << "8. Sort the Doubly Link List" << endl
             << "9. Search data from the Doubly Link List" << endl
             << "10. Search and Update the Doubly Link List" << endl
             << "11. Quit" << endl;

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
            insertAtPosition(head, index, num);
            if (run == 1)
            {
                cout << "List is Empty. So value placed at 1st." << endl;
                run = 0;
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

                    cout << "Enter the index from 1 to " << getSize(head) << ": ";
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
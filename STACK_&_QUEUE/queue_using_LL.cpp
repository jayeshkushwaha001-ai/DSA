struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};
class LinkedListQueue
{
private:
    Node *head;
    Node *end;

public:
    LinkedListQueue()
    {
        head = nullptr;
        end = nullptr;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr)
        {
            head = end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        Node *temp = head;
        head = head->next;
        int val = temp->val;
        delete temp;
        if (head == nullptr)
        {
            end = nullptr;
        }
        return val;
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        int temp = head->val;
        return temp;
    }

    bool isEmpty() { return head == nullptr; }

    ~LinkedListQueue()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};
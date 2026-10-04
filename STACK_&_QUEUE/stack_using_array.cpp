class ArrayStack
{
private:
    int arr[1000];
    int topp;

public:
    ArrayStack()
    {
        topp = -1;
    }

    void push(int x)
    {
        if (topp >= 999)
            return;
        topp += 1;
        arr[topp] = x;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int temp = arr[topp];
        topp = topp - 1;
        return temp;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        return arr[topp];
    }

    bool isEmpty()
    {
        if (topp == -1)
            return true;
        return false;
    }
};
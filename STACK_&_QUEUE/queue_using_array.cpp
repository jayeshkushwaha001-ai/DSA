class ArrayQueue
{
private:
    int arr[1000];
    int start;
    int end;
    int currSize;

public:
    ArrayQueue()
    {
        start = end = -1;
        currSize = 0;
    }

    void push(int x)
    {
        if (currSize == 0)
        {
            start = end = 0;
        }
        else
        {
            end = (end + 1) % 1000;
        }
        arr[end] = x;
        currSize++;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int temp = arr[start];
        if (currSize == 1)
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1) % 1000;
        }
        currSize--;
        return temp;
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[start];
    }

    bool isEmpty()
    {
        return currSize == 0;
    }
};
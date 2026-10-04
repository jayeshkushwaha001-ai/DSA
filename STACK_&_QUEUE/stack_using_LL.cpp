struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class LinkedListStack {
   private:
    Node* topp;

   public:
    LinkedListStack() { topp = nullptr; }

    void push(int x) {
        Node* value = new Node(x);
        value->next = topp;
        topp = value;
    }

    int pop() {
        if(isEmpty()){return -1;}
        Node* temp = topp;
        int tempVal = temp->val;
        topp = topp->next;
        delete temp;
        return tempVal;
    }

    int top() {
        if(isEmpty()) return -1;
        int temp = topp->val;
        return temp;
    }

    bool isEmpty() {
        if(topp == nullptr) return true;
        return false;
    }
};
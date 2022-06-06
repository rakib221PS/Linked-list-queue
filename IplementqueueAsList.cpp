
#include <iostream>
#include <stdexcept>

class Node
{
public:
    int value;
    Node *next;

    Node(int _value, Node *_next = nullptr) : value(_value), next(_next)
    {
    }
};

class Queue
{
    Node *head;
    Node *tail;
    Node *copy = nullptr;

public:
    Queue() : head(nullptr), tail(nullptr)
    {
    }
    bool isEmpty() const
    {
        return head == nullptr;
    }

    void push(int x)
    {
        if (isEmpty())
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            tail->next = new Node(x);
            tail = tail->next;
        }
    }

    int front()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Under flow");
        }
        return head->value;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Under flow");
        }
        if (head->next == nullptr)
        {
            Node *tmp = head;
            int topValue = head->value;
            head = nullptr;
            tail = nullptr;
            delete tmp;
            return topValue;
        }
        Node *tmp = head;
        int topValue = head->value;
        head = head->next;
        delete tmp;
        return topValue;
    }

    void printList()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Empty Queue");
        }
        copy = head;

        while (copy != nullptr)
        {
            std::cout << copy->value << " ";
            copy = copy->next;
        }
        std::cout<<std::endl;
    }

    void clear()
    {
        while (!isEmpty())
        {
            deleteHead();
        }
    }
    ~Queue()
    {
        clear();
    }

    Queue(const Queue &original) : head(nullptr)
    {
        // if (!original.isEmpty())
        // {
        //     head = new Node(original.head->value);
        //     Node *src = original.head->next;
        //     Node *dsc = head;
        //     while (src != nullptr)
        //     {
        //         dsc->next = new Node(src->value);
        //         dsc = dsc->next;
        //         src = src->next;
        //     }
        //     delete src;
        //     // delete dsc;
        // }
        // if (!original.isEmpty())
        // {
        Node *dsc = original.head;
        while (dsc != nullptr)
        {
            push(dsc->value);
            dsc = dsc->next;
        }
        // }
    }

    Queue &operator=(const Queue &main)
    {
        if (main.head != head)
        {
            // if (!isEmpty())
            // {
            // while (head != nullptr)
            // {
            //     Node *tmp = head;
            //     head = head->next;
            //     delete tmp;
            // }
            // }
            clear();
            Node *copyValue = main.head;
            while (copyValue != nullptr)
            {
                push(copyValue->value);
                copyValue = copyValue->next;
            }
            return *this;
        }
        throw std::runtime_error("Trying self assignment");
    }

    // void extend(const Queue &qu)
    // {
    //     if (!isEmpty())
    //     {
    //         clear();
    //     }
    //     else
    //     {
    //         head = nullptr;
    //     }
    //     if (!qu.isEmpty())
    //     {
    //         head = new Node(qu.head->value);
    //         Node *src = qu.head->next;
    //         Node *dsc = head;
    //         while (src != nullptr)
    //         {
    //             dsc->next = new Node(src->value);
    //             dsc = dsc->next;
    //             src = src->next;
    //         }
    //         delete src;
    //         // delete dsc;
    //     }
    // }

    void extend(const Queue &qu)
    {
        Node *tmp = qu.head;

        while (tmp != nullptr)
        {
            push(tmp->value);
            tmp = tmp->next;
        }
    }

    // Queue merge(const Queue &m, const Queue &n)
    // {
    //     head = nullptr;
    //     Node *d;
    //     Node *s;
    //     Node *si;
    //     while (1)
    //     {
    //         if (m.isEmpty())
    //         {
    //             if (isEmpty())
    //             {
    //                 head = new Node(n.head->value);
    //                 si = n.head->next;
    //                 d = head;
    //                 while (si != nullptr)
    //                 {
    //                     d->next = new Node(si->value);
    //                     d = d->next;
    //                     si = si->next;
    //                 }
    //             }
    //             else
    //             {
    //                 while (si != nullptr)
    //                 {
    //                     d->next = new Node(si->value);
    //                     d = d->next;
    //                     si = si->next;
    //                 }
    //             }
    //         }
    //         else if (n.isEmpty())
    //         {
    //             if (isEmpty())
    //             {
    //                 head = new Node(m.head->value);
    //                 s = m.head->next;
    //                 d = head;
    //                 while (s != nullptr)
    //                 {
    //                     d->next = new Node(s->value);
    //                     d = d->next;
    //                     s = s->next;
    //                 }
    //             }
    //             else
    //             {
    //                 while (s != nullptr)
    //                 {
    //                     d->next = new Node(s->value);
    //                     d = d->next;
    //                     s = s->next;
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             if (isEmpty())
    //             {
    //                 if (m.head->value > n.head->value)
    //                 {
    //                     head = new Node(m.head->value);
    //                     s = m.head->next;
    //                     d = head;
    //                     si = n.head->next;
    //                 }
    //                 else
    //                 {
    //                     head = new Node(n.head->value);
    //                     s = m.head->next;
    //                     d = head;
    //                     si = n.head->next;
    //                 }
    //             }
    //             else
    //             {
    //                 if (s->value > si->value)
    //                 {
    //                     d->next = new Node(s->value);
    //                     d = d->next;
    //                     s = s->next;
    //                     si = si->next;
    //                 }
    //                 else
    //                 {
    //                     d->next = new Node(si->value);
    //                     d = d->next;
    //                     s = s->next;
    //                     si = si->next;
    //                 }
    //             }
    //         }
    //         if (s == nullptr && si == nullptr)
    //         {
    //             break;
    //         }
    //     }
    //     return *this;
    // }

    // void inserted_sorted(const Queue &ins)
    // {
    //     if (ins.isEmpty())
    //     {
    //         throw std::runtime_error("Trying to read from an empty queue");
    //     }
    //     if (!isEmpty())
    //     {
    //         clear();
    //     }
    //     head = new Node(ins.head->value);
    //     Node *sor = ins.head->next;
    //     Node *inserted = head;
    //     int n = 1;
    //     while (sor != nullptr)
    //     {
    //         if (inserted->value < sor->value)
    //         {
    //             int val = inserted->value;
    //             inserted->value = sor->value;
    //             sor->value = val;
    //             inserted->next = new Node(sor->value);
    //             inserted = inserted->next;
    //             sor = sor->next;
    //             n++;
    //         }
    //         else
    //         {
    //             inserted->next = new Node(sor->value);
    //             inserted = inserted->next;
    //             sor = sor->next;
    //             n++;
    //         }
    //         if (head->value > n)
    //         {
    //             break;
    //         }
    //     }
    // }
    // void inserted_sorted(const int x)
    // {
    //     if (!isEmpty())
    //     {
    //         Node *pushFront = new Node(x);
    //         Node *addOther = pushFront;
    //         Node *reArrange = head;
    //         // is it good enough?
    //         while (reArrange != nullptr)
    //         {
    //             addOther->next = new Node(reArrange->value);
    //             reArrange = reArrange->next;
    //             addOther = addOther->next;
    //         }
    //         Node *reReArrange = pushFront;
    //         int val;
    //         while (reReArrange != nullptr && reReArrange->next != nullptr && (reReArrange->value > reReArrange->next->value))
    //         {
    //             val = reReArrange->value;
    //             reReArrange->value = reReArrange->next->value;
    //             reReArrange->next->value = val;
    //             reReArrange = reReArrange->next;
    //         }
    //         // is it good?
    //         // clear();
    //         head = pushFront;
    //         while (pushFront != nullptr)
    //         {
    //             tail = pushFront;
    //             pushFront = pushFront->next;
    //         }
    //     }
    //     else
    //     {
    //         push(x);
    //     }
    // }
    Queue merge(Queue &a, Queue &b)
    {
        Queue c;

        while (!a.isEmpty() && !b.isEmpty())
        {
            if (a.front() <= b.front())
            {
                c.push(a.pop());
            }
            else
            {
                c.push(b.pop());
            }
            
        }

        while (!a.isEmpty())
        {
            c.push(a.pop());
        }
        while (!b.isEmpty())
        {
            c.push(b.pop());
        }
        return c;
    }

    void inserted_sorted(const int x){
        head = new Node(x,head);
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            if (tmp->value > tmp->next->value)
            {
                int val = tmp->value;
                tmp->value = tmp->next->value;
                tmp->next->value = val;
                tmp = tmp->next;
            }
            else
            {
                break;
            }
        }
        
    };

private:
    void deleteHead()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
};

int main()
{
    Queue queue, anotherQueue, newQueue, result, insertedQueue;
    for (int i = 0; i < 5; i++)
    {
        // std::cin>>n;
        queue.push(i);
    }
    std::cout << queue.front() << std::endl;
    // Queue copyQueue(queue);
    anotherQueue.extend(queue);
    std::cout << "copy " << anotherQueue.front() << std::endl;
    queue.pop();
    anotherQueue.printList();
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
    {
        newQueue.push(-(i + 1));
    }
    queue = newQueue;
    result.merge(queue, newQueue);
    // result.printList();
    std::cout << std::endl;
    for (int i = 0; i < 7; i++)
    {
        insertedQueue.push(i*2);
    }
    insertedQueue.printList();
    
    insertedQueue.inserted_sorted(99);
    // insertedQueue.inserted_sorted(5);
    // insertedQueue.printList();
    // std::cout << std::endl;
    // insertedQueue.push(9);
    // insertedQueue.inserted_sorted(3);
    std::cout<<"inserted queue: ";
    insertedQueue.printList();
    
    return 0;
}
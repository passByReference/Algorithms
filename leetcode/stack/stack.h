#ifndef STACK_H
#define STACK_H
class stack()
{
    public:
        stack(int iMaxSize);
        stack(const stack &source);
        stack& operator= (const stack &source);
        ~stack();
        void push(int v);
        int pop();
        bool empty();
        int get_size();
    private:
        int _maxSize;
        int _top;
        int* _items[];

};

#endif

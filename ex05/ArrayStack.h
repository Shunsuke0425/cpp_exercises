// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
    private:
    int _num_items; // number of items in the stack
    double* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;
        
        // Move stack to a new array of size max
        _allocated_size = max_size;
        double* temp = new double[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    ArrayStack():
    /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to the null pointer, 
     */
        _num_items(0),
        _items(nullptr),
        _allocated_size(0)
    {}


    explicit ArrayStack(int allocated_size):
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */
    _num_items(0),
    _items(new double[allocated_size]),
    _allocated_size(allocated_size){}
    
    // Destructor:
    ~ArrayStack() {
        // COMPLETE
        delete[] _items;
    }
    //Copy Constructor:
    ArrayStack(const ArrayStack& another_arraystack){
        std::cout << "Copy Constructor" <<  std::endl;
        _num_items = another_arraystack._num_items;
        _items = new double[another_arraystack._allocated_size];
        for(int i = 0; i < another_arraystack._num_items; i++){
            _items[i] = another_arraystack._items[i];
        }
        _allocated_size = another_arraystack._allocated_size;
    }
    // Assignment:
    ArrayStack& operator = (const ArrayStack& another_arraystack2){
        if(this == &another_arraystack2)return *this;
        std::cout << "Assignment Operator" <<  std::endl;
        _num_items = another_arraystack2._num_items;
        delete[] _items;
        _items = new double[another_arraystack2._allocated_size];
        for(int i = 0; i < another_arraystack2._num_items; i++){
            _items[i] = another_arraystack2._items[i];
        }
        _allocated_size = another_arraystack2._allocated_size;
        return *this;
    }

    //Move:
    ArrayStack& operator = (ArrayStack&& another_arraystack3){
        if(this == &another_arraystack3)return *this;
        std::cout << "Move Constructor" << std::endl;
        _num_items = another_arraystack3._num_items;
        _items = another_arraystack3._items;
        _allocated_size = another_arraystack3._allocated_size;
        another_arraystack3._num_items = 0;
        another_arraystack3._items = nullptr;
        another_arraystack3._allocated_size = 0;
        return *this;
    }
    //another Move assignment:
    ArrayStack(ArrayStack&& another):
        _num_items(another._num_items),
        _items(another._items),
        _allocated_size(another._allocated_size)
    {
        another._num_items = 0;
        another._items = nullptr;
        another._allocated_size = 0;
    }
    void push(double item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    void pop() {
        _num_items--;
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    }

    double top() {
        return _items[_num_items-1];
    }

    bool empty() const { return _num_items == 0; }

    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H
#include "stack.h"

stack::stack(int iMaxSize): _maxSize(iMaxSize), _top(-1), _items(new int[_maxSize])
{}
/*
stack::stack(const stack &source) {
    if (source.empty()) return;
    _maxSize = std::move(source.get_size());
    _items = new int[_maxSize];
    for (int i = 0; i < _maxSize; ++i) {
        _items[i] = 
    }

}
*/

stack::~stack() {
    if (_items) {
        delete[] _items;
    }
}
void stack::push(int v) {
    if (_top < _maxSize) {
        _items[++_top] = v;
    } else {
        std::cout << "max size exceeded!" << std::endl;
    }
}

void stack::pop() {
    if (!this.empty()) {
        return _items[_top--];
    } else {
        std::cout << "stack is empty" << std::endl;
    }
}

void stack::empty() {
    return _items == nullptr;
}

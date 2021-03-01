#ifndef STACK_H
#define STACK_H

#include<cstdint>
namespace algo {
    const uint32_t defaultCapacity = 50;
    
    template <typename T = uintptr_t>
    class Stack {
        public:
            Stack(uint32_t capacity = defaultCapacity) 
                :_size(0), _capacity(capacity), _elements(new T[_capacity]){};
            ~Stack()
            {
                delete []_elements;    
            }
            void Push(T const &item){
                if (_size == _capacity){
                    resize(2 * _capacity);
                }
                _elements[_size] = item;
                _size++;
            }

            T const &Peek(){
                return _elements[_size-1];
            }

            void Pop(){
                if (isEmpty()){
                    return;
                }
                _size--;
                if (_size < _capacity/4) {
                    resize(_capacity/2);
                }
            }
            uint32_t Size(){
                return _size;
            }

            bool isEmpty() {
                if (_size == 0){
                    return true;
                }
                return false;
            }

            void Show() {
                std::cout << "size:" << _size <<std::endl;
                std::cout << "capacity:" << _capacity << std::endl;
                for(int i = 0; i < _size; i++){
                    std::cout << "item:" << _elements[i] << std::endl;
                }
            }
        private:
            uint32_t _size;
            uint32_t _capacity;
            T * _elements;

            void resize(uint32_t capacity){
                T * temp = new T[capacity];
                for(int i =0;i < _size; i++)
                {
                    temp[i] = _elements[i];
                }
                delete []_elements;
                _capacity = capacity;
                _elements = temp;
            }
    };

    template<typename T = uintptr_t>
    class StackList {
        public:
            StackList(): _head(nullptr), _size(0){};
            ~StackList(){
                while(_head){
                    Node* toDeleteNode = _head;
                    _head = _head->next;
                    std::cout << "delete node addr:" << toDeleteNode << std::endl;
                    std::cout << " item:" << toDeleteNode->item << std::endl;
                    delete toDeleteNode;
                }
            }
            void Push(T const &item){
                Node *oldhead = _head;
                _head = new Node();
                _head->item = item;
                _head->next = oldhead;
                _size++;
            }

            T Pop(){
                if (_head == nullptr)
                {
                    throw "Stack is empty.";
                }
                T item = _head->item;
                Node *toDeleteNode = _head;
                _head = _head->next;
                _size--;
                delete toDeleteNode;
                return item;
            }

            T const & Peek(){
                if (_head == nullptr)
                {
                    throw "Stack is empty.";
                }
                return _head->item;
            }

            uint32_t Size(){
                return _size;
            }
            bool IsEmpty(){
                if (Size() == 0){
                    return true;
                }
                return false;
            }

            void Show(){
                Node *cur = _head;
                while(cur) {
                    std::cout << "item:" << cur->item << std::endl;
                    cur = cur->next;
                }
                std::cout << "size:" << _size << std::endl;
            }
        private:
            struct Node {
                T item;
                Node *next;
                };
            Node *_head;
            Node *_tail;
            uint32_t _size;
    };


}
#endif
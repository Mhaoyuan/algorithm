#ifndef QUEUE_H
#define QUEUE_H
#include<cstdint>

namespace algo {
    template<typename T>
    class Queue {
        public:
            Queue(uint32_t capacity = _defaultCapacity): _size(0),_head(0), _tail(0), _capacity(capacity), _elements(new T[_capacity]){};
            ~Queue(){
                delete [] _elements;
            }

            void Enqueue(T const &item){
                if (_size == _capacity){
                    resize(_capacity * 2);
                }
                _elements[_tail++] = item;
                _size++;
                if (_tail == _capacity){
                    _tail = 0;
                }
            }
            T Dequeue(){
                if (_size < _capacity/4){
                    resize(_capacity/2);
                }
                T item = _elements[_head++];
                if (_head == _capacity){
                    _head = 0;
                }
                _size--;
                return item;
            }
            uint32_t Size(){return _size;};
            bool IsEmpty(){return _size == 0;};
            T Peek(){return _elements[_head];}
            void Show(){
                std::cout << "_size:" << _size << std::endl;
                std::cout << "_capacity:" << _capacity << std::endl;
                for(int i = 0; i < _size; i++){
                    std::cout << "item:" <<_elements[(_head + i)%_capacity] << std::endl;
                }
            }
        private:
            uint32_t _size;
            uint32_t _head;
            uint32_t _tail;
            uint32_t _capacity;
            T * _elements;
            static const int _defaultCapacity = 50;

            void resize(uint32_t capacity){
                if (capacity <= _size){
                    return;
                } 
                T* temp = new T[capacity]; 
                for (int i = 0; i < _size; i++){
                    temp[i] = _elements[(_head + i)%_capacity];
                }
                delete []_elements;
                _head = 0;
                _tail = _size;
                _capacity = capacity;
                _elements = temp;
            }
    };
    template<typename T>
    class QueueList {
        public:
            QueueList():_size(0), _head(nullptr), _tail(nullptr){};
            ~QueueList(){
                while(_head){
                    Node* toDeleteNode = _head;
                    _head = _head->next;
                    std::cout << "to delete item" << toDeleteNode->item << std::endl;
                    delete toDeleteNode;
                }
            }
            void Enqueue(T const& item){
                Node* newNode = new Node();
                newNode->item = item;
                newNode->next = nullptr;
                if (IsEmpty()) {
                    _tail = newNode;
                    _head = _tail;
                }else{
                    _tail->next = newNode;
                    _tail = newNode;
                }
                _size++;
            }
            T Dequeue(){
                if (IsEmpty()){
                    throw "Queue is empty.";
                }
                Node* temp = _head;
                T item = _head->item;
                _head = _head->next;
                _size--;
                if (_head == nullptr){
                    _tail = nullptr;
                }
                delete temp;
                return item;
            }
            bool IsEmpty(){
                return _size == 0;
            }
            uint32_t Size(){
                return _size;
            }
            void Show(){
                std::cout << "size:" << Size()<< std::endl;
                Node *cur = _head; 
                while(cur)
                {
                    std::cout<< "item:" << cur->item << std::endl;
                    cur = cur->next;

                }
            }
        private:
            struct Node {
                T    item;
                Node *next;
            };
            uint32_t  _size;
            Node*     _head;
            Node*     _tail;
        };
}
#endif
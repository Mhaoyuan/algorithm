//#ifndef MYLIST_H
//#define MYLIST_H
#include<iostream>
#include<cstdint>
//https://stackoverflow.com/questions/5136433/c-list-implementation
namespace algo{
template<typename T>
class MyList{
    public:
        MyList():_head(nullptr), _tail(nullptr),_size(0){};
        MyList(const MyList&);
        MyList(MyList &&);
        MyList& operator=(const MyList&);
        MyList& operator=(MyList&&);
        ~MyList();

        void add_tail(const T&);
        void add_front(const T&);
        uint32_t Size(){return _size;}
        bool IsEmpty(){return Size()==0;}
        void Display(){
            auto temp = _head;
            while(temp){
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    private:
        void copy(const MyList&);
        void move(MyList &&);
        void free();
        struct Node{
            Node *next;
            T    value;    
            };
        Node* _head;
        Node* _tail;
        uint32_t _size;
};


template<typename T>
MyList<T>::MyList(const MyList& rhs){
    copy(rhs);
}
template<typename T>
MyList<T>& MyList<T>::operator=(const MyList& rhs){
    if(this != &rhs)
    {
        free();
        copy(rhs);
        
    }
    return *this;
}

template<typename T>
MyList<T>::MyList(MyList && rhs){
    move(std::move(rhs));
    rhs._head =  rhs._tail = nullptr;
    _size = 0;

}

template<typename T>
MyList<T>& MyList<T>::operator=(MyList && rhs){
    if(this != &rhs){
        free();
        move(std::move(rhs));
        rhs._head =  rhs._tail = nullptr;
        _size = 0;
    }
    return *this;
}

template<typename T>
MyList<T>::~MyList(){
    free();
}

template<typename T>
void MyList<T>::add_tail(const T& item){
    Node* newNode = new Node();
    newNode->value = item;
    newNode->next = nullptr;
    if (IsEmpty()){
        _head = _tail = newNode;
    }else{
        _tail->next = newNode;
        _tail = newNode;
    }
    _size++;
}

template<typename T>
void MyList<T>::add_front(const T& item){
    Node* newNode = new Node();
    newNode->value = item;
    newNode->next = nullptr;
    if(IsEmpty()){
        _head = _tail = newNode;
    }else{
        newNode->next = _head->next;
        _head = newNode;
    }
    _size++;
}


template<typename T>
void MyList<T>::free(){
    while(_head){
        auto temp = _head;
        delete temp;
        _head = _head->next;
        _size--;
    }
}

template<typename T>
void MyList<T>::copy(const MyList& rhs){
    auto cur = rhs._head;
    while(cur){
        add_tail(cur->value);
        cur = cur->next;
        _size++;
    }
}

template<typename T>
void MyList<T>::move(MyList &&rhs){
    _head = rhs._head;
    _tail = rhs._tail;
    _size = rhs._size;
}

}
//#endif
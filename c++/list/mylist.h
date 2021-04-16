#ifndef MYLIST_H
#define MYLIST_H
#include<iostream>
#include<cstdint>
//https://stackoverflow.com/questions/5136433/c-list-implementation
namespace algo{

template<typename T>
struct Node{
    Node *next;
    T    value;
    public:
        void Set(const T& item){value = item;}    
};


template<typename T>
class MyList{
    public:
        MyList():_head(nullptr), _tail(nullptr),_size(0){};
        MyList(const MyList&);
        MyList(MyList &&);
        MyList& operator=(const MyList&);
        MyList& operator=(MyList&&);
        ~MyList();

        T delete_tail();
        T delete_front();
        T delete_k(uint32_t k);
        T max();
        T recursion_max();
        void insertAfter(const Node<T>& first, const Node<T>& second);
        void removeAfter(const Node<T>&);
        void remove(const T&);
        bool find(const T&);
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
        T getmax(const Node<T>* node, T& max_value);

        Node<T>* _head;
        Node<T>* _tail;
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
    rhs._size = 0;

}

template<typename T>
MyList<T>& MyList<T>::operator=(MyList && rhs){
    if(this != &rhs){
        free();
        move(std::move(rhs));
        rhs._head =  rhs._tail = nullptr;
        rhs._size = 0;
    }
    return *this;
}

template<typename T>
MyList<T>::~MyList(){
    free();
}

template<typename T>
void MyList<T>::add_tail(const T& item){
    Node<T>* newNode = new Node<T>();
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
    Node<T>* newNode = new Node<T>();
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
T MyList<T>::delete_tail(){
    assert(!IsEmpty());
    T deleteItem;
    Node<T>* toDeleteNode = _head;
    if(toDeleteNode == _tail){
        deleteItem = _tail->value;
        delete _tail;
        _head = _tail = nullptr; 
       
    }
    else{
        while(toDeleteNode->next != _tail){
            toDeleteNode = toDeleteNode->next;
        }
        deleteItem = _tail->value;
        delete _tail;
        toDeleteNode->next = nullptr;
        _tail = toDeleteNode;
        
    }
    _size--;
    return deleteItem;
}
template<typename T>
T MyList<T>::delete_front(){
    assert(!IsEmpty());
    T delValue;
    auto toDeleteNode = _head;
    _head = _head->next;
    delValue = toDeleteNode->value;
    delete toDeleteNode;
    _size--;
    return delValue;
}


template<typename T>
T MyList<T>::delete_k(uint32_t k){
    assert(!IsEmpty());
    assert(k <= Size());
    assert(k >= 0);
    T delValue;
    
    if( k == 1){
        delValue = delete_front();
    }
    else if (k == Size()){
        delValue = delete_tail();
    }
    else{
        auto preDeleteNode = _head;
        k = k - 1;
        while(--k)
        {
            preDeleteNode = preDeleteNode->next;
        }

        auto toDeleteNode = preDeleteNode->next;
        delValue = toDeleteNode->value;
        preDeleteNode->next = toDeleteNode->next;
        
        delete toDeleteNode;
        _size--;
    }
    return delValue;
}

template<typename T>
bool MyList<T>::find(const T& item){
    assert(!IsEmpty());
    auto current = _head;
    while(current){
        if(current->value == item){
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
void MyList<T>::removeAfter(const Node<T>& node){
    assert(!IsEmpty());
    auto current = _head;
    while(current){
        if (current->value == node.value){
            auto toDeleteNode = current->next;
            if(toDeleteNode){
                current->next = toDeleteNode->next;
                delete toDeleteNode;
            }
        }
        current = current->next;
    }  
}

template<typename T>
void MyList<T>::remove(const T& key){
    assert(!IsEmpty());
    auto sentinel = new Node<T>();
    sentinel->next = _head;
    Node<T>* current = _head, *prev = sentinel, *toDelete = nullptr;
    while(current){
        if (current->value == key){
            toDelete = current;
            // current = current->next;
            prev->next = current->next;
            if(current == _tail){
                _tail = prev;
            }

        }else{
            prev = current;
            // current = current->next;
        }
        current = current->next;
        if(toDelete){
            delete toDelete;
            toDelete =nullptr;
        }
    }
    _head = sentinel->next;
    delete sentinel;
}

template<typename T>
T MyList<T>::max(){
    assert(!IsEmpty());
    T max = _head->value;
    auto curr = _head;
    while(curr){
        if (max < curr->value){
            max = curr->value;
        }
        curr = curr->next;
    }
    return max;
}

template<typename T>
T MyList<T>::recursion_max(){
    assert(!IsEmpty());
    T max_value = _head->value;
    return getmax(_head->next, max_value);
}
template<typename T>
T MyList<T>::getmax(const Node<T>* node, T& max_value){
    if(node == nullptr){
        return max_value;
    }
    if(max_value < node->value){
        max_value = node->value;
    }
    return getmax(node->next, max_value);
}

template<typename T>
void MyList<T>::insertAfter(const Node<T>& first, const Node<T>& second){
    assert(!IsEmpty());
    add_tail(first.value);
    add_tail(second.value);
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
#endif
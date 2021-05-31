#include<cstdint>
#include<iostream>
template<class T>
struct Node{
    T item;
    Node* next;
};

template<class T>
class StackList;

template<class U>
std::ostream& operator<<(std::ostream&, const StackList<U>&);

template<class T>
class StackList{
public:
    typedef  T           value_type;
    typedef  u_int32_t   size_type;

    StackList():_head(nullptr), _size(0){}
    StackList(const StackList&);
    StackList(StackList&&);
    StackList& operator=(const StackList&);
    StackList& operator=(StackList&&);
    friend std::ostream& operator<< <T>(std::ostream&, const StackList<T>&);
    ~StackList();

    size_type size() const {return _size;};
    bool is_empty() const {return size() == 0;};


    void push(value_type item);
    void pop();
    value_type peek();
    
private:
    void free();
    void copy(const StackList& rhs);
    Node<T> *_head;
    size_type _size;
};


template<class T>
void StackList<T>::copy(const StackList& rhs){
    auto current = rhs._head;
    _head = nullptr;
    while(current){
        Node<T> *oldhead = _head;
        _head = new Node<T>();
        _head->item = current->item;
        _head->next = oldhead;
        current = current->next;
    }
    _size = rhs._size;
}

template<class T>
void StackList<T>::free(){
    Node<T> *toDeleteNode;
    while(_head){
        toDeleteNode = _head;
        _head = _head->next;
        delete toDeleteNode;
        --_size;
    }
}

template<class T>
StackList<T>::StackList(const StackList& rhs){
    copy(rhs);
}

template<class T>
StackList<T>::StackList(StackList&& rhs){
    _head = rhs._head;
    _size = rhs._size;
    rhs._head = nullptr;
    rhs._size = 0;
}

template<class T>
StackList<T>& StackList<T>::operator=(StackList&& rhs){
    if(&rhs == this){
        return *this;
    }
    free();
    _head = rhs._head;
    _size = rhs._size;
    rhs._head = nullptr;
    rhs._size = 0;
    return *this;
}

template<class T>
void StackList<T>::push(T item){
    auto oldhead = _head;
    _head = new Node<T>();
    _head->item = item;
    _head->next = oldhead;
    ++_size;
}

template<class T>
void StackList<T>::pop(){
    assert(!is_empty());
    auto toDeleteNode = _head;
    _head = _head->next;
    delete toDeleteNode;
    --_size;
}
template<class T>
T StackList<T>::peek(){
    assert(!is_empty());
    return _head->item;
}


template<class T>
StackList<T>::~StackList(){
    free();
}


template<class T>
StackList<T>& StackList<T>::operator=(const StackList& rhs){
    if(&rhs == this){
        return *this;
    }
    free();
    copy(rhs);
    return *this;
}

template<class U>
std::ostream& operator<<(std::ostream& os, const StackList<U>& stack){
    auto current = stack._head;
    while(current){
        os << current->item;
        current = current->next;
    }
    return os;
}

class Buffer{
public:
    typedef StackList<char> container_type;
    typedef typename container_type::value_type value_type;
    typedef typename container_type::size_type size_type;
    Buffer();
    void insert(char c);
    char delete_c();
    void left(int k);
    void right(int k);
    int size(){return _size;};
private:
    container_type leftbuffer;
    container_type rightbuffer;
    size_type _size;
};
void 
Buffer::insert(char c){
    leftbuffer.push(c);
    _size++;
}
char
Buffer::delete_c(){
    if(rightbuffer.is_empty()){
        return '\0';
    }
    auto res = rightbuffer.peek();
    rightbuffer.pop();
    _size--;
    return res;
}

void
Buffer::left(int k){
    int count = 0;
    while(count < k && count < leftbuffer.size()){
        rightbuffer.push(leftbuffer.peek());
        leftbuffer.pop();
        count++;
    }
}

void 
Buffer::right(int k){
    int count = 0;
    while(count < k&& rightbuffer.size() > 0){
        leftbuffer.push(leftbuffer.peek());
        rightbuffer.pop();
        count++;
    }
}

int main(){
    //1.init StackList
    StackList<char> sl;
    //1.push method
    for(int i = 0; i < 10; i++){
        sl.push('a');
    }
    std::cout << sl << std::endl;;
    StackList<char> sl1(sl);
    std::cout << sl1 << std::endl;
    StackList<char> sl2;
    for(int i = 0 ; i < 10 ;i++){
        sl2.push('b');
    }
    sl = sl2;
    std::cout << sl << std::endl;

    StackList<char> sl3(std::move(sl));
    std::cout << sl3 << std::endl;
    std::cout << sl << std::endl;

    sl3 = std::move(sl1);
    std::cout << sl3 << std::endl;
    
}
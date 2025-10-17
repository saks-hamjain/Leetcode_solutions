class MyCircularDeque {
    public:
    vector<int> que;
    int size,capacity;
    public:
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        que.insert(que.begin(),value);
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        que.push_back(value);
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        que.erase(que.begin());
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        que.pop_back();
        size--;
        return true;
    }
    
    int getFront() {
       return isEmpty() ? -1: que.front(); 
    }
    
    int getRear() {
        return isEmpty() ? -1: que.back();
    }
    
    bool isEmpty() 
    {
        return size == 0;    
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
struct Node{
int key,value;
Node *next,*prev;
Node(int key,int value)
{
    this-> key = key;
    this-> value = value;
    next = prev = nullptr;
}
};
class LRUCache {
    unordered_map<int,Node*>hash;
    Node *head,*tail;
    int N;
public:
    
    LRUCache(int capacity) {
        N = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void insertToFront(Node *node)
    {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node-> prev;
    }
    int get(int key)
    {
        int value =-1;
        if(hash.find(key) != hash.end())
        {
            value = hash[key]->value;
            Node *node = hash[key];
            removeNode(node);
            insertToFront(node);
        }
        return value;
    }
    
    void put(int key, int value)
    {
        Node *node = new Node(key,value);
       if(hash.size() >= N)
       {
         Node *toRemove = tail->prev;
         removeNode(toRemove);
          hash.erase(toRemove->key);
         delete toRemove;
       }
        hash[key] = node;
        insertToFront(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
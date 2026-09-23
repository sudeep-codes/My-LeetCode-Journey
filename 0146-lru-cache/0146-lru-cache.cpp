class LRUCache {
public:

    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v):key(k), val(v), prev(nullptr), next(nullptr){}

    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void addToTail(Node* node){
        Node* prevNode=tail->prev;
        prevNode->next=node;
        node->prev=prevNode;
        node->next=tail;
        tail->prev=node;
    }

    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    ~LRUCache(){
        Node* curr=head;
        while(curr!=nullptr){
            Node* next=curr->next;
            delete curr;
            curr=next;
        }
    }

    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        Node* node=cache[key];
        remove(node);
        addToTail(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* oldNode=cache[key];
            remove(oldNode);
            delete oldNode;
        }
        Node* newNode =new Node(key, value);
        addToTail(newNode);
        cache[key]=newNode;
        if(cache.size()>capacity){
            Node* lru=head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
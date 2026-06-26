class Node {
public:
    int key, val, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast() {
        if (size == 0)
            return nullptr;

        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
private:
    int capacity;
    int currSize;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    void updateFreq(Node* node) {

        int oldFreq = node->freq;

        freqList[oldFreq]->removeNode(node);

        if (oldFreq == minFreq && freqList[oldFreq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    int get(int key) {

        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];

        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];
            node->val = value;

            updateFreq(node);
            return;
        }

        // Cache full
        if (currSize == capacity) {

            Node* node = freqList[minFreq]->removeLast();

            keyNode.erase(node->key);

            delete node;

            currSize--;
        }

        Node* newNode = new Node(key, value);

        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->addFront(newNode);

        keyNode[key] = newNode;

        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
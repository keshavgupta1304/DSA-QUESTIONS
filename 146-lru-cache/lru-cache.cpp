class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
            prev = nullptr;
            next = nullptr;
        }
    };

private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void addNode(Node* newNode) {
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node* delNode) {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); 
        tail = new Node(-1, -1); 
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* resNode = cache[key];
            int res = resNode->value;
            cache.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            cache[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* existingNode = cache[key];
            cache.erase(key);
            deleteNode(existingNode);
        }
        if (cache.size() == capacity) {
            cache.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        cache[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
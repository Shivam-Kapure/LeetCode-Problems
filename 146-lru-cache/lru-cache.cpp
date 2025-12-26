class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int limit;

    void insertNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->next = oldNext;
        oldNext->prev = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode) {
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        int ans = node->val;

        deleteNode(node);
        mp.erase(key);

        insertNode(node);
        mp[key] = node;

        return ans;
    }
    
    void put(int key, int value) {
        if(limit == 0)
            return;

        if(mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            mp.erase(key);
            deleteNode(oldNode);
            delete oldNode;

        }

        if(mp.size() == limit) {
            Node* oldNode = tail->prev;
            mp.erase(oldNode->key);
            deleteNode(oldNode);
            delete oldNode;
        }

        Node* newNode = new Node(key, value);
        insertNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
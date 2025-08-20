class Node{
    public:
        int count;
        unordered_set<string> keys;
        Node* next;
        Node* prev;
        Node(int count):count(count), next(nullptr), prev(nullptr){}
};

class AllOne {
public:
    Node* head;
    Node* tail;
    unordered_map<string, int> counts;
    unordered_map<int, Node*> nodes;
    AllOne() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        //if not in the counts map
        if(counts.find(key) == counts.end()){
            counts[key] = 1;
            //if node with count = 1 is not initialized
            if(head->next->count != 1){
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->next = head->next;
                newNode->prev = head;
                head->next->prev = newNode;
                head->next = newNode;
                nodes[1] = newNode;
            }else{
                head->next->keys.insert(key);
            }
        }else{
            int count = counts[key];
            Node* node = nodes[count];
            node->keys.erase(key);
            counts[key]++;
            //if the next node doesn't exit, create a node node
            if(node->next->count != count+1){
                Node* newNode = new Node(count + 1);
                newNode->prev = node;
                newNode->next = node->next;
                node->next->prev = newNode;
                node->next = newNode;
                nodes[count+1] = newNode;
                newNode->keys.insert(key);
            }else{
                node->next->keys.insert(key);
            }
            //delete the current node if empty
            if(node->keys.empty()){
                nodes.erase(count);
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete(node);
            }
        }
    }
    
    void dec(string key) {
        int count = counts[key];
        Node* node = nodes[count];
        counts.erase(key);
        node->keys.erase(key);
        if(count != 1){
            int newCount = count-1;
            counts[key] = newCount;
            //if the prev node doesn't exit, create a new node
            if(node->prev->count != newCount){
                Node* newNode = new Node(newCount);
                newNode->next = node;
                newNode->prev = node->prev;
                node->prev->next = newNode;
                node->prev = newNode;
                nodes[newCount] = newNode;
                newNode->keys.insert(key);
            }else{
                node->prev->keys.insert(key);
            }
        }
        //delete the current node if empty
        if(node->keys.empty()){
            nodes.erase(count);
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete(node);
        }
    }
    
    string getMaxKey() {
        if(tail->prev->count != -1){
            return *(tail->prev->keys.begin());
        }
        return "";
    }
    
    string getMinKey() {
        if(head->next->count != -1){
            return *(head->next->keys.begin());
        }
        return "";
    }
};

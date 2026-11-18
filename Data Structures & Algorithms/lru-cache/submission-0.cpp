#include<bits/stdc++.h>

class LRUCache {
public:
    class node{
        
        public:
        int key;
        int value;
        node* prev;
        node* next;
        node(int key,int value){
            this->key=key;
            this->value=value;
            prev=nullptr;
            next=nullptr;
        }
    };

    node* head=new node(-1,-1);
    node* tail =new node(-1,-1);

    std::unordered_map<int,node*> cache;

    int capacity;


    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(node* newNode){
        node * temp = head -> next;
    newNode -> next = temp;
    newNode -> prev = head;
    head -> next = newNode;
    temp -> prev = newNode;

    }
    
    void deleteNode(node* delNode){
        node* delnodeprev=delNode->prev;
        node* delnodenext=delNode->next;
        delnodeprev->next=delnodenext;
        delnodenext->prev=delnodeprev;
    }

    int get(int key) {
        if(cache.find(key)!=cache.end()){
            node* resnode=cache[key];
            int val=resnode->value;
            deleteNode(resnode);
            addNode(resnode);
            cache[key]=head->next;
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            node* existingNode=cache[key];
            cache.erase(key);
            deleteNode(existingNode);
        }
        if(cache.size()==capacity){
            node* temp=tail->prev;
            cache.erase(temp->key);
            deleteNode(temp);
        }
        addNode(new node(key,value));
        cache.insert({key,head->next});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
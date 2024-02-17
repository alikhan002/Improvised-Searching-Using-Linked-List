#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        vector<Node*> hash;
        bool is_head;

        Node(){

        }

        Node(int data, bool is_head = false){
            this->data = data;
            this->is_head = is_head;
            this->next = NULL;
        }

        void show_hash(){
            for(int x = 0; x < hash.size(); x++){
                cout << hash[x]->data << " ";
            }
        }
};

class List{
    public:
        Node* head;
        int size;

        List(){
            head = NULL;
        }

        void insert(int data){
            if(head == NULL){
                head = new Node(data, true);
                return;
            }
            Node* node;
            for(node = head; node->next != NULL; node = node->next);
            Node* newNode = new Node(data);
            node->next = newNode;
            head->hash.push_back(newNode);
        }

        void traverse(){
            for(Node* node = head; node != NULL; node = node->next){
                cout << node->data << " ";
            }
        }
};


int main(){
    List list;
    list.insert(2);
    list.insert(3);
    list.insert(4);
    cout << list.head->hash[0]->data;
    // list.head->show_hash();
    // list.traverse();
}
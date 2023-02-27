#include <iostream>

struct node{
    int value;
    node next;
};

class LinkedList{
    public
        node head;
        int num;
        
        LinkedList(){
            num = 0;
            head = NULL;
        }
        
    public
        void addNode(int n){
            
             Prepare Node
            
            node nodePtr = new node;
            node newNode = new node;
            newNode - value = n;
            newNode - next = NULL;
            
            if(isEmpty()){
                head = newNode;
            } else {
                nodePtr = head;
                while (nodePtr-next != nullptr) {
                    nodePtr = nodePtr-next;
                }
                
                nodePtr-next = newNode;
            }
            
            num++;
        }
        
        void traverse(){
            node nodePtr = new node;
            nodePtr = head;
            
            stdcout  Traversing...nn;
            
            if(isEmpty()){
                stdcoutThe list is empty;
                return;
            }else{
                while(nodePtr){
                    stdcout nodePtr-value   - ;
                    nodePtr = nodePtr - next;
                }
                stdcout  NULL;
            }
        }
        
        bool isEmpty(){
            bool status = (!head)  true  false;
            return status;
        }
};

int main(){
    
    LinkedList test;
    
    test.addNode(1);
    test.addNode(2);
    test.addNode(3);
    test.addNode(4);
    test.traverse();
    
    return 0;
}

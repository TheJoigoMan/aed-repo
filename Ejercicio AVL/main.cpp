#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct NodeAVL{
    int data;
    int h;
    NodeAVL* left;
    NodeAVL* right;
    NodeAVL(){
        left = nullptr;
        right = nullptr;
        data=-1;
    }
    NodeAVL(int val,int h=0){
        left=nullptr;
        right=nullptr;
        data=val;
        h=h;
    }
    void display(){
        cout<<data<<"-"<<h;
    }
    NodeAVL(int val,NodeAVL* l,NodeAVL* r, int h=0){
        left=l;
        right=r;
        data=val;
        h=h;
    }
};

int altura(NodeAVL* p){
    if(p == nullptr) return -1;
	return p->h;
}

void actualizar_altura(NodeAVL *node){
	if(node == nullptr) return;
	node->h = max(altura(node->left), altura(node->right)) + 1;
}

int rBalanceo(NodeAVL* p){
    if(p == nullptr) return 0;
	return altura(p->left) - altura(p->right);
}


class AVL{
private:
    NodeAVL* root;
public:
    AVL(){
        root = nullptr;
    }
    AVL(NodeAVL* n){
        root = n;
    }

    void rotateWithLeftChild(NodeAVL*& k2){
        NodeAVL* q = k2->left;
        k2->left = q->right;
        q->right = k2;	
        actualizar_altura(k2);
        actualizar_altura(q);
        k2 = q;
    }

    void rotateWithRightChild(NodeAVL*& k2){
        NodeAVL* q = k2->right;
        k2->right = q->left;
        q->left = k2;	
        actualizar_altura(k2);
        actualizar_altura(q);
        k2 = q;
    }
    void doubleWithLeftChild(NodeAVL*& k3){
        //TODO
    }
    void doubleWithRightChild(NodeAVL*& k3){
        //TODO
    }

    void insert(int val,NodeAVL*& n){
        if (n == nullptr)
            n = new NodeAVL(val);
        else if (val < n->data)
            insert(val, n->left);
        else
            insert(val, n->right); 
        
        actualizar_altura(n);
        balance(n);
    }

    void insert(int val){
        insert(val,root);
    }

    ///balance(t) asume que t esta balanceado o a 1 de serlo
    void balance(NodeAVL* & p){
        if(p==nullptr) return;
        if(rBalanceo(p)>1){
            ///desbalanceo izquierdo
            ///2 casos: LL o LR
            if(rBalanceo(p->left) <= -1)
                rotateWithRightChild(p->left);
            rotateWithLeftChild(p);
        }
        else{
            if(rBalanceo(p)<-1){
                ///desbalanceo derecho
                ///RL,RR
                if(rBalanceo(p->right) >= 1)
                    rotateWithLeftChild(p->right);
                rotateWithRightChild(p);
            }
        }
        ///actualizar altura
        p->h = max(altura(p->left), altura(p->right)) +1;
    }

    void raiz(){
        cout<<root->data<<"\n";
    }
    void bfs(NodeAVL*& p){
        if(p==nullptr) return;
        queue<NodeAVL*> q;
        q.push(p);
        while(!q.empty()){
            NodeAVL* x=q.front();
            ///cout<<x->data<<"-"<<x->h<<"\t";
            cout<<x->data<<"_"<<rBalanceo(x)<<"\t";
            q.pop();
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
    }
    void bfs(){
        bfs(root);
        cout<<"\n";
    }

    bool find(NodeAVL*& p, int value){
        if(p==nullptr) return false;
        if(value< p->data)
            return find(p->left, value);
        if(value> p->data)
            return find(p->right, value);
        return true;
    }

    bool find(int value){
        return find(root,value);
    }

    NodeAVL* fMin(NodeAVL* p){
        ///recursiva:
        if(p==nullptr) return nullptr;

        if(p->left==nullptr) return p;
        return fMin(p->left);
    }

    NodeAVL* fMin(){
        return fMin(root);
    }

    NodeAVL* fMax(NodeAVL* p){
        if(p!=nullptr)
            while(p->right)
                p=p->right;
        return p;
    }
    NodeAVL* fMax(){
        return fMax(root);
    }

    void remove(int val, NodeAVL*& p){
        if(p==nullptr) return;
        if(val < p->data){
            remove(val, p->left);
            //return;
        }
        else if(val> p->data){
            remove(val, p->right);
            //return;
        }
        else if((p->left!=nullptr) && (p->right!=nullptr)){
            int nuevo = fMin(p->right)->data;
            p->data= nuevo;
            remove(nuevo, p->right);
            //return;
        }
        else{
            NodeAVL* old=p;
            if(p->left != nullptr)
                p=p->left;
            else
                p=p->right;
            delete old;
        }
        balance(p);
    }
    void remove(int val){
        remove(val, root);
    }
};

int main(){
    AVL* bstree = new AVL;
    ///vector<int> v = {3,2,1,4,5,6,7}; Puntaje parcial
    vector<int> v = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9}; //puntaje total
    for(int i=0;i<v.size();i++){
        bstree->insert(v[i]);
        bstree->bfs();
    }

    bstree->remove(12);
    bstree->bfs();
    return 0;
}
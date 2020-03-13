#include <iostream>

using namespace std;

class STACKQUE{
public:
    typedef class node{
    public:
        int data;
        node * next;
        node * prev;
    }*nptr;
    int siz=0;
    nptr head;
    nptr tail;
    nptr cur;
    nptr tmp;
    STACKQUE(){
        head = NULL;
        tail = NULL;
        cur = NULL;
        tmp = NULL;
    }
    void pushintostruct(int d){
        nptr n = new node;
        n->data=d;
        if(head == NULL && siz==0){
            head=n;
            n->prev=NULL;
        }
        else{
            cur = tail;
            cur->next=n;
            n->prev=cur;
        }
        n->next=NULL;
        tail=n;
        cout << "Data been added to the struct" << endl;
        siz++;
    }
    void popfromstack(){
        if(siz==0){
            cout << "The Stack is empty" << endl;
            return ;
        }
        if(siz>1){
            tmp=tail;
            cur=tail;
            cur=cur->prev;
            cur->next=NULL;
            delete tmp;
            tail=cur;
        }
        else if(siz==1){
            tmp=head;
            head = NULL;
            tail = NULL;
            delete tmp;
        }
        cout << "Pop has been occurred" << endl;
        siz--;
    }
    void showqeue(){
        if(siz==0){
            cout << "The Qeue is empty" << endl;
            return ;
        }
        cout << "The elements are\t" ;
        cur=head;
        while(cur->next != NULL){
            cout << cur->data << " " ;
            cur=cur->next;
        }
        cout << cur->data << endl;
    }
    void showstack(){
        if(siz==0){
            cout << "The Stack is empty" << endl;
            return ;
        }
        cout << "The elements are\t" ;
        cur=tail;
        while(cur->prev!=NULL){
            cout << cur->data << " " ;
            cur=cur->prev;
        }
        cout << cur->data << endl;
    }
    void popfromqeue(){
        if(siz==0){
            cout << "The Qeue is empty" << endl;
            return ;
        }
        if(siz>1){
            tmp=head;
            cur=head;
            cur=cur->next;
            cur->prev=NULL;
            delete tmp;
            head=cur;
        }
        else if(siz==1){
            tmp=head;
            head = NULL;
            tail = NULL;
            delete tmp;
        }
        cout << "Pop has been occurred" << endl;
        siz--;
    }
    int getfstqeueelm(){
        cur=head;
        return cur->data;
    }
    int getfststackelm(){
        cur=tail;
        return cur->data;
    }
    void emptythestruct(){
        while(siz>=1){
            popfromstack();
        }
    }
    ~STACKQUE(){
        delete head;
        delete tail;
        delete cur;
        delete tmp;
    }
};

int main() {
    STACKQUE s,a,d;
    int n,n_s=1,da;
    cout << "How many input\t";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Input the data\t";
        cin >> da;
        s.pushintostruct(da);
    }
    for(int i=1;i<=n;i++){
        n_s*=2;
    }
    n_s--;
    cout << "The steps are\t" << n_s << endl;
    s.showstack();
    a.showstack();
    d.showstack();
    for(int i=1;i<=n_s;i++){
        if(i%3==1){
            if(s.siz==0){
                s.pushintostruct(a.getfststackelm());
                a.popfromstack();
            }
            else if(a.siz==0){
                a.pushintostruct(s.getfststackelm());
                s.popfromstack();
            }
            else if(a.getfststackelm()<s.getfststackelm()){
                s.pushintostruct(a.getfststackelm());
                a.popfromstack();
            }
            else{
                a.pushintostruct(s.getfststackelm());
                s.popfromstack();
            }
        }
        else if(i%3==2){
            if(s.siz==0){
                s.pushintostruct(d.getfststackelm());
                d.popfromstack();
            }
            else if(d.siz==0){
                d.pushintostruct(s.getfststackelm());
                s.popfromstack();
            }
            else if(d.getfststackelm()<s.getfststackelm()){
                s.pushintostruct(d.getfststackelm());
                d.popfromstack();
            }
            else{
                d.pushintostruct(s.getfststackelm());
                s.popfromstack();
            }
        }
        else{
            if(a.siz==0){
                a.pushintostruct(d.getfststackelm());
                d.popfromstack();
            }
            else if(d.siz==0){
                d.pushintostruct(a.getfststackelm());
                a.popfromstack();
            }
            else if(d.getfststackelm()<a.getfststackelm()){
                a.pushintostruct(d.getfststackelm());
                d.popfromstack();
            }
            else{
                d.pushintostruct(a.getfststackelm());
                a.popfromstack();
            }
        }
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "src ";
    s.showstack();
    cout << endl;
    cout << "aux ";
    a.showstack();
    cout << endl;
    cout << "dst ";
    d.showstack();
    cout << endl;

    return 0;
}

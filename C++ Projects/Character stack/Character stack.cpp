#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Node {
    char info;
    Node*  next;
public:
    Node(char c = '0' , Node* p = NULL);
    Node(Node&);
    ~Node();
    char get_info();
    void set_info(char);
    Node* get_next();
    void set_next(Node*);
    void Afisare();
    /*
    void CreateNew(char);
    Node* Parcurgere();
    */
};

Node::Node(char c , Node* p) { info = c; next = p; }

Node::Node(Node &c) { info = c.info; next = c.next; }

Node::~Node() { /*cout << "Am distrus: " << info << endl;*/ }

char Node::get_info() { return info; }

void Node::set_info(char a) { info=a; }

Node* Node::get_next() { return next; }

void Node::set_next(Node* p) { next=p; }

//void Node::CreateNew(char a) { next = new Node(a); }

void Node::Afisare() {
    cout << info << " -> ";
    if(next == NULL) cout << "-|" << endl;
    else next->Afisare();
}
/*
Node* Node::Parcurgere() {
    if(next == NULL) return this;
    return next->Parcurgere();
}
*/
class Stiva_de_caractere {
    Node* Top;
public:
    Stiva_de_caractere(Node* p = NULL);
    ~Stiva_de_caractere();
    void push(char);
    void pop();
    void top();
    void isempty();
    friend ostream& operator<<(ostream& , Stiva_de_caractere&);
    friend istream& operator>>(istream& , Stiva_de_caractere&);
    Stiva_de_caractere& operator-(Stiva_de_caractere&);
    Stiva_de_caractere& operator=(Stiva_de_caractere&);
    void InversareSir(char**);
    Node* get_Top();
    void Afisare();
};

Stiva_de_caractere::Stiva_de_caractere(Node* p) { Top = p; }

Stiva_de_caractere::~Stiva_de_caractere() {
    Node* temp = Top;
    while(temp != NULL) {
        Top = Top->get_next();
        delete temp;
        temp = Top;
    }
}

void Stiva_de_caractere::push(char c) { Node* temp = new Node(c,Top); Top = temp; }

void Stiva_de_caractere::pop() {
    if(Top != NULL) {
    Node* temp = Top;
    Top = Top->get_next();
    delete temp;
    }
}

void Stiva_de_caractere::top() { if(Top == NULL)  cout << "Top is NULL" << endl;  else  cout << "Top: " << Top->get_info() << endl; }

void Stiva_de_caractere::isempty() { if(Top == NULL)  cout << "Stack is empty" << endl;  else  cout << "Stack has values in it" << endl; }

ostream& operator<<(ostream& out , Stiva_de_caractere& S){
    Node* temp = S.Top;
    while(S.Top != NULL)
    {
        out<<S.Top->get_info()<<" -> ";
        S.Top = S.Top->get_next();
        delete temp;
        temp=S.Top;
    }
    out << "-|" << endl;
    return out;
}

istream& operator>>(istream& in, Stiva_de_caractere& S) {
    char c;
    in >> c;
    while(c != '0') {
        S.push(c);
        in >> c;
    }
    return in;
}

Stiva_de_caractere& Stiva_de_caractere::operator-(Stiva_de_caractere& S2) {
    Stiva_de_caractere *p = new Stiva_de_caractere;
    Node *temp , *temp2;
    while( Top != NULL && S2.Top != NULL ) {
        if(Top->get_info() > S2.Top->get_info())
            (*p).push(Top->get_info());
        else
            (*p).push(S2.Top->get_info());

        temp = Top;
        Top = Top->get_next();
        delete temp;

        temp2 = S2.Top;
        S2.Top = S2.Top->get_next();
        delete temp2;
    }
    return (*p);
}

Stiva_de_caractere& Stiva_de_caractere::operator=(Stiva_de_caractere& S) {

    if(this != &S) {
        delete Top;
        Top = S.Top;
    }

    return *this;
}

void Stiva_de_caractere::InversareSir(char **sir) {
    for(unsigned int i = 0 ; i < strlen(*sir) ; i ++) {
        push( (*sir)[i] );
    }
    for(unsigned int i = 0 ; i < strlen(*sir) ; i ++) {
        (*sir)[i] = Top->get_info();
        pop();
    }
}

Node* Stiva_de_caractere::get_Top() { return Top; }

void Stiva_de_caractere::Afisare() {
    if(Top)
        Top->Afisare();
    else
        cout << "-|"<<endl;
}

void CitireVector(int n) {
    Stiva_de_caractere v[n];
    int i;
    cout << "Signal end of input with caracter '0'" << endl;
    for( i = 0 ; i < n ; i ++) {
        cout << "Stack #" << i + 1 << ": "<<endl;
        cin >> v[i];
    }
    for( i = 0 ; i < n ; i ++) {
        cout << "Stack #" << i + 1 << ": "<<endl;
        cout << v[i];
    }
}

int main()
{
    int choice , n;
    char val;
    char* sir = new char[100];
    Stiva_de_caractere S,S2,S3;
    cout << "Stack of characters commands:" << endl;
    cout << "Push: 1" << endl;
    cout << "Pop: 2" << endl;
    cout << "Top: 3" << endl;
    cout << "IsEmpty: 4" << endl;
    cout << "Read via >> operator (Signal end of input with caracter '0'): 5" << endl;
    cout << "Show and empty current stack: 6" << endl ;
    cout << "Show: 7"<< endl;
    cout << "(-) Operation between 2 stacks: 8" << endl;
    cout << "Reversing a string (using a stack): 9" << endl ;
    cout << "Read a vector of stacks: 10" << endl;
    cout << "Do these copy constructors work?: 11" << endl;
    cout << "Press any other key to exit execution." << endl;
    do {
        cout << "Command: ";
        cin >> choice;
        switch(choice) {

        case 1:
            cout << "Value to be added: ";
            cin >> val;
            S.push(val);
            S.Afisare();
            break;

        case 2:
            S.pop();
            S.Afisare();
            break;

        case 3:
            S.top();
            break;

        case 4:
            S.isempty();
            break;

        case 5:
            cin >> S;
            S.Afisare();
            break;

        case 6:
            cout << S;
            break;

        case 7:
            S.Afisare();
            break;

        case 8:
            cout << "First stack (Signal end of input with caracter '0'):" << endl;
            cin >> S2;
            cout << "Second stack (Signal end of input with caracter '0'):" << endl;
            cin >> S3;
            S = S2 - S3;
            S.Afisare();
            break;

        case 9:
            cout << "Input string: ";
            cin.get();
            cin.get(sir,100);
            S.InversareSir(&sir);
            cout << sir << endl;
            break;

        case 10:
            cout << "Number of stacks: ";
            cin >> n;
            CitireVector(n);
            break;

        case 11:
            cout << "Value: ";
            cin >> val;
            Node x(val);
            Node y(x);
            cout << "Value copied in new node: ";
            y.Afisare();
            break;
        }
    }while(choice > 0 && choice < 12);
    return 0;
}

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Matrice {
  int **a;
  int lin, col;
public:
  Matrice(int** = NULL, int = 0, int = 0);
  Matrice(Matrice&);
  ~Matrice();
  int** get_a() { return a; }
  int get_dim() { return lin; }
  friend istream& operator>>(istream&, Matrice&);
  friend ostream& operator<<(ostream&, Matrice&);
  Matrice& operator=(Matrice&);
}Matrice_default(NULL, 0, 0);

Matrice::Matrice(int** mat, int lin_mat, int col_mat) {
  lin = lin_mat;
  if (lin_mat != 0)  lin_mat ++;
  col = col_mat;
  if (col_mat != 0)  col_mat ++;
  a = new int* [lin];
  for (int i = 0; i < lin; i++)
    a[i] = new int [col];

  for (int i = 1; i < lin; i++)
    for (int j = 1; j < col; j++)
      a[i][j] = mat[i - 1][j - 1];
}

Matrice::Matrice(Matrice& x) {
  lin = x.lin;
  col = x.col;
  a = new int* [lin];
  for (int i = 0; i < lin; i++)
    a[i] = new int [col];

  for (int i = 0; i < lin; i++)
    for (int j = 0; j < col; j++)
      a[i][j] = x.a[i][j];
}

Matrice::~Matrice() {
  for (int i = 0; i < lin; i++)
    delete [] a[i];
  delete []a;
}

istream& operator>>(istream& in, Matrice& x) {
  for (int i = 0; i < x.lin; i++)
    delete [] x.a[i];
  delete []x.a;

  cout << "Number of lines: ";
  in >> x.lin;
  if (x.lin != 0)  x.lin++;
  cout << "Number of columns: ";
  in >> x.col;
  if (x.col != 0)  x.col++;
  x.a = new int* [x.lin];
  for (int i = 0; i < x.lin; i++)
    x.a[i] = new int [x.col];

  cout << "Elements:" << endl;
  for (int i = 1; i < x.lin; i++)
    for (int j = 1; j < x.col; j++)
      in >> x.a[i][j];
  return in;
}

ostream& operator<<(ostream& out, Matrice& x) {
   for (int i = 1; i < x.lin; i++) {
    for (int j = 1; j < x.col; j++)
      out << x.a[i][j] << " ";
      out << endl;
    }
  return out;
}

Matrice& Matrice::operator=(Matrice& x) {
  if(this != &x) {
  for (int i = 0; i < lin; i++)
    delete [] a[i];
  delete []a;

  lin = x.lin;
  col = x.col;
  a = new int* [lin];
  for (int i = 0; i < lin; i++)
    a[i] = new int [col];

  for (int i = 0; i < lin; i++)
    for (int j = 0; j < col; j++)
      a[i][j] = x.a[i][j];
}
  return *this;
}

class Vector {
  int* v;
  int dim;
public:
  Vector(int* = NULL, int = 0);
  Vector(Vector&);
  ~Vector();
  int* get_v() { return v; }
  int get_dim() { return dim; }
  void push(int);
  friend istream& operator>>(istream&, Vector&);
  friend ostream& operator<<(ostream&, Vector&);
  Vector& operator=(Vector&);
};

Vector::Vector(int* arr, int dimensiune) {
  dim = dimensiune;
  v = new int [dim];
  for (int i = 0; i < dim; i++)
    v[i] = arr[i];
}

Vector::Vector(Vector& c) {
  dim = c.dim;
  v = new int [dim];
  for (int i = 0; i < dim; i++)
    v[i] = c.v[i];
}

Vector::~Vector() {
  delete []v;
}

void Vector::push(int x) {
  int* temp = new int [dim + 1];
  for(int i = 0; i < dim; i++) {
    temp[i] = v[i];
  }
  temp[dim] = x;
  delete []v;
  v = temp;
  dim++;
}

istream& operator>>(istream& in, Vector& x) {
  delete []x.v;
  cout << "Number of elements: ";
  in >> x.dim;
  x.v = new int [x.dim];
  for (int i = 0; i < x.dim; i++)
    in >> x.v[i];
  return in;
}

ostream& operator<<(ostream& out, Vector& x) {
  for (int i = 0; i < x.dim; i++)
    out << x.v[i] << " ";
  out << endl;
  return out;
}

Vector& Vector::operator=(Vector& x) {
  if (this != &x) {
  delete []v;
  dim = x.dim;
  v = new int [dim];
  for (int i = 0; i < dim; i++)
    v[i] = x.v[i];
  }
  return *this;
}

class Lista {
  Vector* l;
  int list_dim;
public:
  Lista(int = 0);
  Lista(Lista&);
  ~Lista();
  Vector* get_l() { return l; }
  int get_list_dim();
  friend istream& operator>>(istream&, Lista&);
  friend ostream& operator<<(ostream&, Lista&);
  Lista& operator=(Lista&);
}Lista_default(0);

Lista::Lista(int nr_linii) {
  list_dim = nr_linii + 1;
  l = new Vector [list_dim];
}

Lista::Lista(Lista& c) {
  list_dim = c.list_dim;
  l = new Vector [list_dim];
  for (int i = 0; i < list_dim; i++)
    l[i] = c.l[i];
}

Lista::~Lista() {
  delete []l;
}

int Lista::get_list_dim() { return list_dim; }

istream& operator>>(istream& in, Lista& x) {
  delete x.l;
  int nr, i, j, m;
  cout << "Number of nodes: ";
  in >> x.list_dim;
  x.l = new Vector [++x.list_dim];
  cout << "Number of edges: ";
  in >> m;
  cout << "Edges: ";
  for (int nr = 0; nr < m; nr++) {
    in >> i >> j;
    x.l[i].push(j);
    x.l[j].push(i);
  }
  return in;
}

ostream& operator<<(ostream& out, Lista& x) {
  for (int i = 1; i < x.list_dim; i++) {
    cout << i << ": " << x.l[i] << endl;
  }
  return out;
}

Lista& Lista::operator=(Lista& x) {
  if (this != &x) {
  delete l;
  list_dim = x.list_dim;
  l = new Vector [list_dim];
  for (int i = 0; i < list_dim; i++)
    l[i] = x.l[i];
  }
  return *this;
}

class Graf {
protected:
  int nr_noduri;
public:
  Graf(int i = 0) { nr_noduri = i; }
  Graf(Graf&);
  virtual ~Graf() = 0;
  virtual void BFS(int, int*, queue <int>) {};
};

Graf::Graf(Graf& c) {
  nr_noduri = c.nr_noduri;
}

Graf::~Graf() {}


class Graf_Neorientat : public Graf {
  static int Nr_Neorientate;
  Lista L;
public:
    Graf_Neorientat(Lista = Lista_default, int = Lista_default.get_list_dim());
    Graf_Neorientat(Graf_Neorientat&);
    ~Graf_Neorientat();
    static int get_Nr_Neorientate() { return Nr_Neorientate; }
    friend istream& operator>>(istream&, Graf_Neorientat&);
    friend ostream& operator<<(ostream&, Graf_Neorientat&);
    Graf_Neorientat& operator=(Graf_Neorientat&);
};

int Graf_Neorientat::Nr_Neorientate = 0;

Graf_Neorientat::Graf_Neorientat(Lista l, int noduri) : L(noduri), Graf(noduri) {
  L = l;
  Nr_Neorientate++;
}

Graf_Neorientat::Graf_Neorientat(Graf_Neorientat& c) : L(c.L), Graf(c.nr_noduri) {}

Graf_Neorientat::~Graf_Neorientat() { Nr_Neorientate--; }

istream& operator>>(istream& in, Graf_Neorientat& x) {
  in >> x.L;
  x.nr_noduri = x.L.get_list_dim();
  return in;
}

ostream& operator<<(ostream& out, Graf_Neorientat& x) {
  out << x.L;
  return out;
}

Graf_Neorientat& Graf_Neorientat::operator=(Graf_Neorientat& x) {
  if (this != &x) {
  L = x.L;
  nr_noduri = x.nr_noduri;
  }
  return *this;
}

class Graf_Orientat : public Graf {
  static int Nr_Orientate;
  Matrice A;
public:
  Graf_Orientat(int** = NULL, int = 0);
  Graf_Orientat(Graf_Orientat&);
  ~Graf_Orientat();
  void BFS(int, int*, queue <int>);
  static int get_Nr_Orientate() { return Nr_Orientate; }
  friend istream& operator>>(istream&, Graf_Orientat&);
  friend ostream& operator<<(ostream&, Graf_Orientat&);
  Graf_Orientat& operator=(Graf_Orientat&);
};

int Graf_Orientat::Nr_Orientate = 0;

Graf_Orientat::Graf_Orientat(int** m, int noduri) : A(m , noduri , noduri), Graf(noduri) { Nr_Orientate++; }

Graf_Orientat::Graf_Orientat(Graf_Orientat& c) : A(c.A), Graf(c.nr_noduri) {}

Graf_Orientat::~Graf_Orientat() { Nr_Orientate--; }

void Graf_Orientat::BFS(int start, int* tata, queue <int> coada) {
  for (int i = 1; i < nr_noduri; i++) {
    tata[i] = -1;
  }
  int** mat = A.get_a();
  coada.push(start);
  tata[start] = 0;
  while (!coada.empty()) {
    int i = coada.front();
    coada.pop();
    for (int j = 1; j < nr_noduri; j++) {
      if (mat[i][j] == 1 && tata[j] == -1) {
        coada.push(j);
        tata[j] = i;
      }
    }
  }
  cout << "Assigned tree (0 stands for root, - 1 stands for unvisited node):" << endl;
  for (int j = 1; j < nr_noduri; j++)
    cout << tata[j] << " ";
  cout << endl;
}

istream& operator>>(istream& in, Graf_Orientat& x) {
  in >> x.A;
  x.nr_noduri = x.A.get_dim();
  return in;
}

ostream& operator<<(ostream& out, Graf_Orientat& x) {
  out << x.A;
  return out;
}

Graf_Orientat& Graf_Orientat::operator=(Graf_Orientat& x) {
  if (this != &x) {
    A = x.A;
    nr_noduri = x.nr_noduri;
  }
  return *this;
}

void Citire_Neorientate(int n, Graf_Neorientat*& G) {
  G = new Graf_Neorientat [n];

  for (int i = 0; i < n; i++) {
    cout << "Graph #" << i + 1 << ":" << endl;
    cin >> G[i];
  }
  for (int i = 0; i < n; i++) {
    cout << "Graph #" << i + 1 << ":" << endl;
    cout << G[i];
  }
}

void Citire_Orientate(int n, Graf_Orientat*& G) {
  G = new Graf_Orientat [n];

  for (int i = 0; i < n; i++) {
    cout << "Graph #" << i + 1 << ":" << endl;
    cin >> G[i];
  }
  for (int i = 0; i < n; i++) {
    cout << "Graph #" << i + 1 << ":" << endl;
    cout << G[i];
  }
}

int main()
{
  int choice , n1, n2, val, start;
  Graf_Neorientat *GN = NULL;
  Graf_Orientat *GO = NULL;
  Graf* G = NULL;
  int* tata = new int [100];
  queue <int> coada;
  cout << "Read n directed graphs (represented using two-dimensional arrays): 1" << endl;
  cout << "Read n undirected graphs (represented using lists): 2" << endl;
  cout << "Number of active directed graphs: 3" << endl;
  cout << "Number of active undirected graphs: 4" << endl;
  cout << "Check connectivity of last directed graph read with command 1: 5" << endl;
  cout << "Does this upcasting and downcasting example work?: 6" << endl;
  cout << "Press any other key to exit execution." << endl;
  do {
  cout << "Command:";
  cin >> choice;
  switch (choice) {
    case 1:
      cout << "n = ";
      cin >> n1;
      Citire_Orientate(n1, GO);
      break;

    case 2:
      cout << "n = ";
      cin >> n2;
      Citire_Neorientate(n2, GN);
      break;

    case 3:
      cout << "There are: " << Graf_Orientat::get_Nr_Orientate() << " directed graphs" << endl;
      break;

    case 4:
      cout << "There are: " << Graf_Neorientat::get_Nr_Neorientate() << " undirected graphs" << endl;
      break;

    case 5:
      if (GO != NULL) {
        cout << "Starting at node: ";
        cin >> start;
        GO[n1 - 1].BFS(start, tata, coada);
      }
      else
        cout << "You need to input a directed graph first!" << endl;
      break;

    case 6:
      cout << "Graph type pointer holds object of type:" << endl << "Directed graph: 1" << endl << "Undirected graph: 2" << endl;
      cin >> val;
      if (val == 1)
      G = new Graf_Orientat;
      else
      G = new Graf_Neorientat;

    Graf_Orientat* r = dynamic_cast <Graf_Orientat*> (G);
    cout << "Using downcasting to see object type:" << endl;
    if(r == 0)
      cout << "Undirected graph" << endl;
    else
      cout << "Directed graph" << endl;
    break;
    }
    }while (choice > 0 && choice < 7);
  return 0;
}

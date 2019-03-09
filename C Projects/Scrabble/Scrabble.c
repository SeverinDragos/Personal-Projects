#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

struct Jeton {
  char litera;
  int valoare;
};

struct Patrat {
  int multiplicare_litera, multiplicare_cuvant, ocupat;
  struct Jeton jeton_actual;
};

int Compara (const void* a, const void* b) {
  return ((struct Jeton*)a)->litera - ((struct Jeton*)b)->litera;
}

struct Jeton* IncarcaJetoane (char* fisier) {
  FILE* fin = fopen(fisier, "r");
  if (fin == NULL)  printf("Error when opening file %s\n", fisier);
  struct Jeton* de_incarcat = malloc(sizeof(struct Jeton) * 26);
  int i = 0;

  while (1) {
    if (feof(fin))  break;
    fscanf(fin, "%c%d", &de_incarcat[i].litera, &de_incarcat[i].valoare);
    fgetc(fin);
    i++;
  }

  int (*pf)(const void*, const void*);
  pf = Compara;
  qsort(de_incarcat, 26, sizeof(struct Jeton), pf);

  fclose(fin);

  return de_incarcat;
}

void AfiseazaJetoane (struct Jeton* x) {
  for (int i = 0; i < 26; i++) {
    printf("%d: %c %d\n", i, x[i].litera, x[i].valoare);
  }
}

void StergeJetoane (struct Jeton* x) {
  free(x);
}

struct Patrat** CitesteTablaDeJoc (char* fisier, int* dim) {
  FILE* fin = fopen(fisier, "r");
  if (fin == NULL)  printf("Error when opening file %s\n", fisier);

  fscanf(fin, "%d", dim);
  fgetc(fin);
  struct Patrat** de_incarcat = malloc(sizeof(struct Patrat*) * (*dim));
  for (int i = 0; i < (*dim); i++) {
    de_incarcat[i] = malloc(sizeof(struct Patrat) * (*dim));
    for (int j = 0; j < (*dim); j++) {
      de_incarcat[i][j].multiplicare_cuvant = 1;
      de_incarcat[i][j].multiplicare_litera = 1;
      de_incarcat[i][j].ocupat = 0;
      de_incarcat[i][j].jeton_actual.litera = 0;
      de_incarcat[i][j].jeton_actual.valoare = 0;
    }
  }

  while (1) {
    if (feof(fin))   break;
    char culoare[10], s[10];
    int linie, coloana;
    fscanf(fin, "%s", culoare);
    fscanf(fin, "%s", s);
    fgetc(fin);

    linie = s[0] - 'a';
    strcpy(s, s + 1);
    sscanf(s, "%d", &coloana);
    coloana--;

    if (culoare[0] == 'b')
      de_incarcat[linie][coloana].multiplicare_litera = 2;
    else
    if (culoare[0] == 'a')
      de_incarcat[linie][coloana].multiplicare_litera = 3;
    else
    if (culoare[2] == 'z')
      de_incarcat[linie][coloana].multiplicare_cuvant = 2;
    else
      de_incarcat[linie][coloana].multiplicare_cuvant = 3;
  }

  return de_incarcat;

  fclose(fin);
};

///W stands for word multiplier, L stands for letter multiplier
void AfiseazaTablaDeJoc (struct Patrat** x, int dim) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      if (x[i][j].multiplicare_cuvant != 1) printf ("Wx%d   ", x[i][j].multiplicare_cuvant);
      else
      if (x[i][j].multiplicare_litera != 1) printf ("Lx%d   ", x[i][j].multiplicare_litera);
      else  printf ("empty ");
    }
    printf ("\n");
  }
}

void StergeTablaDeJoc (struct Patrat** x, int dim) {
  for (int i = 0; i < dim; i++) {
    free(x[i]);
  }
  free(x);
}

void DepunereCuvant (struct Jeton* tablou_jetoane, struct Patrat** TablaJoc, int lin, int col, char* cuvant_depus, int mod_depunere) {
  if (mod_depunere == 1) {
    for (int i = 0; i < strlen(cuvant_depus); i++) {
      if (cuvant_depus[i] >= 'a' && cuvant_depus[i] <= 'z') {
        TablaJoc[lin][col + i].jeton_actual.litera = cuvant_depus[i];
        TablaJoc[lin][col + i].jeton_actual.valoare = 0;
      }
      else {
      TablaJoc[lin][col + i].jeton_actual.litera = tablou_jetoane[cuvant_depus[i] - 'A'].litera;
      TablaJoc[lin][col + i].jeton_actual.valoare = tablou_jetoane[cuvant_depus[i] - 'A'].valoare;
      }
    }
  }
  else {
    for (int i = 0; i < strlen(cuvant_depus); i++) {
      if (cuvant_depus[i] >= 'a' && cuvant_depus[i] <= 'z') {
        TablaJoc[lin + i][col].jeton_actual.litera = cuvant_depus[i];
        TablaJoc[lin + i][col].jeton_actual.valoare = 0;
      }
      else {
      TablaJoc[lin + i][col].jeton_actual.litera = tablou_jetoane[cuvant_depus[i] - 'A'].litera;
      TablaJoc[lin + i][col].jeton_actual.valoare = tablou_jetoane[cuvant_depus[i] - 'A'].valoare;
      }
    }
  }

}

int CalculDepunere (struct Jeton* tablou_jetoane, struct Patrat** TablaJoc, int lin, int col, int len, int mod_depunere) {
  int total = 0, multiplier = 1, nr_jetoane_depuse = 0;

  if (mod_depunere == 1) {
    for (int i = 0; i < len; i++) {
      if (TablaJoc[lin][col + i].ocupat == 0) {
      nr_jetoane_depuse++;
      total += TablaJoc[lin][col + i].jeton_actual.valoare * TablaJoc[lin][col + i].multiplicare_litera;
      multiplier *= TablaJoc[lin][col + i].multiplicare_cuvant;
      TablaJoc[lin][col + i].ocupat = 1;
      }
      else {
        total += TablaJoc[lin][col + i].jeton_actual.valoare;
      }
    }
  }
  else {
    for (int i = 0; i < len; i++) {
      if (TablaJoc[lin + i][col].ocupat == 0) {
      nr_jetoane_depuse++;
      total += TablaJoc[lin + i][col].jeton_actual.valoare * TablaJoc[lin + i][col].multiplicare_litera;
      multiplier *= TablaJoc[lin + i][col].multiplicare_cuvant;
      TablaJoc[lin + i][col].ocupat = 1;
      }
      else {
        total += TablaJoc[lin + i][col].jeton_actual.valoare;
      }
    }
  }
  total *= multiplier;
  if (nr_jetoane_depuse == 7) total += 50;
  return total;
}

int main()
{
  int Puncte[5] = {0}, Jucator_Curent, dim, lin, col, mod_depunere, i;
  char s[25];
  struct Jeton* tablou_jetoane = IncarcaJetoane("tiles.txt");

  struct Patrat** TablaJoc = CitesteTablaDeJoc("board.txt", &dim);

  ///AfiseazaTablaDeJoc(TablaJoc, dim);     //Prints game board
  ///AfiseazaJetoane(tablou_jetoane);          //Prints game tiles


  FILE* fin = fopen("game.txt", "r");
  if (fin == NULL)  printf("Error when opening file %s\n", "joc.txt");

  while (1) {
  if (feof(fin))  break;

  fscanf(fin, "%d", &Jucator_Curent);
  fscanf(fin, "%s", &s);

  if (isalpha(s[0])) {
    lin = s[0] - 'a';
    strcpy(s, s + 1);
    mod_depunere = 1;
  }
  else {
    lin = s[strlen(s) - 1] - 'a';
    strcpy(s + strlen(s) - 1, s + strlen(s));
    mod_depunere = 2;
  }

    sscanf(s, "%d", &col);
    col--;

    fscanf(fin, "%s", s);

    DepunereCuvant(tablou_jetoane, TablaJoc, lin, col, s, mod_depunere);
    Puncte[Jucator_Curent] += CalculDepunere(tablou_jetoane, TablaJoc, lin, col, strlen(s), mod_depunere);
  }

  if (Puncte[1] > Puncte[2])  printf ("Player 1 won the game with a total of %d points!\n", Puncte[1]);
  else if (Puncte[1] < Puncte[2]) printf ("Player 2 won the game with a total of %d points!\n", Puncte[2]);
  else printf ("Both players accumulated a total of %d points!", Puncte[1]);

  fclose(fin);
  StergeTablaDeJoc(TablaJoc, dim);
  StergeJetoane(tablou_jetoane);
  return 0;
}

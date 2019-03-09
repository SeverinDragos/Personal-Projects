#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

enum Rima{RimaImperecheata = 1, RimaIncrucisata, RimaImbratisata};

struct Poezie {
  int nr_versuri;
  char** Versuri;
};

struct cuvant {
  char cuv[20];
  int nr_ap;
};

struct AmprentaStilistica {
  enum Rima rima;
  int nr_min, nr_max;
  char* cuv_dominant;
};

void IncarcaPoezie (char* fisier, struct Poezie* de_incarcat) {
  FILE* fin;
  fin = fopen(fisier,"r");
  if (fin == NULL)  printf("Error when opening file %s/n", fisier);
  de_incarcat->nr_versuri = 0;
  int i = 0;
  de_incarcat->Versuri = malloc(sizeof(char*) * 4);
  if (de_incarcat->Versuri == NULL) printf("Allocation failure 1\n");

  while (1) {
  if (feof(fin)) break;
  char s[100];
  char** temp = realloc(de_incarcat->Versuri, sizeof(char*) * (de_incarcat->nr_versuri + 4));
  if (temp)
    de_incarcat->Versuri = temp;
  else
    printf("Allocation failure 2\n");

  for (int j = 0; j < 4; j++) { /// Avem numai catrene
    fgets(s, 100, fin);
    de_incarcat->Versuri[i] = malloc(sizeof(char) * (strlen(s) + 1));
    if (de_incarcat->Versuri[i] == NULL) printf("Allocation failure 3\n");
    strcpy(de_incarcat->Versuri[i], s);
    i++;
  }
  de_incarcat->nr_versuri += 4;
  fgets(s,100,fin);
  }

  fclose(fin);
}

void AfiseazaPoezie (struct Poezie de_afisat) {
  for (int i = 0; i < de_afisat.nr_versuri; i++) {
    printf("%s", de_afisat.Versuri[i]);
  }
}

void StergerePoezie (struct Poezie* x) {
  for (int i = 0; i < x->nr_versuri; i++) {
    free(x->Versuri[i]);
  }
  free(x->Versuri);
}

enum Rima DeterminareRima (struct Poezie x) {
  char vers1[3], vers2[3];
  int poz;
  for (poz = strlen(x.Versuri[0]); poz >= 0; poz--)
    if ((x.Versuri[0][poz] >= 65 && x.Versuri[0][poz] <= 90) ||
        (x.Versuri[0][poz] >= 97 && x.Versuri[0][poz] <= 122))  break;

  vers1[0] = x.Versuri[0][poz - 1];
  vers1[1] = x.Versuri[0][poz];
  vers1[2] = '\0';

  for (poz = strlen(x.Versuri[1]); poz >= 0; poz--)
    if ((x.Versuri[1][poz] >= 65 && x.Versuri[1][poz] <= 90) ||
        (x.Versuri[1][poz] >= 97 && x.Versuri[1][poz] <= 122))  break;

  vers2[0] = x.Versuri[1][poz - 1];
  vers2[1] = x.Versuri[1][poz];
  vers2[2] = '\0';
  if (strcmp(vers1, vers2) == 0)  return RimaImperecheata;

  for (poz = strlen(x.Versuri[2]); poz >= 0; poz--)
    if ((x.Versuri[2][poz] >= 65 && x.Versuri[2][poz] <= 90) ||
        (x.Versuri[2][poz] >= 97 && x.Versuri[2][poz] <= 122))  break;

  vers2[0] = x.Versuri[2][poz - 1];
  vers2[1] = x.Versuri[2][poz];
  vers2[2] = '\0';
  if (strcmp(vers1, vers2) == 0)  return RimaIncrucisata;

  return RimaImbratisata;
}


int Comparare (const void* a, const void* b) {
  if (((struct cuvant*)a)->nr_ap == ((struct cuvant*)b)->nr_ap)
    return strcmp(((struct cuvant*)a)->cuv, ((struct cuvant*)b)->cuv);
  else return ((struct cuvant*)b)->nr_ap - ((struct cuvant*)a)->nr_ap;
}

char* DeterminareCuvantDominant (struct Poezie x) {
  int indice = 0;
  struct cuvant* tablou = malloc(sizeof(struct cuvant) * indice);

  for (int i = 0; i < x.nr_versuri; i++) {
    char* p = strtok(x.Versuri[i], ",.- ;!?\n");
    while (p) {
      if (strlen(p) >= 3) {
        strlwr(p);
        int j;
        for (j = 0; j < indice; j++) {
          if (strcmp(tablou[j].cuv, p) == 0) {
            tablou[j].nr_ap++;
            break;
          }
        }
        if (j == indice) {
          struct cuvant* temp = realloc(tablou, sizeof(struct cuvant) * (indice + 1));
          if (temp) tablou = temp;
          else  printf("Allocation failure 4\n");
          tablou[indice].nr_ap = 1;
          strcpy(tablou[indice].cuv, p);
          //printf("%s %d\n", tablou[indice].cuv, tablou[indice].nr_ap);
          indice++;
        }
      }
      p = strtok(NULL, ",.- ;!?\n");
    }
  }

  int (*pf)(const void*, const void*);
  pf = Comparare;
  qsort(tablou, indice, sizeof(struct cuvant), pf);

  char* rez = malloc(sizeof(char) * strlen(tablou[0].cuv));
  strcpy(rez, tablou[0].cuv);
    free(tablou);
  return rez;
}

struct AmprentaStilistica DeterminareAmprentaStilistica (int n, ...) {
  struct Poezie x;
  struct AmprentaStilistica de_returnat;
  de_returnat.nr_max = 0;
  de_returnat.nr_min = 99999;
  de_returnat.cuv_dominant = malloc(sizeof(char)); /// pentru \0
  strcpy(de_returnat.cuv_dominant, "");
  int max = 0, nr_ap_rima[4] = {0};

  va_list lp;
  va_start(lp, n);

  for (int i = 0; i < n; i++) {
    IncarcaPoezie(va_arg(lp, char*), &x);

    int j;
    j = DeterminareRima(x); ///1.
    nr_ap_rima[j]++;
    if (nr_ap_rima[j] > max) {
      max = nr_ap_rima[j];
      de_returnat.rima = j;
    }

    int nr_strofe = x.nr_versuri / 4;   ///2.
    if (nr_strofe > de_returnat.nr_max)
      de_returnat.nr_max = nr_strofe;
    if (nr_strofe < de_returnat.nr_min)
      de_returnat.nr_min = nr_strofe;

    char* p;
    p = DeterminareCuvantDominant(x); ///3.
    char* temp = realloc(de_returnat.cuv_dominant, sizeof(char) * (strlen(p) + strlen(de_returnat.cuv_dominant) + 1) );
    if (temp) de_returnat.cuv_dominant = temp;
    else  printf("Allocation failure 5\n");
    strcat(de_returnat.cuv_dominant, p);
    strcat(de_returnat.cuv_dominant, " ");
  }
  StergerePoezie(&x);

  return de_returnat;
};

int main()
{
  struct AmprentaStilistica x;
  x = DeterminareAmprentaStilistica(5, "poem1.txt", "poem2.txt", "poem3.txt", "poem4.txt", "poem5.txt");
  printf("Our author`s tendencies:\n");
  switch(x.rima) {
    case 1:
      printf("Rhyme: Couplet-Rhyme\n");
      break;
    case 2:
      printf("Rhyme: Crossed-Rhyme\n");
      break;
    case 3:
      printf("Rhyme: Envelope-Rhyme\n");
      break;
    }
  printf("Minimum number of stanzas:%d\nMaximum number of stanzas:%d\nCommonly used words:%s\n", x.nr_min, x.nr_max, x.cuv_dominant);

  struct Poezie de_analizat;
  enum Rima rima_analiza;
  char* cuv;
  IncarcaPoezie("analysed poem.txt", &de_analizat);
  int nr_strofe = de_analizat.nr_versuri / 4;
  rima_analiza = DeterminareRima(de_analizat);
  cuv = DeterminareCuvantDominant(de_analizat);
  printf("\nGiven poem characteristics:\n");
  switch(rima_analiza) {
    case 1:
      printf("Rhyme: Couplet-Rhyme\n");
      break;
    case 2:
      printf("Rhyme: Crossed-Rhyme\n");
      break;
    case 3:
      printf("Rhyme: Envelope-Rhyme\n");
      break;
    }
  printf("Number of stanzas:%d\nPreponderant word:%s\n", nr_strofe, cuv);
  printf("\nIs this the work of our author?\n");
  char decizie[4] = "Yes";

  if (x.rima != rima_analiza)
    strcpy(decizie, "No");

  if (nr_strofe > x.nr_max || nr_strofe < x.nr_min)
    strcpy(decizie, "No");

  if (strstr(x.cuv_dominant, cuv) == NULL)
    strcpy(decizie, "No");

  printf("%s", decizie);

  StergerePoezie(&de_analizat);
  return 0;
}

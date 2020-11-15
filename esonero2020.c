#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void crypto(char[], char[], char[]);
void decrypto(char[], char[], char[]);
void manualKey(char[], char[]);
void casualKey(char[], char[]);
void inserisciStringa(char[]);

time_t t;

int main(void){

  char ptxt[128];
  char key[128];
  char keyCas[128];
  char atxt[128];
  char s;

  srand((unsigned) time(&t));
  inserisciStringa(ptxt);

  do{

    puts("scegli un'opzione: \n a. Key manuale \n b. Key casuale \n i. Reinserisci stringa \n x. Esci dal programma \n");
    scanf("%c", &s);
    getchar();

    switch (s){
      case 'a':  {
                  manualKey(ptxt, key);
                  crypto(ptxt, key, atxt);
                }
      break;
      case 'b': {
                  puts("\n Generazione chiave casuale... \n");
                  casualKey(ptxt, keyCas);
                  crypto(ptxt, keyCas, atxt);
                }
      break;
      case 'i': inserisciStringa(ptxt);
      break;
      case 'x':
          puts("uscita in corso");
      break;
      default: puts("scelta sbagliata, reinserire la scelta");
      break;
    }
  }while(s!='x' && s!='a' && s!='b');



  return 0;
}
void inserisciStringa(char ptxt[]){
  puts("Inserisci stringa da cifrare (max.128 caratteri) \a \a \n");
  fgets(ptxt, 127, stdin);
  printf("la stringa inserita e': %s \n", ptxt);
}


void manualKey(char ptxt[], char key[]){
  char str[128];
  int lenTxt=strlen(ptxt);
  int h=0;
  do{
    printf("inserire chiave di minimo %d caratteri \n", lenTxt);
    fgets(str, 128, stdin);
    h=strlen(str)-lenTxt;

  }while(strlen(str)<lenTxt);
  for(int i=0; i<h; i++){
    str[strlen(str)-h]='\0';
  }
  
  printf("la key è: %s \n", key);

}


void casualKey(char ptxt[], char key[]){
  char str[128];
  int k=0;
  int lenTxt=strlen(ptxt);
  for(int i=0; i<lenTxt; i++){
    k=(rand()%128);
    if(k<33) k=k+33;
    else k=k;
    str[i]=k;
  }
  printf("la key è: %s \n", str);
}

void crypto(char ptxt[], char key[], char atxt[]){
  int l=strlen(ptxt);
  int v=0;
  char txt[128];
  for(int i=0; i<l; i++){

      v=((int)ptxt[i]^(int)key[i])+33;
      atxt[i]=v;

  }

  printf("\nil testo cifrato è: %s", atxt);
  for(int i=0; i<l; i++){

      v=((int)atxt[i]-33)^(int)key[i];
      txt[i]=v;

  }
  printf("\nil testo decifrato è: %s\n\n", txt);
}

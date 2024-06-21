/**************************************************
*
* Eduardo Teixeira Rocato
* Trabalho 1
* Professor(a): Diego Padilha Rupert
*
*/
#include <stdio.h>
#define MAX 100

/* Armazena informações de uma capivara */

typedef struct {
int numero; /* Número da capivara = posição na largada */
int ultrapass; /* Quantidade de ultrapassagens feitas */
} capivara;

void ultrapassa(capivara n1, capivara n2){
    capivara aux;
    n1 = aux;
    n2 = n1;
    n2 = aux;
}

void intercala(int p, int q, int r, capivara v[MAX])
{
    int i, j, k;
    capivara w[r-p];
   
    i = p; j = q; k = 0;
        while (i < q && j < r) {
            if (v[i].ultrapass > v[j].ultrapass) {
                 w[k] = v[i]; i++; }
            else if(v[i].ultrapass == v[j].ultrapass){
                if(v[i].numero < v[j].numero){
                    w[k] = v[i];
                    i++;
                }
                else{
                    w[k] = v[j];
                    j++;
                }
            }
            else {
                 w[k] = v[j]; j++; }
            k++;
}

       
while (i < q) {
    w[k] = v[i]; i++; k++; }
while (j < r) {
    w[k] = v[j]; j++; k++; }
for (i = p; i < r; i++)
    v[i] = w[i-p];
}

void mergesort(int p, int r, capivara v[MAX])
{
int q;
if (p < r - 1) {
    q = (p + r) / 2;
    mergesort(p, q, v);
    mergesort(q, r, v);
    intercala(p, q, r, v);
    }
}
int main()
{
    int n, x;
    scanf("%d", &n);
    capivara capi[n];
    for(int i = 0;i<n; i++){
        capi[i].numero = i+1;
        capi[i].ultrapass = 0;
    }
    while(scanf("%d", &x)==1){
        capivara aux;
        for(int i =0; i<n ; i++){
            if(capi[i].numero == x){
                capi[i].ultrapass++;
                aux = capi[i];
                capi[i] = capi[i-1];
                capi[i-1] = aux;
                
            }
        }
    }
   
    for(int i = 0; i < n; i ++){
        if(i == n-1){
            printf("%d\n", capi[i].numero);
           
        }
        else
            printf("%d ", capi[i].numero);
       
    }
   
    mergesort(0, n, capi);
   
   
    for(int i = 0; i < n; i++){
        if(i == n-1){
            printf("%d\n", capi[i].numero);
           
        }
        else
            printf("%d ", capi[i].numero);
       
    }
   
    return 0;
   
}
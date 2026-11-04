#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct no{
    int num;
    struct no *prox;
};
void criaInsereRoleta(struct no **topo,int v[])
{
    struct no *novo,*fim,*primeiro;
    int i;
    for(i=0;i<37;i++)
    {
        novo = malloc(sizeof(*novo));
        novo->num = v[i];
        if(*topo==NULL)
           *topo = fim = novo;
        else
        {
            fim->prox = novo;
            fim = novo;
        }
    }
    fim->prox = *topo;
}
void sorteio(int f,struct no *topo)
{
    int aleatorio,i;
    struct no *x;
    aleatorio = rand() % 20 + 1;
    f = f*aleatorio;
    x=topo;
    for(i=0;i<f;i++)
    {
        x=x->prox;
    }
    if(x->num == 0)
        printf("\nNumero Sorteado:\033[32m%d\033[0m\n", x->num);
       else
          if(x->num == 1 || x->num == 3 || x->num == 5 ||
            x->num == 7 || x->num == 9 || x->num == 12 ||
            x->num == 14 || x->num == 16 || x->num == 18 ||
            x->num == 19 || x->num == 21 || x->num == 23 ||
            x->num == 25 || x->num == 27 || x->num == 30 ||
            x->num == 32 || x->num == 34 || x->num == 36)
             printf("\nNumero sorteado:\033[31m%d\033[0m\n", x->num);
         else
             printf("\nNumero sorteado:\033[30m%d\033[0m\n", x->num);
}
int main()
{
    int roleta[37] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26 };
    struct no *topo = NULL;
    int f;
    criaInsereRoleta(&topo,roleta);
    do{
    printf("\nDigite o nivel da sua força de 1 a 10 (-1 para encerrar):");
    scanf("%d",&f);
    if(f!=-1)
      if(f<1 || f>10)
        if(f<1)
          printf("\nNão comeu hoje?, digite uma força maior!");
        else
          printf("\nVai com calma, digite uma força menor!");
      else
       sorteio(f,topo);
    }while(f!=-1);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#define N 9 

typedef struct elemento// struct elemento
{
  int valor;
  struct elemento *proximo;
}Tipoelemento; 


Tipoelemento *criarelemento(int valor)
{
   Tipoelemento *elemento = malloc(sizeof(Tipoelemento));
   elemento->valor = valor ; 
   elemento->proximo = NULL ; 
}

void criarinicio(Tipoelemento **inicio)
{
  *inicio = NULL ;
}

Tipoelemento *insere(Tipoelemento *inicio, Tipoelemento *elemento) // variavel  *ponteiro elemento ==cont
{
  
  if(inicio==NULL)  //se o inicio for == null a lista ainda está vazia
  {
    inicio = elemento;  // se lista vazia insere o primeiro elemento, caso contrario o recursivo chama até chegar no ultimo
  }else{ // se a lista não está vazia vai entrar 
    inicio->proximo = insere(inicio->proximo,elemento); // chama a funcao até o atual ser igual a null
  }
    return inicio ;
}

Tipoelemento *imprime(Tipoelemento *inicio)
{
  if(inicio == NULL){
    printf("LISTA VAZIA \n");
  }else
  {
    Tipoelemento *temp = inicio;
    printf("IMPRIMINDO: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->valor); 
        temp = temp->proximo;
    }
    printf("\n");
  }
}

Tipoelemento *removelista (Tipoelemento *elemento) //remove lista completa
{ 
  Tipoelemento *temp = elemento;
  if(elemento == NULL)
  {
    return elemento;
   
  }
  elemento = elemento->proximo;
  printf("%d ",temp->valor);
  free(temp);
  removelista(elemento);
}
void imprimirtabuleiro (int matriz[N][N]) 
{ 
    int coluna=0;
    int linha=0;
    int cont = 0;
    int contadorl = 0;
    int contadorc =0;
    system("color 3f");
    printf("  |1|2|3| |4|5|6| |7|8|9|\n\n");
     while(linha < N)
     {
         printf("%d |",contadorl+1);
         contadorl++;
         coluna = 0;
         while(coluna < N)
          { 
            printf("%d|",matriz[linha][coluna]);
            coluna++;
             if((coluna==3)||(coluna==6))
             {
               printf(" |");
             } 
      }
     if((linha==2)||(linha==5))
      {
        printf("\n");
      }
      printf("\n");
      linha++;
    }
}

void preenchercomzero(int matriz[N][N],int matrizauxiliar[N][N]) 
{
    int coluna=0;
    int linha=0;
     while(linha < N)
     {
       coluna = 0;
       while(coluna < N)
       {
         matriz[linha][coluna]=0;
         matrizauxiliar[linha][coluna]=0;
         coluna++;
       }
      linha++;
     }
}

int verificarcoluna(int valorusuario,int coluna ,int matriz[N][N])  //funcÃƒÂ£o (1.1) verifica se jÃƒÂ¡ existe aquele valor da coluna !!
{
  int cont= 0;
  int verifica = 1;    //o valor dado pelo usuario e valido !!
  
  while((cont < 9) && (verifica == 1))  /*a variavel coluna ÃƒÂ© fixa, para que ela pecorra a coluna escolhida do usuario*/
  {
    if((matriz[cont][coluna] == valorusuario)&& (valorusuario != 0)) //!= 0  para ele poder modificar o valor
    {
       verifica = 0;      //no caso do valor ser encontrado dentro da coluna ele deixa de ser valido !!
    } 
    cont++;        //incremento do cont para ele "andar na coluna"
  } 
  return verifica; //isso ÃƒÂ© oque irÃƒÂ¡ retorna para a funÃƒÂ§ÃƒÂ£o main ,no caso serÃƒÂ¡ um boolean (true or false)
}

int verificarlinha(int valorusuario,int linha ,int matriz[N][N])  //funÃƒÂ§ÃƒÂ¢o (1.2) faz a mesma coisa da funÃƒÂ§ÃƒÂ£o anterio mas para a linha
{
  int cont= 0;
  int verifica = 1;                                             
  
  while((cont < 9) && (verifica == 1))  
  {
    if((matriz[linha][cont] == valorusuario)&& (valorusuario != 0)) //!= 0  para ele poder modificar o valor
    {
       verifica = 0;                                    
    } 
    cont++;                                                  
  } 
  return verifica;
}

int verificabloco(int valorusuario,int linha,int coluna,int matriz[N][N]) //funÃƒÂ§ÃƒÂ£o (1.3) verifica se jÃƒÂ¡ existe valor nos blocos 
{
    int verifica = 1;
    int linha_verificada = linha;
    int coluna_verificada = coluna;
    if(coluna_verificada <=2)
    {
     
       if(linha_verificada <=2)
       {
         //entrou no bloco(1),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso; //corrigido
         linha_verificada = 0 ; 
         coluna_verificada = 0 ;
           while((linha_verificada <= 2)&&(verifica ==1))
           {
            coluna_verificada = 0 ;
              while((coluna_verificada<=2)&&(verifica == 1))
              {
               if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0)) 
               {
                 verifica = 0;
               }else
               {
                 coluna_verificada = coluna_verificada +1 ;
               }
              } 
            linha_verificada = linha_verificada +1;
           }
        }else if((linha_verificada >=3)&&(linha_verificada <=5))
         {
         //entrou no bloco(4),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 3 ; 
           coluna_verificada = 0 ;
            while((linha_verificada <= 5)&&(verifica ==1))
            { 
             coluna_verificada = 0 ;
              while((coluna_verificada<=2)&&(verifica == 1))
              {
               if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0)) 
                {
                 verifica = 0;
                }else{
                  coluna_verificada = coluna_verificada +1 ;
                }
              }
             linha_verificada = linha_verificada +1;
            }
        }else if((linha_verificada >=6)&&(linha_verificada <=8))
        {
         //entrou no bloco(7),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 6 ; 
           coluna_verificada = 0 ;
          while((linha_verificada <= 8)&&(verifica ==1))
          {
             coluna_verificada = 0 ;
               while((coluna_verificada<=2)&&(verifica == 1))
              {
                 if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0))
                  {
                    verifica = 0;
                  }else{
                    coluna_verificada = coluna_verificada +1 ;
                  }
              }
            linha_verificada = linha_verificada +1;
           }
         }
     }else if((coluna_verificada >= 3)&&(coluna_verificada <=5))
     {
        if(linha_verificada <=2)
        { 
        //entrou no bloco(2),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 0 ; 
           coluna_verificada = 3 ;
             while((linha_verificada <= 2)&&(verifica ==1))
             {
               coluna_verificada = 3 ;
               while((coluna_verificada<=5)&&(verifica == 1))
                {
                 if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0)) 
                  {
                   verifica = 0;
                  }else{
                   coluna_verificada = coluna_verificada +1 ;
                  }
                }
             linha_verificada = linha_verificada +1;
            }
        }else if((linha_verificada >=3)&&(linha_verificada <=5)){
          //entrou no bloco(5),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 3 ; 
           coluna_verificada = 3 ;
              while((linha_verificada <= 5)&&(verifica ==1))
              {
               coluna_verificada = 3 ;
                 while((coluna_verificada<=5)&&(verifica == 1))
                 {
                   if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0))
                   {
                     verifica = 0;
                   }else{
                     coluna_verificada = coluna_verificada +1 ;
                   }
                 }
               linha_verificada = linha_verificada +1;
              }
        }else if((linha_verificada >=6)&&(linha_verificada <=8)){
          //entrou no bloco(8),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 6 ; 
           coluna_verificada = 3 ;
             while((linha_verificada <= 8)&&(verifica ==1))
             {
               coluna_verificada = 3 ;
                 while((coluna_verificada<=5)&&(verifica == 1))
                 {
                   if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0))
                   {
                     verifica = 0;
                   }else{
                     coluna_verificada = coluna_verificada +1 ;
                   }
                 } 
               linha_verificada = linha_verificada +1;
             }
         }
     }else if((coluna_verificada >= 6)&&(coluna_verificada <=8)){

       if(linha_verificada <=2)
        {
          //entrou no bloco(3),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 0 ; 
           coluna_verificada = 6 ;
             while((linha_verificada <= 2)&&(verifica ==1))
             {
               coluna_verificada = 6 ;
                 while((coluna_verificada<=8)&&(verifica == 1))
                 {
                   if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0)) 
                   {
                     verifica = 0;
                   }else{
                     coluna_verificada = coluna_verificada +1 ;
                   }
                 }
               linha_verificada = linha_verificada +1;
              }
        }else if((linha_verificada >=3)&&(linha_verificada <=5)){
          //entrou no bloco(6),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 3 ; 
           coluna_verificada = 6 ;
             while((linha_verificada <= 5)&&(verifica ==1))
             {
               coluna_verificada = 6 ;
                 while((coluna_verificada<=8)&&(verifica == 1))
                 {
                   if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0))
                   {
                     verifica = 0;
                   }else{
                     coluna_verificada = coluna_verificada +1 ;
                   }
                 }
               linha_verificada = linha_verificada +1;
              }
        }else if((linha_verificada >=6)&&(linha_verificada <=8)){
          //entrou no bloco(9),agora tem de verificar se o valor se repete nesse bloco caso repita verifica = falso;
           linha_verificada = 6 ; 
           coluna_verificada = 6 ;
             while((linha_verificada <= 8)&&(verifica ==1))
             {
               coluna_verificada = 6 ;
                 while((coluna_verificada<=8)&&(verifica == 1))
                 {
                   if((matriz[linha_verificada][coluna_verificada] == valorusuario)&&(valorusuario!=0))
                   {
                     verifica = 0;
                   }else{
                     coluna_verificada = coluna_verificada +1 ;
                   }
                 }
               linha_verificada = linha_verificada +1;
             }
        }
    }
    return verifica;
}

void randomico(int matriz[N][N],int matrizauxiliar[N][N]) //funÃƒÂ§ao (1.5)insere 8  valores aleatorios de 1 a 9 na matriz. //A matriz auxiliar serve para deixar os valores randomicos imutavel
{ 
  int cont = 0;
  int linharand ;
  int colunarand ; 
  int valor_gerado; 
 while(cont < 8)
 {
   srand(time(NULL));  //iniciando o randomico,sem essa funÃƒÂ§ao ele dÃƒÂ¡ valores iguais a todo tempo
   linharand = rand()%9;
   colunarand = rand()%9;
        if(matriz[linharand][colunarand]==0) //esse if estÃƒÂ¡ sem o else (se der valor falso !=0 ele ira ficar executando em loop infinito)
        {
          valor_gerado =  1 +(rand()% 9);  //nesse formato ele gera valores de 1 a 9
          while((verificarlinha(valor_gerado,linharand,matriz) == 0)|| //basta que 1 desses seja =1 para que ele gere outto valor
                (verificarcoluna(valor_gerado,colunarand,matriz)==0)||
                (verificabloco(valor_gerado,linharand,colunarand,matriz)==0)){ //essas duas linhas chama as 3 funcoes de verificaÃƒÂ§ÃƒÂ¢o para que os randomicos entre na regra do jogo
                 srand(time(NULL));
                 valor_gerado =  1 +(rand()% 9);
          }
              matriz[linharand][colunarand] = valor_gerado;  
              matrizauxiliar[linharand][colunarand] = valor_gerado ;   
              cont++;
        }
 }
}
int verificaposicao (int linha,int coluna,int matriz[N][N]) //funÃƒÂ§ÃƒÂ£o (1.4) que verifica se local escolhido pelo usuario estÃƒÂ¡ vazio .
{                                                            
  int verifica = 1;
  
  if (matriz[linha][coluna] != 0)
  {
    verifica = 0;
  }
  return verifica;
}

int tamanhovalor (int valorusuario) // funÃƒÂ§ao (1.6) se estÃƒÂ¡ funÃƒÂ§ÃƒÂ£o der false na funÃƒÂ§ao main, ela deve exibir uma mensagem de valor incompativel
{
  int verifica = 1;

  if((valorusuario < 0) || (valorusuario > 9)) // o valorusuario vai poder ser 0 ,para o caso do usuario querer mudar o valor jÃƒÂ¡ iserido,ele poderÃƒÂ¡ retornar a 0 para recolocar outro valor valido depois
  {
    verifica = 0;
  }
  return verifica;
}


void main()
{ 
  int cont = 1 ; 
  Tipoelemento * inicio;
  criarinicio(&inicio);
  int matriz[N][N];
  int matrizauxiliar[N][N];
  int linha;
  int coluna;
  int valorusuario;
  int opcao = 0;
  int opcao1 = 0;
  int ganhador = 8; //comeÃ§a com 8 por conta dos primeiros 8 randomicos
  // 1 = true , 0 = false
  preenchercomzero(matriz,matrizauxiliar);
  randomico(matriz,matrizauxiliar);
  while((opcao != 2)&&(ganhador <81))
  {  
     system("cls");
     imprimirtabuleiro(matriz);
     printf("\n\n");
     printf("insira linha: \n");
     scanf("%d",&linha);
     linha = linha - 1;
     printf("insira coluna: \n");
     scanf("%d",&coluna);
     coluna = coluna - 1; 

     if((verificaposicao(linha,coluna,matriz)==1)&&(matrizauxiliar[linha][coluna] == 0))
     {
     	cont = 1;
      while(cont <=9)
      {
      	if((verificarlinha(cont,linha,matriz)==1) &&
           (verificarcoluna(cont,coluna,matriz)==1)&&
           (verificabloco(cont,linha,coluna,matriz)==1)&&
		   (matrizauxiliar[linha][coluna] == 0))
		       {
		         Tipoelemento *elemento = criarelemento(cont);
                 inicio = insere(inicio,elemento);
            }
            cont++;
      }
      imprime(inicio);
      printf("removendo: ");
      inicio = removelista(inicio);
      imprime(inicio);
     }else if(verificaposicao(linha,coluna,matriz)!=1)
     {
        printf("a unica opcao e 0, pois o local ja esta com um valor \n ");
     }

     printf("insira valor: \n");
     scanf("%d",&valorusuario);
      if((verificarlinha(valorusuario,linha,matriz)==1) &&
         (verificarcoluna(valorusuario,coluna,matriz)==1)&&
         (verificabloco(valorusuario,linha,coluna,matriz)==1)&&
         (verificaposicao(linha,coluna,matriz)==1)&&
         (tamanhovalor(valorusuario)==1)&&(valorusuario!=0)&&
         (matrizauxiliar[linha][coluna] == 0)) //se a posiÃƒÂ§ÃƒÂ¢o estiver um valor randomico ele ÃƒÂ© imutavel
       {
         matriz[linha][coluna] = valorusuario;
         ganhador++;
         system("cls");
         imprimirtabuleiro(matriz);
         printf("\n\n");
       }else if((verificarlinha(valorusuario,linha,matriz)==0) || (verificarcoluna(valorusuario,coluna,matriz)==0)||(verificabloco(valorusuario,linha,coluna,matriz)==0))
       {
         printf("valor em posicao que foge a regra do jogo! \n");
         printf("digite :  1 - tentar novamente\n");
         printf("          2 - sair\n");
         scanf("%d",&opcao);
       }else if(tamanhovalor(valorusuario)==0)
       {
         printf("insira somente valor entre 0 e 9 para\n");
         printf("Cuidado ,as colunas e linhas vao de 0 a 8 \n");
         system("cls");
       }else if((verificaposicao(linha,coluna,matriz)==0)&&(matrizauxiliar[linha][coluna] == 0)) //esse caso ÃƒÂ© se a posiÃƒÂ§ÃƒÂ£o jÃƒÂ¡ estiver ocupada !! se o valor digitado for != 0 ,a matrizauxiliar for ==0 entÃƒÂ¢o o susuario pode trocar o valor do local 
       {
         printf("Deseja realmente trocar o valor ja inserido nessa posicao por : '%d' \n",valorusuario);
         printf("1 - sim\n");
         printf("2 - nao \n");
         scanf("%d",&opcao1);
         system("cls");
         imprimirtabuleiro(matriz);
          if((opcao1 == 1) &&
            (verificarlinha(valorusuario,linha,matriz)==1) &&   //chama as funÃƒÂ§oes para verificar se o valor da troca ÃƒÂ© valido.
            (verificarcoluna(valorusuario,coluna,matriz)==1)&&
            (verificabloco(valorusuario,linha,coluna,matriz)==1))
          {
            matriz[linha][coluna] = valorusuario;
            ganhador++;
            system("cls");
            imprimirtabuleiro(matriz);
          }
       }else if(matrizauxiliar[linha][coluna] !=0) //nesse caso a posiÃƒÂ§ÃƒÂ¢o ÃƒÂ© imutavel
       {
          printf("O local escolhido esta com um valor randomico, esse nao pode ser modificado\n");
          printf("digite :  1 - tentar novamente\n");
          printf("          2 - sair\n");
          scanf("%d",&opcao);
       }
  }//while   
  if(ganhador == 81)
  {
    printf("parabens voce ganhou !!!!");
    
  }else{
    printf( "infelizmente nao foi dessa vez !!!" );
  }
}//main


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


typedef struct elementocircular {
  int valor;
  int posicao;
  int linha;   //COLOQUEI PARA PODER MUDAR TAMBEM NA MATRIZ AS JOGADAS
  int coluna;
  struct elementocircular *proximo;
  struct elementocircular *anterior;
}Tipolista;

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
  
  if(inicio==NULL)  //se o inicio for == null a lista ainda estÃ¡ vazia
  {
    inicio = elemento;  // se lista vazia insere o primeiro elemento, caso contrario o recursivo chama atÃ© chegar no ultimo
  }else{ // se a lista nÃ£o estÃ¡ vazia vai entrar 
    inicio->proximo = insere(inicio->proximo,elemento); // chama a funcao atÃ© o atual ser igual a null
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

int verificarcoluna(int valorusuario,int coluna ,int matriz[N][N])  //funcÃƒÆ’Ã‚Â£o (1.1) verifica se jÃƒÆ’Ã‚Â¡ existe aquele valor da coluna !!
{
  int cont= 0;
  int verifica = 1;    //o valor dado pelo usuario e valido !!
  
  while((cont < 9) && (verifica == 1))  /*a variavel coluna ÃƒÆ’Ã‚Â© fixa, para que ela pecorra a coluna escolhida do usuario*/
  {
    if((matriz[cont][coluna] == valorusuario)&& (valorusuario != 0)) //!= 0  para ele poder modificar o valor
    {
       verifica = 0;      //no caso do valor ser encontrado dentro da coluna ele deixa de ser valido !!
     } 
    cont++;        //incremento do cont para ele "andar na coluna"
  } 
  return verifica; //isso ÃƒÆ’Ã‚Â© oque irÃƒÆ’Ã‚Â¡ retorna para a funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o main ,no caso serÃƒÆ’Ã‚Â¡ um boolean (true or false)
}

int verificarlinha(int valorusuario,int linha ,int matriz[N][N])  //funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â¢o (1.2) faz a mesma coisa da funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o anterio mas para a linha
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

int verificabloco(int valorusuario,int linha,int coluna,int matriz[N][N]) //funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o (1.3) verifica se jÃƒÆ’Ã‚Â¡ existe valor nos blocos 
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
   coluna_verificada = 3;
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

void randomico(int matriz[N][N],int matrizauxiliar[N][N]) //funÃƒÆ’Ã‚Â§ao (1.5)insere 8  valores aleatorios de 1 a 9 na matriz. //A matriz auxiliar serve para deixar os valores randomicos imutavel
{ 
  int cont = 0;
  int linharand ;
  int colunarand ; 
  int valor_gerado; 
  while(cont < 8)
  {
   srand(time(NULL));  //iniciando o randomico,sem essa funÃƒÆ’Ã‚Â§ao ele dÃƒÆ’Ã‚Â¡ valores iguais a todo tempo
   linharand = rand()%9;
   colunarand = rand()%9;
        if(matriz[linharand][colunarand]==0) //esse if estÃƒÆ’Ã‚Â¡ sem o else (se der valor falso !=0 ele ira ficar executando em loop infinito)
        {
          valor_gerado =  1 +(rand()% 9);  //nesse formato ele gera valores de 1 a 9
          while((verificarlinha(valor_gerado,linharand,matriz) == 0)|| //basta que 1 desses seja =1 para que ele gere outto valor
            (verificarcoluna(valor_gerado,colunarand,matriz)==0)||
                (verificabloco(valor_gerado,linharand,colunarand,matriz)==0)){ //essas duas linhas chama as 3 funcoes de verificaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â¢o para que os randomicos entre na regra do jogo
           srand(time(NULL));
         valor_gerado =  1 +(rand()% 9);
       }
       matriz[linharand][colunarand] = valor_gerado;  
       matrizauxiliar[linharand][colunarand] = valor_gerado ;   
       cont++;
     }
   }
 }
int verificaposicao (int linha,int coluna,int matriz[N][N]) //funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o (1.4) que verifica se local escolhido pelo usuario estÃƒÆ’Ã‚Â¡ vazio .
{                                                            
  int verifica = 1;
  
  if (matriz[linha][coluna] != 0)
  {
    verifica = 0;
  }
  return verifica;
}

int tamanhovalor (int valorusuario) // funÃƒÆ’Ã‚Â§ao (1.6) se estÃƒÆ’Ã‚Â¡ funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o der false na funÃƒÆ’Ã‚Â§ao main, ela deve exibir uma mensagem de valor incompativel
{
  int verifica = 1;

  if((valorusuario < 0) || (valorusuario > 9)) // o valorusuario vai poder ser 0 ,para o caso do usuario querer mudar o valor jÃƒÆ’Ã‚Â¡ iserido,ele poderÃƒÆ’Ã‚Â¡ retornar a 0 para recolocar outro valor valido depois
  {
    verifica = 0;
  }
  return verifica;
}


Tipolista *criarelementocircular(int valor,int posicao,int linha, int coluna)
{
 Tipolista *elementocircular = malloc(sizeof(Tipolista));
 elementocircular->valor = valor ; 
 elementocircular->posicao = posicao;
 elementocircular->linha = linha;
 elementocircular->coluna = coluna;
 elementocircular->proximo = NULL ;
 elementocircular->anterior = NULL ; 
}

void criariniciocircular(Tipolista **inicio, Tipolista **fim)
{
  *inicio = NULL ;
  *fim = NULL;
}

Tipolista *inserecircular(Tipolista **inicio, Tipolista *fim , Tipolista elementocircular)
{
  Tipolista *aux = inicio; //querro que auxiliar sempre aponte para o primeiro elemento da lista
  if(inicio == NULL) //lista vazia
  {
    inicio = elementocircular;
    elementocircular->proximo = inicio;
    elementocircular->anterior = inicio;
    fim->proximo = elementocircular;
  } else if((inicio == fim)&&(inicio!=NULL)) //unico elemento
  {
   inicio->proximo = elementocircular;
   inicio->anterior = elementocircular;
   elementocircular->anterior = inicio;
   elementocircular->proximo = inicio;
   fim->proximo = elementocircular;
   
    }else if(inicio->proximo < aux) //chegou ao ultimo elemento
    {
      inicio->proximo = elementocircular;
      elementocircular->anterior = inicio ; 
      elementocircular->proximo = aux;
      aux->anterior = elementocircular;
      fim->proximo = elementocircular;
      
    }else{
     inicio->proximo = insere(inicio->proximo,fim->proximo,elementocircular);
   }
   return inicio;
 }

 Tipolista *imprimecircular(Tipolista *inicio)
 {
   Tipolista *auxiliar = inicio ; 
   if(auxiliar)
   {
    do{
      printf("%d  |%dº|", auxiliar->valor, auxiliar->posicao);
      system("pause");
      auxiliar = auxiliar->proximo; 
    }while(auxiliar != inicio);
  }  
}

Tipolista *removelistacircular (Tipolista *elementocircular) //remove lista completa
{ 
  Tipolista *temp = elementocircular;
  if(elementocircular == NULL)
  {
    return elementocircular;
  }
  elementocircular = elementocircular->proximo;
  printf("%d ",temp->valor);
  free(temp);
  removelistacircular(elementocircular);
}

Tipolista *removerultimoelemento(Tipolista *inicio , Tipolista *elementocircular, int matriz[N][N]) //funÃ§Ã£o para excluir a ultima jogada, quando o usuario pedir
{
  Tipolista *atual = inicio;
  if(atual->proximo < atual)
  {
      atual->anterior->proximo = atual->proximo;  // anterior = inicio
      atual->proximo->anterior = atual->anterior;  // inicio = anterior
      free(atual); //limpa o atual
      matriz[atual->linha][atual->coluna] = 0;
    }else{
      atual->proximo = removerultimoelemento(atual->proximo, elementocircular);
    }
  }
  Tipolista *busca(Tipolista *inicio,int jogada)
  {
    if((inicio == NULL) || ((inicio->proximo < inicio)&&(inicio->posicao != jogada))){
      printf("elemento nÃ£o encontrado");
    inicio = NULL ; // vai retornar falso
  }else if(inicio->posicao == jogada){
    printf("elemento encontrado");
  }else{
    inicio->proximo = busca(inicio->proximo,posicao);
  }
  return inicio;
}                                                                                      //ESSA MATRIZ Ã‰ A MATRIZ DO JOGO DO JOGO 
Tipolista *trocarvalor(Tipolista *inicio,int novovalor,int jogada, int matriz[N][N]) // nessa funcao e preciso trocar o valor na lista e na mastriz tambem
{
     Tipolista *aux  = busca(inicio,jogada); //isso pode acontecer ??? // assim eu quero o resultado da busca em aux
     
     if(aux != NULL) // QUER DIZER QUE O ELEMENTO FOI ENCONTRADO
     {   
      if((verificalinha(novovalor,aux->linha,matriz)==1)&&(verificacoluna(novovalor,aux->coluna,matriz)==1)&&
        (verificabloco(novovalor,aux->linha,aux->coluna,matriz)==1))
      {
                aux->valor = novovalor; //auxiliar serÃ¡ o local retornado da funÃ§Ã£o busca, a jogada==posicao continua a mesma , sÃ³ muda o valor da jogada.
                matriz[aux->linha][aux->coluna] = novovalor;  // assim tambÃ©m irÃ¡ trocar o valor na matriz do jogo
              }
            } 
          }

          void main()
          { 
            int cont = 1 ; 
            Tipoelemento * inicio;
            criarinicio(&inicio);
            Tipolista *iniciocircular;
            criariniciocircular(&iniciocircular);
            int matriz[N][N];
            int matrizauxiliar[N][N];
            int matrizjogada[N][N];
            int linha, coluna =0;
            int contadorjogadas = 0;
            int valorusuario;
            int opcao = 0;
            int opcao1 = 0;
            int opjogo = 0;
            int troca= 0;
            int novovalor=0;
            int auxiliar = 0;
  int ganhador = 8; //comeÃƒÂ§a com 8 por conta dos primeiros 8 randomicos
  // 1 = true , 0 = false
  preenchercomzero(matriz,matrizauxiliar);
  preenchercomzero(matriz,matrizjogada);
  randomico(matriz,matrizauxiliar);
  while((opcao != 2)&&(ganhador <81))
  {  
   printf("1 - nova jogada?\n");
   printf("2 - trocar jogada ?");
   printf("3 - apagar ultima jogada?" );
   scanf("%d",&opjogo);
   
   if(opjogo == 1)
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
         (matrizauxiliar[linha][coluna] == 0)) //se a posiÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â¢o estiver um valor randomico ele ÃƒÆ’Ã‚Â© imutavel
  {
   matriz[linha][coluna] = valorusuario;
   matrizjogada[linha][coluna]= contadorjogadas;
   Tipolista *elementocircular = criarelementocircular(valorusuario,contadorjogadas,linha,coluna);
   iniciocircular = inserecircular(inicio,fim,elementocircular);
   ganhador++;
   contadorjogadas = contadorjogadas + 1;
   system("cls");
   imprimirtabuleiro(matriz);
   printf("\n\n");
   imprimecircular(iniciocircular);
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
       }else if(matrizauxiliar[linha][coluna] !=0) //nesse caso a posiÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â¢o ÃƒÆ’Ã‚Â© imutavel
       {
        printf("O local escolhido esta com um valor randomico, esse nao pode ser modificado\n");
        printf("digite :  1 - tentar novamente\n");
        printf("          2 - sair\n");
        scanf("%d",&opcao);
      }else if(opjogo ==2)
      {
        printf("**TABULEIRO DAS POSIÃ‡Ã•ES JOGADAS**\n ");
        imprimirtabuleiro(matrizjogada);
        printf("**TABULEIRO SUDOKU**\n");
        imprimirtabuleiro(matriz);
        printf("qual jogada a ser trocada ?");
        scanf("%d",&troca);
        printf("novo valor");
        scanf("%d",&novovalor);
          auxiliar = busca(iniciocircular,troca); //troca Ã© o numero da posiÃ§ao (15Âª)
          if(auxiliar != NULL)
          {
            trocarvalor(iniciocircular,novovalor,troca,matriz);
            imprimirtabuleiro(matriz);
            imprimecircular(iniciocircular);
          }
        }else if(opjogo == 3)
        {
          removerultimoelemento(iniciocircular,elementocircular,matriz); 
          imprimirtabuleiro(matriz);
          imprimecircular(iniciocircular);
        }
      }
  }//while 
  inicio = removelistacircular(iniciocircular);

  if(ganhador == 81)
  {
    printf("parabens voce ganhou !!!!");
    
  }else{
    printf( "infelizmente nao foi dessa vez !!!" );
  }
}//main

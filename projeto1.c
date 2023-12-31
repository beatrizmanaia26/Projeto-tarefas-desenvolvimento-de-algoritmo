
#include <stdio.h>
#include <string.h>
#include "projeto1.h"

//PRIORIDADE DIFERENTE DE 0 E 9 NAO RODA

//*Lt-> alterar valor dentro e fora da funcao
int cria_tarefa(lista_tarefas *Lt){
  // usa ponteiro pra funcao -> usa seta 
  int qnt = 0; //só pra funcao
  if (Lt->quantidade < 100){
    printf("Digite a categoria da tarefa: ");
    scanf("%s", Lt->Tarefas[Lt->quantidade].categoria);
    printf("Digite a descricao da tarefa: ");
    scanf("%s", Lt->Tarefas[Lt->quantidade].descricao);
    printf("Digite a prioridade da tarefa (0-9): ");
       //prioridade de 0 a 9 pois para perguntar novamente a prioridade se o usuario nao digitar um numero precisa usar a tabela ascii e ela vai de 0 a 9 
    scanf("%d",&Lt->Tarefas[Lt->quantidade].prioridade); 
    printf("Digite o estado da sua tarefa: \n");
    printf("0-Não iniciada, 1-Realizando, 2- Completa: ");
    scanf("%d", &Lt->Tarefas[Lt->quantidade].estado);
    while(Lt->Tarefas[Lt->quantidade].estado < 0 || Lt->Tarefas[Lt->quantidade].estado > 2){
      printf("Digite um estado valido: ");
      scanf("%d", &Lt->Tarefas[Lt->quantidade].estado);
    }
    qnt += 1; 
    Lt -> quantidade = Lt -> quantidade + 1;  //funciona dentro e fora da funcao  
    //FAZER CODIGO PRA C ESTADO TIVER ERRADO NAO CONTABILIZAR A TAREFA
    }
    if(qnt == 1){                           
      printf("Tarefa criada com sucesso!\n");       
      return 0;                           
    }                                      
    if(qnt != 1){                          
      printf("Erro ao criar tarefa\n");   
      return 1;                           
    }                 
}

int deleta_tarefa(lista_tarefas *Lt){
    int num = 0;
    printf("Digite o número da categoria da tarefa que deseja deletar: ");
    scanf("%d",&num);
    if (Lt->quantidade == 0 || Lt->quantidade < num){   
        printf("Falha ao deletar a tarefa :( \n ");
        return 1;
    }
    for (int search = num - 1; search < Lt->quantidade; search ++ ){
        strcpy(Lt->Tarefas[search].categoria, Lt->Tarefas[search +1].categoria);
        strcpy(Lt->Tarefas[search].descricao, Lt->Tarefas[search +1].descricao);   
        Lt->Tarefas[search].prioridade = Lt->Tarefas[search +1].prioridade;
        Lt->Tarefas[search].estado = Lt->Tarefas[search +1].estado; 
    }
    Lt->quantidade--;
    printf("Deletou com sucesso!\n");
    return 0;
}

int listar_tarefas(lista_tarefas Lt){ 
  //quando for a copia do struct usa o ponto 
  if (Lt.quantidade == 0){
      printf("Não tem tarefa para listar");
      return 1;
  }
    //printf("quantidade: %d \n", Lt.quantidade);
  for (int ToDo = 0; ToDo< Lt.quantidade; ToDo++ ){
    printf("\n");
    printf("\n%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", ToDo+1,Lt.Tarefas[ToDo].categoria, Lt.Tarefas[ToDo].descricao, Lt.Tarefas[ToDo].prioridade, Lt.Tarefas[ToDo].estado); //\t = tab do teclado (formatação)
    printf("O estado da sua tarefa é: ");
    if (Lt.Tarefas[ToDo].estado == 0){  
      
      printf(" nao iniciada");
    }
    if (Lt.Tarefas[ToDo].estado == 1){
      printf(" em andamento");
    }
    if (Lt.Tarefas[ToDo].estado == 2){   
      printf(" concluida");
    }
  }
    printf("\n");
    return 0;
 }

int alterar_tarefa(lista_tarefas *Lt){
  int alterar = 0;
  int tarefa;
  int estado;
  int prioridade;
  printf("Digite o número da tarefa que deseja alterar: ");
  scanf("%d",&alterar);
  
  if (Lt->quantidade == 0 || Lt->quantidade < alterar){   
    printf("Falha ao encontrar a tarefa :( \n ");
    return 1;
  }
    for (int buscar = alterar - 1; buscar < Lt->quantidade; buscar ++ ){

    printf("Digite o que da tarefa deseja alterar\n1)categoria, 2)descricao, 3)prioridade, 4)estado): ");
    printf("\n");
    scanf("%d", &tarefa);
    //MUDO E AS VEZES PEDE O Q DA TAREFA QR MUDAR AO INVES D MOSTRA O MENU
    if (tarefa == 1){
      printf("Digite a nova categoria: ");
      scanf("%s", Lt->Tarefas[buscar].categoria);
      printf("Nova categoria: %s\n", Lt->Tarefas[buscar].categoria);
      return 0;
    }
    else if (tarefa == 2){
      printf("Digite a nova descricao: ");
      scanf("%s", Lt->Tarefas[buscar].descricao);
      printf("Nova desrição: %s\n", Lt->Tarefas[buscar].descricao);
      return 0;
    }
    else if (tarefa == 3){
      printf("Digite a nova prioridade: ");
      scanf("%d", &prioridade);
      if (prioridade == 0 || prioridade == 1 || prioridade == 2 || prioridade == 3 || prioridade == 4 || prioridade == 5 || prioridade == 6 || prioridade == 7 || prioridade == 8 || prioridade == 9){
        Lt->Tarefas[buscar].prioridade = prioridade;
        printf("Nova prioridade: %d\n", Lt->Tarefas[buscar].prioridade);
        return 0;
      }
      else{
        printf("Prioridade invalida");
        return 1;
      }
    }
    else if (tarefa == 4){
      printf("Digite o novo estado: 0-Não iniciada, 1-Realizando, 2- Completa: ");
      scanf("%d", &estado);
      if (estado == 0 || estado == 1 || estado == 2){
        Lt->Tarefas[buscar].estado = estado;
        printf("Novo estado: %d\n", Lt->Tarefas[buscar].estado);
        return 0;
        }
      else{
        printf("Estado invalido\n");
        return 1;
          }
    } 
    else {
      printf("Essa opção nao existe\n");
      return 1;
      }
  } 
}

void filtrar_por_prioridade(lista_tarefas Lt){
  int filtrarPrior;
  printf("Digite a prioridade que deseja filtrar: ");
  scanf("%d",&filtrarPrior);
  int contador = 0;
   for (int buscarPrioridade = 0; buscarPrioridade < Lt.quantidade; buscarPrioridade++ ){
     if (Lt.Tarefas[buscarPrioridade].prioridade == filtrarPrior){
       contador = 1;
       printf("\n");
       printf("\n%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", buscarPrioridade+1,Lt.Tarefas[buscarPrioridade].categoria, Lt.Tarefas[buscarPrioridade].descricao, Lt.Tarefas[buscarPrioridade].prioridade, Lt.Tarefas[buscarPrioridade].estado);
     }
  } 
  if (contador == 0){
    printf("Falha ao encontrar a tarefa(s) com essa prioridade :( \n ");
  }
}

void filtrar_por_estado(lista_tarefas Lt){
  int filtrarEstado;
  int contador = 0;
  printf("Digite o estado que deseja filtrar: ");
  scanf("%d",&filtrarEstado);
  for (int buscarEstado = 0; buscarEstado < Lt.quantidade; buscarEstado ++ ){
    if (Lt.Tarefas[buscarEstado].estado == filtrarEstado){
      contador = 1;
      printf("\n");
      printf("%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", buscarEstado+1,Lt.Tarefas[buscarEstado].categoria, Lt.Tarefas[buscarEstado].descricao, Lt.Tarefas[buscarEstado].prioridade, Lt.Tarefas[buscarEstado].estado);
    }   
  }
  if (contador == 0){
    printf("Falha ao encontrar a tarefa(s) com essa estado :( \n ");
  }
}

void filtrar_por_categoria(lista_tarefas Lt){
  char filtrarCategoria[100];
  int contador = 0;
  printf("Digite a categoria que deseja filtrar: ");
  scanf("%s",filtrarCategoria);
  for (int ordem = 9; ordem >= 0 ; ordem--){
  for (int buscarCategoria = 0; buscarCategoria < Lt.quantidade; buscarCategoria ++ ){

    if (strcmp(Lt.Tarefas[buscarCategoria].categoria, filtrarCategoria) == 0){
      if(Lt.Tarefas[buscarCategoria].prioridade == ordem){
        contador = 1;
        printf("\n");
        printf("%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", buscarCategoria+1,Lt.Tarefas[buscarCategoria].categoria, Lt.Tarefas[buscarCategoria].descricao, Lt.Tarefas[buscarCategoria].prioridade, Lt.Tarefas[buscarCategoria].estado);  
      }     
   }
  }
 }
  if (contador == 0){
    printf("Falha ao encontrar a tarefa(s) com essa categoria :( \n ");
  }
}

void filtrar_por_prioridade_categoria(lista_tarefas Lt){
  int filtrarPrior;
  int contador = 0;
  printf("Digite a prioridade que deseja filtrar: ");
  scanf("%d",&filtrarPrior);
  
  char filtrarCategoria[100];
  printf("Digite a categoria que deseja filtrar: ");
  scanf("%s",filtrarCategoria);
  
  if (Lt.quantidade == 0){   
      printf("Falha ao encontrar a tarefa(s) com essa prioridade :( \n ");
    }
   for (int priorCateg = 0; priorCateg < Lt.quantidade; priorCateg++ ){
     if(strcmp(Lt.Tarefas[priorCateg].categoria, filtrarCategoria) == 0){
       if (Lt.Tarefas[priorCateg].prioridade == filtrarPrior){
        contador = 1;
        printf("\n");
        printf("\n%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", priorCateg+1,Lt.Tarefas[priorCateg].categoria, Lt.Tarefas[priorCateg].descricao, Lt.Tarefas[priorCateg].prioridade, Lt.Tarefas[priorCateg].estado);
       }
     }
  }
  if (contador == 0){
    printf("Falha ao encontrar a tarefa(s) com essa categoria e prioridade:( \n ");
  }
}

void exportar_tarefa_prioridade(lista_tarefas Lt){
  FILE *f = fopen("prioridade","w");
   int filtrarPrior;
  if (Lt.quantidade == 0){
      printf("Não tem tarefa para listar");
  }
  printf("Digite a prioridade que deseja filtrar: ");
  scanf("%d",&filtrarPrior);
  int contador = 0;
  for (int buscarPrioridade = 0; buscarPrioridade < Lt.quantidade; buscarPrioridade++ ){
    if (Lt.Tarefas[buscarPrioridade].prioridade == filtrarPrior){
      contador = 1;
      fprintf(f,"\n");
      fprintf(f,"\n%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", buscarPrioridade+1,Lt.Tarefas[buscarPrioridade].categoria, Lt.Tarefas[buscarPrioridade].descricao, Lt.Tarefas[buscarPrioridade].prioridade, Lt.Tarefas[buscarPrioridade].estado);
      }
   } 
   if (contador == 0){
     fprintf(f,"Falha ao encontrar a tarefa(s) com essa prioridade :( \n ");
   }
   fclose(f);
}

void exportar_tarefa_categoria(lista_tarefas Lt){
  FILE *f = fopen("categoria","w");
    if (Lt.quantidade == 0){
        fprintf(f,"Não tem tarefa para listar");
    }
      //printf("quantidade: %d \n", Lt.quantidade);
  char filtrarCategoria[100];
  int contador = 0;
  printf("Digite a categoria que deseja filtrar: ");
  scanf("%s",filtrarCategoria);
  for (int ordem = 9; ordem >= 0 ; ordem--){
  for (int buscarCategoria = 0; buscarCategoria < Lt.quantidade; buscarCategoria ++ ){

    if (strcmp(Lt.Tarefas[buscarCategoria].categoria, filtrarCategoria) == 0){
      if(Lt.Tarefas[buscarCategoria].prioridade == ordem){
        contador = 1;
        fprintf(f,"\n");
        fprintf(f,"%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", buscarCategoria+1,Lt.Tarefas[buscarCategoria].categoria, Lt.Tarefas[buscarCategoria].descricao, Lt.Tarefas[buscarCategoria].prioridade, Lt.Tarefas[buscarCategoria].estado);  
        }     
     }
    }
   }
    if (contador == 0){
      printf("Falha ao encontrar a tarefa(s) com essa categoria :( \n ");
  }
  fclose(f);
}

void exportar_tarefa_prioridade_categoria(lista_tarefas Lt){
  FILE *f = fopen("prioridadeCategoria","w");
    if (Lt.quantidade == 0){
        fprintf(f,"Não tem tarefa para listar");
    }
  int filtrarPrior;
  int contador = 0;
  printf("Digite a prioridade que deseja filtrar: ");
  scanf("%d",&filtrarPrior);

  char filtrarCategoria[100];
  printf("Digite a categoria que deseja filtrar: ");
  scanf("%s",filtrarCategoria);
      //printf("quantidade: %d \n", Lt.quantidade);
    for (int ToDo = 0; ToDo< Lt.quantidade; ToDo++ ){
      if(strcmp(Lt.Tarefas[ToDo].categoria, filtrarCategoria) == 0){
        if (Lt.Tarefas[ToDo].prioridade == filtrarPrior){
          contador = 1;
          fprintf(f,"\n");
          fprintf(f,"\n%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t estado: %d\t \n", ToDo+1,Lt.Tarefas[ToDo].categoria, Lt.Tarefas[ToDo].descricao, Lt.Tarefas[ToDo].prioridade, Lt.Tarefas[ToDo].estado);
           }
         }
      }
    if (contador == 0){
      printf("Falha ao encontrar a tarefa(s) com essa categoria e prioridade:( \n ");
      }
  fclose(f);
}

void print_menu(){
    printf("\n1.Criar tarefa \n2.Deletar tarefa \n3.Listar tarefa\n4.Alterar Tarefa\n5.Filtrar tarefa por prioridade\n6.Filtrar tarefa por estado\n7.Filtrar tarefa por categoria\n8.Filtrar tarefa por prioridade e categoria\n9.Exportar tarefas por prioridade\n10.Exportar tarefas por categoria\n11.Exportar tarefas por prioridade e categoria\nDigite 0 para sair </3\n");   
  printf("\n");
}

int salva_tarefa(lista_tarefas Lt, char nome[]){
    FILE *f = fopen(nome,"wb");
    if (f == NULL){ //vê se valor do ponteiro ta apontando pra NULL
        printf("Falha ao abrir o arquivo");
        return 1;
    } 
    fwrite(&Lt, sizeof(lista_tarefas), 1, f);
    fclose(f);
    return 0;
} 

int ler_arquivo(lista_tarefas *Lt, char nome[]){  
    FILE *f = fopen(nome, "rb"); 
    if (f == NULL){ 
        printf("Falha ao abrir o arquivo");
        return 1;
    } //  var, tamanho, quantidade, arquivo
    fread(Lt, sizeof(lista_tarefas), 1, f); //1 pq é 1 struct (se fosse o tarefa seria 100 em quantidade)
    fclose(f);
    return 0;
} 


//printar em ordem de prioridade: fazer dentro de if (if priporidade = 1: print prioridade)

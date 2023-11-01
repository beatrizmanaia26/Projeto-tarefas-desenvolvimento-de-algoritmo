#include <stdio.h>
#include "projeto1.h"
#include <string.h>

int main(){
  char arquivo[]= "tarefa"; 
  char arquivo_prioridade[] = "prioridade";
  char arquivo_categoria[] = "categoria";
  char arquivo_prioridade_categoria[] = "prioridadeCategoria";
  int codigo; //armazena codigo de retorno das funcoes
  lista_tarefas Lt;
  codigo = ler_arquivo(&Lt, arquivo); //chama a funcao de ler arquivo
  if( codigo == 1){
      Lt.quantidade = 0; //limpa memoria 
  }
  int opcao;
  do{
      print_menu();
      printf("Digite o numero da opcao desejada: ");
      scanf("%d", &opcao);
    if (opcao == 0){
    }else if(opcao == 1){
      cria_tarefa(&Lt);
    }else if(opcao == 2){
      deleta_tarefa(&Lt);
    }else if(opcao == 3){
      listar_tarefas(Lt);
    }else if (opcao == 4){
      alterar_tarefa(&Lt);
    }else if(opcao == 5){
      filtrar_por_prioridade(Lt);
    }else if(opcao == 6){
      filtrar_por_estado(Lt);
    }else if(opcao == 7){
      filtrar_por_categoria(Lt);
    }else if (opcao == 8){
      filtrar_por_prioridade_categoria(Lt);
    }else if(opcao == 9){
      exportar_tarefa_prioridade(Lt);
    }else if(opcao == 10){
      exportar_tarefa_categoria(Lt);
    }else if(opcao == 11){
      exportar_tarefa_prioridade_categoria(Lt);
    }else{
      printf("Opcao escolhida nao existe\n");
    }
    codigo = salva_tarefa(Lt, arquivo);    //chama a funcao ->salva tarefa
    }while(opcao != 0); //loop

    if(codigo != 0){
        printf("Erro ao salvar as tarefas");
    }
}
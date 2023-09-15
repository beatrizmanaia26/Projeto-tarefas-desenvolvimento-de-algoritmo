//Beatriz Manaia Lourenço Berto      RA: 24.123.013-5
//Luana Bortko Rodrigues             RA: 24.123.006-9

#include <stdio.h>
#include <string.h>
#include "projeto1.h"


//*Lt-> alterar valor só na funcao
int cria_tarefa(lista_tarefas *Lt){
    printf("Digite a categoria da tarefa: ");
    scanf("%s", Lt->Tarefas[Lt->quantidade].categoria);
    printf("Digite a descricao da tarefa: ");
    scanf("%s", Lt->Tarefas[Lt->quantidade].descricao);
    printf("Digite a prioridade da tarefa (0-10): ");
    scanf("%d", &Lt->Tarefas[Lt->quantidade].prioridade);

    return 0;
//return 0 funciono de return 1 deu errado
}

int deleta_tarefa(lista_tarefas *Lt){
    return 0;
//return 0 funciono de return 1 deu errado
}

int listar_tarefas(lista_tarefas Lt){
    return 0;
    //return 0 funciono de return 1 deu errado
}
void print_menu(){
    printf("1.Criar tarefa \n2.Deletar tarefa \n3.Listar tarefa\nDigite 0 para sair </3");
}
int ler_arquivo(lista_tarefas *Lt, char nome[]){
    
    return 1;
//return 0 funciono de return 1 deu errado
} //fread
int salva_tarefa(lista_tarefas Lt, char nome[]){

      return 0;
    
    //return 0 funciono de return 1 deu errado
} //fwrite

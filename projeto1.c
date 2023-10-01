//Beatriz Manaia Lourenço Berto      RA: 24.123.013-5
//Luana Bortko Rodrigues             RA: 24.123.006-9

#include <stdio.h>
#include <string.h>
#include "projeto1.h"

//*Lt-> alterar valor dentro e fora da funcao
int cria_tarefa(lista_tarefas *Lt){ // usa ponteiro pra funcao -> usa seta 
       int qnt = 0; //só pra funcao
    if (Lt->quantidade < 100){
    printf("Digite a categoria da tarefa: ");
    scanf("%s", Lt->Tarefas[Lt->quantidade].categoria);
    printf("Digite a descricao da tarefa: ");
    scanf("%s", Lt->Tarefas[Lt->quantidade].descricao);
    printf("Digite a prioridade da tarefa (0-9): ");
     //prioridade de 0 a 9 pois para perguntar novamente a prioridade se o usuario nao digitar um numero precisa usar a tabela ascii e ela vai de 0 a 9 
    scanf("%d",&Lt->Tarefas[Lt->quantidade].prioridade); 
    qnt += 1; 
    Lt -> quantidade = Lt -> quantidade + 1;  //funciona dentro e fora da funcao  
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
    printf("Digite a categoria da tarefa que deseja deletar: ");
    scanf("%d",&num);
    if (Lt->quantidade == 0 || Lt->quantidade <= num){   
        printf("Falha ao deletar a tarefa :( \n ");
        return 1;
    }
    for (int search = num - 1; search < Lt->quantidade; search ++ ){
        strcpy(Lt->Tarefas[search].categoria, Lt->Tarefas[search +1].categoria);
        strcpy(Lt->Tarefas[search].descricao, Lt->Tarefas[search +1].descricao);   
        Lt->Tarefas[search].prioridade = Lt->Tarefas[search +1].prioridade;
        Lt->quantidade--;
    }
    printf("Deletou com sucesso!\n");
    return 0;
}

//printar em ordem de prioridade: fazer dentro de if (if priporidade = 1: print prioridade)

int listar_tarefas(lista_tarefas Lt){ //quando for a copia do struct usa o ponto 
    printf("\n");
    //printf("quantidade: %d \n", Lt.quantidade);
    for (int ToDo = 0; ToDo< Lt.quantidade; ToDo++ ){
        printf("%d.categoria: %s\tdescricao: %s\tprioridade: %2d\t \n", ToDo+1,Lt.Tarefas[ToDo].categoria, Lt.Tarefas[ToDo].descricao, Lt.Tarefas[ToDo].prioridade); //\t = tab do teclado (formatação)
    }
    printf("\n");

    return 0;
    if (Lt.quantidade == 0){
        printf("Não tem tarefa para listar");
        return 1;
    }
}

void print_menu(){
    printf("1.Criar tarefa \n2.Deletar tarefa \n3.Listar tarefa\nDigite 0 para sair </3 \n");   
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


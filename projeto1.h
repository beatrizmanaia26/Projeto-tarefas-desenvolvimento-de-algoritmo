
typedef struct{
    int prioridade;
    char categoria[100];//struct em categoria pra ter mais opcoes
    char descricao[300];
}tarefa;

typedef struct{ //fwrite desse struct 
    tarefa Tarefas[100];
    int quantidade; //fazer for (ultima tarefa que adicionei (comeca com 0 e vai add)
}lista_tarefas;

//int pq retorna numero (1 ou 0)
int cria_tarefa(lista_tarefas *Lt);
int deleta_tarefa(lista_tarefas *Lt);
int listar_tarefas(lista_tarefas Lt);
void print_menu(); 
int ler_arquivo(lista_tarefas *Lt, char nome[]);
int salva_tarefa(lista_tarefas Lt, char nome[]);
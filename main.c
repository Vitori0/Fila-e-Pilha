#include <stdio.h>
#include <stdlib.h>

typedef struct NoP {
    int valor;
    struct NoP *anterior;
} NoP;

typedef struct Pilha {
    NoP *topo;
    int tamanho;
} Pilha;

Pilha *criaPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
        p->tamanho = 0;
        return p;
    }
    printf ("Nao ha memoria disponivel para executar o programa :(\n\n");
    exit(1);
}

int PilhaCheia(NoP *n) {
    if (n == NULL) {
        return 1;
    }
    return 0;
}

int PilhaVazia(Pilha *p) {
    if (p->topo == NULL) {
        return 1;
    }
    return 0;
}

int Empilhar(Pilha *p, int v) {
    NoP *newNo = (NoP*)malloc(sizeof(NoP));
    if (PilhaCheia(newNo) == 1) {
        printf ("\nNao ha memoria disponivel para novos elementos :(\n\n");
        return 0;
    }
    newNo->valor = v;
    newNo->anterior = p->topo;
    p->topo = newNo;
    p->tamanho++;
    printf ("\nElemento %d foi adicionado a pilha :)\n\n", v);
    return 1;
}

int Desempilhar(Pilha *p) {
    if (PilhaVazia(p) == 1) {
        printf ("\nA pilha ja esta vazia!\n\n");
        return 0;
    }
    int v = p->topo->valor;
    NoP *newNo = p->topo;
    p->topo = p->topo->anterior;
    p->tamanho--;
    free(newNo);
    printf ("\nElemento %d foi retirado da pilha :)\n\n", v);
    return v;
}

void printarPilha(Pilha *p) {
    NoP *aux = p->topo;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->anterior;
    }
    printf("\n");
}

void LiberaPilha(Pilha *p) {
    NoP *aux;
    while (p->topo != NULL) {
        aux = p->topo;
        p->topo = p->topo->anterior;
        free(aux);
    }
    free(p);
}

typedef struct NoF {
    int valor;
    struct NoF *proximo;
} NoF;

typedef struct Fila {
    NoF *primeiro;
    int tamanho;
} Fila;

Fila *criaFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->primeiro = NULL;
        f->tamanho = 0;
        return f;
    }
    printf ("\nO programa nao pode ser executado por falta de memória :(\n\n");
    exit(1);
}

int FilaCheia(NoF *n) {
    if (n == NULL) {
        return 1;
    }
    return 0;
}

int FilaVazia(Fila *f) {
    if (f->primeiro == NULL) {
        return 1;
    }
    return 0;
}

int Enfileirar(Fila *f, int v) {
    NoF *newNo = (NoF*)malloc(sizeof(NoF));
    if (FilaCheia(newNo) == 1) {
        printf ("\nNao ha memoria disponivel para novos elementos :(\n\n");
        return 0;
    }
    newNo->valor = v;
    newNo->proximo = f->primeiro;
    f->primeiro = newNo;
    f->tamanho++;
    printf ("\nElelmento %d foi adicionado a fila :)\n\n", v);
    return 1;
}

int Desenfileirar(Fila *f) {
    if (FilaVazia(f) == 1) {
        printf ("\nA fila ja esta vazia\n\n");
        return 0;
    }
    int v = f->primeiro->valor;
    NoF *newNo = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    f->tamanho--;
    free(newNo);
    printf ("\nElemento %d foi retirado da fila :)\n\n", v);
    return 1;
}

void printarFila(Fila *f) {
    NoF *aux = f->primeiro;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void LiberaFila(Fila *f) {
    NoF *aux;
    while(f->primeiro != NULL) {
        aux = f->primeiro;
        f->primeiro = f->primeiro->proximo;
        free(aux);
    }
    free(f);
}

void limpartela() {
    getchar();
    system("cls");
}

int main() {
    int menuMain, menuPF, menuExit, elementos;
    Pilha *p = criaPilha();
    Fila *f = criaFila();

    while(1) {
        printf ("Com qual tipo de TAD deseja trabalhar?\n\n");

        printf ("[1] Pilha\n");
        printf ("[2] Fila\n");
        printf ("[3] Encerrar programa\n\n");

        scanf ("%d", &menuMain);

        limpartela();

        switch(menuMain) {
            case 1:
                printf ("Selecione a operacao desejada:\n\n");

                printf ("[1] Empilhar\n");
                printf ("[2] Desempilhar\n");
                printf ("[3] Destruir pilha\n");
                printf ("[4] Voltar ao menu anterior\n\n");

                scanf ("%d", &menuPF);

                limpartela();

                switch(menuPF) {
                    case 1:
                        printf ("Digite o elemento que deseja empilhar\n");
                        scanf ("%d", &elementos);
                        Empilhar(p, elementos);
                        break;
                    case 2:
                        Desempilhar(p);
                        break;
                    case 3:
                        printf ("Voce destruirah permanentemente esta pilha :(\nTem certeza que deseja prosseguir com a operacao?\n\n");

                        printf ("[1] Retornar ao menu principal\n");
                        printf ("[2] Excluir pilha permanentemente\n\n");

                        scanf ("%d", &menuExit);

                        switch(menuExit) {
                            case 1:
                                break;
                            case 2:
                                LiberaPilha(p);
                                break;
                        }
                        break;
                        break;
                    case 4:
                        break;
                }
                break;

            case 2:
                printf ("Selecione a operacao desejada:\n\n");

                printf ("[1] Emfileirar\n");
                printf ("[2] Desenfileirar\n");
                printf ("[3] Destruir fila\n");
                printf ("[4] Voltar ao menu anterior\n\n");

                scanf ("%d", &menuPF);

                limpartela();

                switch(menuPF) {
                    case 1:
                        printf ("Digite o elemento que deseja enfileirar!\n");
                        scanf ("%d", &elementos);
                        Enfileirar(f, elementos);
                        break;
                    case 2:
                        Desenfileirar(f);
                        break;
                    case 3:
                        printf ("Voce destruirah permanentemente esta fila :(\nTem certeza que deseja prosseguir com a operacao?\n\n");

                        printf ("[1] Retornar ao menu principal\n");
                        printf ("[2] Excluir fila permanentemente\n\n");

                        scanf ("%d", &menuExit);

                        switch(menuExit) {
                            case 1:
                                break;
                            case 2:
                                LiberaFila(f);
                                break;
                        }
                        break;
                    case 4:
                        break;
                }
                break;
            case 3:
                printf ("Tem certeza que deseja encerrar a execucao?\n\n");
                printf ("[1] Voltar ao menu anterior\n");
                printf ("[2] Encerrar execucao\n\n");

                scanf ("%d", &menuExit);

                limpartela();

                switch(menuExit) {
                    case 1:
                        break;
                    case 2:
                        printf ("\nPrograma finalizado com sucesso!\n");
                        return 0;
                }
                break;
        }
        getchar();
        limpartela();
    }
}

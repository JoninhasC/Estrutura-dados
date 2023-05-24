//Arquivo matriz.h

struct elemento{
    int valor;
    struct elemento *cima;
    struct elemento *baixo;
    struct elemento *esquerda;
    struct elemento *direita;
};

struct matriz{
    int x;
    int y;
    struct elemento *inicio;
};
typedef struct elemento Elemento;
typedef struct matriz* Matriz;

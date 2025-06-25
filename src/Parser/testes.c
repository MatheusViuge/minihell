#include "../../include/minishell.h"

// opção de debug: imprime a árvore
void print_ast(t_node *n, int depth)
{
    if (!n) return;
    for (int i = 0; i < depth; i++) putchar(' ');
    printf("- %s:", n->type == PIPE ? "PIPE" : "CMD");
    if (n->cmd)
        for (char **c = n->cmd; *c; c++)
            printf(" %s", *c);
    putchar('\n');
    print_ast(n->left,  depth + 2);
    print_ast(n->right, depth + 2);
}


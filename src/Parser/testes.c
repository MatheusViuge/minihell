#include "../../include/minishell.h"

// opção de debug: imprime a árvore
void print_ast(t_node *n, int depth)
{
    int      i;
    t_redir *r;
	const char *type_str;

    if (!n)
        return;

    /* Indentação e impressão do nó */
    for (i = 0; i < depth; i++)
        {printf("  ");}
	if (n->type == PIPE)
		type_str = "PIPE";
	else if (n->type == BUILTIN)
		type_str = "BUILTIN";
	else
		type_str = "COMMAND";
	printf("- %s", type_str);
    if (n->cmd)
    {
        printf(":");
        for (int j = 0; n->cmd[j]; j++)
            printf(" %s", n->cmd[j]);
    }
    printf("\n");

    /* Se houver redirecionamentos, imprima a lista */
    if (n->redirs)
    {
        for (i = 0; i < depth; i++)
            printf("  ");
        printf("  Redirects:");
        r = n->redirs;
        while (r)
        {
            printf(" %s %s",
                r->type == REDIR_IN   ? "<"  :
                r->type == REDIR_OUT  ? ">"  :
                r->type == APPEND     ? ">>" : "<<",
                r->name);
            r = r->next;
        }
        printf("\n");
    }

    /* Recursão nos filhos da AST */
    print_ast(n->left,  depth + 1);
    print_ast(n->right, depth + 1);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_error_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:45:04 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/20 16:48:32 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_ast(t_node *ast)
{
	if (!ast)
		return ;
	free_ast(ast->left);
	free_ast(ast->right);
	if (ast->cmd)
	{
		while (ast->cmd && *ast->cmd)
		{
			free(*ast->cmd);
			ast->cmd++;
		}
		free(ast->cmd);
	}
	free(ast);
}

bool	ast_error_handler(t_node **ast, t_data *data, char *error_msg)
{
	if (!ast || !*ast)
	{
		if (data->ast)
			free_ast(data->ast);
		data->ast = NULL;
		if (data->tokens)
			free_tokens(data->tokens);
		data->tokens = NULL;
		data->exit_code = 1;
		ft_putendl_fd(error_msg, STDERR_FILENO);
		return (true);
	}
	return (false);
}

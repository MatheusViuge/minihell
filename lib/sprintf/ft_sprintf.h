/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:58:43 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/03 15:56:59 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRINTF_H
# define FT_SPRINTF_H

# include <stdarg.h>
# include "../libft.h"

char	*ft_sprintf(const char *str, ...);
char	*malloc_char(va_list *args);
char	*malloc_str(va_list *args);
char	*malloc_pointer(va_list *args);
char	*malloc_nbr(va_list *args);
char	*malloc_unsigned(va_list *args);
char	*malloc_hex(va_list *args, char c);
char	*malloc_uns_long_hex(unsigned long p, const char *base);
char	**malloc_array_args(const char *str);
char	*malloc_new_str(const char *str, char **array_args);
void	free_array_args(char ***array_args);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_extern_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 02:14:04 by mmensing          #+#    #+#             */
/*   Updated: 2022/06/12 17:51:35 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	show_new_line(char *string)
{
	int		len;
	int		i;
	char	*ptr;

	if (!string)
		return ;
	len = strlen(string);
	i = 0;
	ptr = strdup(string);
	if (!strchr(ptr, '\n'))
		printf(MAG "\n\n-- no newline character --\n\n" RESET);
	printf(YEL"\nRESULT: "RESET);
	while (i < len)
	{
		if (ptr[i] == '\n')
			printf(GRN"'\\n'"RESET);
		else
			printf("%c", ptr[i]);
		i++;
	}
	printf("\n\n");
}

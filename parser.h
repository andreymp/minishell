/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:31:46 by jobject           #+#    #+#             */
/*   Updated: 2021/11/29 21:32:15 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_check
{
	int	gap;
	int	gap2;
	// continue
}				t_check;

char	*multi_join(char	*str, int i, int j);

#endif
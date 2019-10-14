/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:30:14 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("error: one of the map file's character is wrong");
	else if (i == 2)
		ft_putstr("error: a malloc failed");
	else if (i == 3)
		ft_putstr("error: spawn number is wrong. You must have ONE spawn");
	else if (i == 4)
		ft_putstr("error: empty file");
	else if (i == 5)
		ft_putstr("error: file not found");
	else if (i == 6)
		ft_putstr("error: spawn is in the wall");
	else
		ft_putstr("error");
	exit(0);
}

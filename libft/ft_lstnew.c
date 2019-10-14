/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:25:33 by mamisdra          #+#    #+#             */
/*   Updated: 2018/11/19 15:36:12 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*cpy;

	if (!(cpy = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		cpy->content = NULL;
		cpy->content_size = 0;
	}
	else
	{
		cpy->content = ft_memalloc(content_size);
		cpy->content = ft_memcpy(cpy->content, content, content_size);
		cpy->content_size = content_size;
	}
	cpy->next = NULL;
	return (cpy);
}

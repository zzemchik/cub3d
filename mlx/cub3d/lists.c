/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:25:57 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/14 19:34:02 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *a;
	if (*lst == NULL)
	{	
		*lst = new;
	}
	else
	{
		a = ft_lstlast(*lst);
		(a)->next = new;
		a->next->next = 0;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != 0 && new != 0)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *lst_cpy1;
	t_list *lst_cpy2;

	if (lst != 0 && *lst != 0 && del != 0)
	{
		lst_cpy1 = *lst;
		while (lst_cpy1)
		{
			lst_cpy2 = lst_cpy1->next;
			del(lst_cpy1->line);
			free(lst_cpy1);
			lst_cpy1 = lst_cpy2;
		}
		*lst = NULL;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != 0 && del != 0)
	{
		del((lst)->line);
		free(lst);
		lst = NULL;
	}
}
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != 0 && f != 0)
	{
		while (lst)
		{
			f(lst->line);
			lst = lst->next;
		}
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_cpy;

	if (lst == 0)
		return (0);
	lst_cpy = lst;
	while (lst_cpy->next)
		lst_cpy = lst_cpy->next;
	return (lst_cpy);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*n_elem;

	if (!(n_elem = malloc(sizeof(t_list))))
		return (NULL);
	n_elem->line = content;
	n_elem->next = NULL;
	return (n_elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_elem;

	if (!f && !del)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		if (!(lst_elem = ft_lstnew(f(lst->line))))
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, lst_elem);
		lst = lst->next;
	}
	return (lst_new);
}
int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*lst_copy;

	if (lst == 0)
		return (0);
	lst_copy = lst;
	if (!lst)
		return (0);
	i = 0;
	while (lst_copy->next != 0)
	{
		lst_copy = lst_copy->next;
		i++;
	}
	return (++i);
}

#include "push_swap.h"

void    ps_stack_init(t_stack *list, char **nbrs, int n)
{
    t_stack *tmp;
    int     i;

    i = 1;
    tmp = list;
    while (n >= 2)
    {   //---------Another way---------------
		//tmp = ft_calloc(sizeof(t_stack));
		//tmp->data = ft_atoi(argv[i]);
		//ft_stackadd_back(&list, tmp);
        //-----------------------------------
		list->data = ft_atoi(nbrs[i]);
		if (n > 2)
		{
			list->next = malloc(sizeof(t_stack));
			list = list->next;
		}
		i++;
		n--;
    }
	list->next = NULL;
	list = tmp;
}
/*
int main(int c, char **v)
{
    t_stack *list;

    if (c > 1)
    {
        list = malloc(sizeof(t_stack));
        stack_init(list, v, c);

        while (list)
		{
			printf("%d\n", list->data);
			list = list->next;
		}
    }
}*/

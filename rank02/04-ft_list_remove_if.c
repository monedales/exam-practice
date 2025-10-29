/*
Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.
It will be declared as follows :
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
cmp takes two void* and returns 0 when both parameters are equal.
You have to use the ft_list.h file, which will contain:
$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
*/
#include <cstddef>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list  *tmp;

    if (!*begin_list || !begin_list)
        return ;
    while (*begin_list != NULL)
    {
        if ((* cmp)(data_ref, (*begin_list)->data) == 0x0)
        {
            tmp = *begin_list;
            *begin_list = (*begin_list)->next;
            free(tmp);
        }
        else
            begin_list = &(*begin_list)->next;
    }
}
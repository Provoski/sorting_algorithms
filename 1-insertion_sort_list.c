#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sort a double link list
 * @list: list to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	int len;
	int i, j;
	int step;
	int flag;
	listint_t *swap, *step_1, *step_2;
	listint_t *temp;
	listint_t *head, *tail;
	listint_t *next, *prev;

	len = i = 0;
	swap = temp = head = tail = next = step_1 = step_2 = prev = NULL;
	head = tail = *list;
	temp = *list;
	/**
	 * counting number of nodes in the list
	 * without counting the head node
	 */
	while (tail)
	{
		len++;
		tail = tail->next;
	}
	/* if nodes is less than 2 */
	if (len < 2)
	{
		print_list(head);
		exit(0);
	}
	/* loop for outer pass */
	for (i = 0; i < len; i++)
	{
		flag = 0;
		head = *list;
		/* loop for inner pass */
		if ((*list)->n > (*list)->next->n)
		{
			swap = *list;
			*list = (*list)->next;
			swap->next = (*list)->next;
			swap->prev = *list;
			(*list)->next = swap;
			(*list)->prev = NULL;
			print_list(*list);
		}
		j = 0;
		step_1 = (*list)->next;
		step_2  = (*list)->next->next;
		printf("%d\n", step_2->n);	
		while (j < len)
		{
			if ((*list)->next->n > (*list)->next->next->n)
			{
				swap = (*list)->next;
				(*list)->next = (*list)->next->next;
				(*list)->next->next = swap;
				(*list)->next->prev = swap->prev;
				swap->prev = (*list)->next; 
				swap->next = (*list)->next->next; 

			}
			j++;
		}
	}
}

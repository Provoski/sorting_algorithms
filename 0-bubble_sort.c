#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sort array of integer in ascending order
 * @array: array of integer to sort
 * @size: size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int flag;
	int temp;

	temp = 0;
	for (i = 0; i < (size - 1); i++)
	{
		flag = 0;
		for (j = 0; j < (size -	1) - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}

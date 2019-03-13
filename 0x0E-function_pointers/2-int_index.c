/**
 * int_index - find a value within an array using comparison function
 * @array: pointer to array
 * @size: size of array
 * @cmp: function to compare number with, returns 0 if match is found
 *
 * Return: index of number found or -1 if none is found
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size < 1)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}

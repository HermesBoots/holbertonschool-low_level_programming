/**
 * reverse_array - reverses the integers in an array
 * @arr: the array to alter
 * @n: the length of the array
 */
void reverse_array(int *arr, int n)
{
	int *left, *right;

	for (left = arr, right = arr + n - 1; left < right; left++, right--)
	{
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

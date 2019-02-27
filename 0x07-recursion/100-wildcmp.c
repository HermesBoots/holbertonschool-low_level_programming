#define NULL ((void *)0)

/**
 * skip_stars - move past all the asterisks in a string
 * @str: string to move through
 *
 * Return: pointer to first non-star character of str
 */
char *skip_stars(char *str)
{
	if (*str != '*')
		return (str);
	return (skip_stars(str + 1));
}

/**
 * do_match - perform the matching for wildcmp
 * @s1: string to match
 * @s2: pattern to match
 * @recall: where to revert s2 to if a partial wildcard match ended
 *
 * Return: 1 if string matches pattern, 0 if it doesn't
 */
int do_match(char *s1, char *s2, char *recall)
{
	if (*s2 == '*')
	{
		s2 = skip_stars(s2);
		recall = s2;
	}
	if (recall == s2)
	{
		if (*s1 == '\0' && *s2 != '\0')
			return (0);
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
		if (*s1 == *s2)
			return (do_match(s1 + 1, s2 + 1, recall));
		return (do_match(s1 + 1, s2, recall));
	}
	else
	{
		if (*s1 != *s2)
		{
			if (!recall)
				return (0);
			return (do_match(s1, recall, recall));
		}
		if (*s1 == '\0' || s2 == '\0')
			return (1);
		return (do_match(s1 + 1, s2 + 1, recall));
	}
}

/**
 * wildcmp - compare a pattern to a string
 * @s1: string to match
 * @s2: pattern to match
 *
 * Return: 1 if string matches pattern, 0 if it doesn't
 */
int wildcmp(char *s1, char *s2)
{
	return (do_match(s1, s2, NULL));
}

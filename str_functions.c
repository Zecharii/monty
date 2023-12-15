#include "monty.h"

/**
 * zsh_strcmp - function that compares two strings.
 * @s1: first str to compare
 * @s2: second str compare
 * Return: 0 if s1 and s2 are equals. Another value if they are different
 */
int zsh_strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * zsh_sch - searches if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int zsh_sch(const char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * zsh_strtoky - cuts a string into tokens depending on the delimiter
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *zsh_strtoky(const char *s, const char *d)
{
	static char *unique;
	int i = 0, j = 0;

	if (!s)
		s = unique;
	while (s[i] != '\0')
	{
		if (zsh_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			unique = s + i + 1;
			*unique = '\0';
			s = s + j;
			return (s);
		}
		else if (zsh_sch(d, s[i]) == 0 && zsh_sch(d, s[i + 1]) == 0)
			i++;
		else if (zsh_sch(d, s[i]) == 0 && zsh_sch(d, s[i + 1]) == 1)
		{
			unique = s + i + 1;
			*unique = '\0';
			unique++;
			s = s + j;
			return (s);
		}
		else if (zsh_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}


/**
 * zsh_calloc - concatenates to strings specially
 * @numb: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *zsh_calloc(unsigned int numb, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (numb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(numb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (numb * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * zsh_realloc - changes the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of bytes
 * Return: nothing
 */
void *zsh_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}

#include "lists.h"

/**
 * reverse_listint - reverses a linked list of type listint_t
 * @head: the head node of the linked list
 *
 * Return: new head node in reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next, *prev = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);
	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;

	return (*head);
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: pointer to the head of the linked list
 *
 * Return: 1 if palindrome, else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *mid = (*head), *forward = (*head), *reverse;
	size_t n, i;

	/** get size of linked list */
	for (n = 0; mid != NULL; n++)
		mid = mid->next;
	/** handle empty/one item linked list */
	if (n <= 1)
		return (1);
	/** increment i/mid to halfway point */
	mid = (*head);
	for (i = 0; i < n / 2 - 1; i++)
		mid = mid->next;
	/** skip middle if n is odd */
	if (n % 2 != 0)
		mid = mid->next;
	/** reverse nodes in list from mid */
	reverse = reverse_listint(&mid);
	for (i = 0; i < n / 2; i++)
	{
		/** if values aren't equal, cannot be palindrome */
		if (reverse->n != forward->n)
		{
			reverse_listint(&mid);
			return (0);
		}
		reverse = reverse->next;
		forward = forward->next;
	}
	/** un-reverse nodes in list from mid */
	reverse_listint(&mid);

	return (1);
}

#include "deck.h"

#define NULL ((void *)0)

/**
 * sort_deck - sort a deck of cards
 * @deck: dptr to a dll representing a deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	insertion_sort_list(deck);
}

/**
 * cast_card - convert a card structure to a byte
 * @card: card to cast
 * Return: byte representation of card
 */
unsigned char cast_card(card_t card)
{
	unsigned char ret;

	ret = card.kind << 4;
	if (card.value == NULL)
		return (ret);
	switch (card.value[0])
	{
	case '2': case '3': case '4': case '5': case '6': case '7': case '8':
	case '9':
		if (card.value[1] == '\0')
			ret |= card.value[0] - '0';
		break;
	case '1':
		if (card.value[1] == '0' && card.value[2] == '\0')
			ret |= 10;
		break;
	case 'A':
		if (card.value[1] == 'c' && card.value[2] == 'e')
			ret |= 1;
		break;
	case 'J':
		if (card.value[1] == 'a' && card.value[2] == 'c')
			ret |= 11;
		break;
	case 'Q':
		if (card.value[1] == 'u' && card.value[2] == 'e')
			ret |= 12;
		break;
	case 'K':
		if (card.value[1] == 'i' && card.value[2] == 'n')
			ret |= 13;
	}
	return (ret);
}

/**
 * insertion_sort_list - sort doubly linked list via insertion sort
 * @list: double pointer to a dll
 * Return: void
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *fp, *cfp, *bp;

	for (cfp = fp = (*list)->next; cfp != NULL; cfp = fp = cfp->next)
	{
		bp = fp->prev;
		while (bp != NULL && cast_card(*fp->card) < cast_card(*bp->card))
			bp = bp->prev;
		if (bp == fp->prev)
			continue;
		cfp = fp->prev;
		if (fp->next != NULL)
			fp->next->prev = fp->prev;
		fp->prev->next = fp->next;
		if (bp != NULL)
		{
			fp->next = bp->next;
			fp->prev = bp;
			bp->next = fp;
			fp->next->prev = fp;
		}
		else
		{
			fp->prev = NULL;
			fp->next = *list;
			(*list)->prev = fp;
			*list = fp;
		}
	}
}

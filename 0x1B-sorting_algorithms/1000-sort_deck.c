#include "sort.h"


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
 * sort_deck -
 *
 * Return: 
 */
void sort_deck(deck_node_t **deck)
{

}

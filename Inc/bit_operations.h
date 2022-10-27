#ifndef _BIT_OPERATIONS_H
#define _BIT_OPERATIONS_H

#define GET_BIT(number, position) (((number) & (1 << (position))) >> (position))

#define SET_BIT(destination, position) ((destination) |= (1 << (position)))
#define CLEAR_BIT(destination, position) ((destination) &= ~(1 << (position)))

#endif /*_BIT_OPERATIONS_H */

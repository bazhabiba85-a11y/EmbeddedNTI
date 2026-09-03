#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, POS)     ((REG) |= (1 << (POS)))
#define CLR_BIT(REG, POS)     ((REG) &= ~(1 << (POS)))
#define TOG_BIT(REG, POS)     ((REG) ^= (1 << (POS)))
#define GET_BIT(REG, POS)     (((REG) >> (POS)) & 1)

#endif
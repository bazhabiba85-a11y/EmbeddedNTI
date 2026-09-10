#ifndef SPI_H_
#define SPI_H_

#include "STD_TYPES.h"

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8   SPI_u8Transceive(u8 copy_u8Data);

#endif
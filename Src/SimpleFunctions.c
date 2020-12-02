/*
 * SimpleFunctions.c
 *
 *  Created on: Mar 18, 2020
 *      Author: user
 */

#include "SimpleFunctions.h"

unsigned char ByteFlip(unsigned char In)
{
  unsigned char Out = 0;
  if(In & 0x01) Out |= 0x80;
  if(In & 0x02) Out |= 0x40;
  if(In & 0x04) Out |= 0x20;
  if(In & 0x08) Out |= 0x10;
  if(In & 0x10) Out |= 0x08;
  if(In & 0x20) Out |= 0x04;
  if(In & 0x40) Out |= 0x02;
  if(In & 0x80) Out |= 0x01;
  return Out;
}




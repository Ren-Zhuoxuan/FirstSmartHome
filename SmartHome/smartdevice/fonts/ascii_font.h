#ifndef ASCII_FONT_H
#define ASCII_FONT_H
#include <font_manager.h>
#include <stdio.h>
#include <string.h>
static void ASCIIGetFontSize(int *pWidth,int *pHeight);

static int ASCIIGetFontBitMap(unsigned int dwCode, PFontBitMap ptFontBitMap);

void AddFontLibASCII(void);

#endif

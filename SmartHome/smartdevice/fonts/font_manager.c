#include <font_manager.h>
#include <string.h>

static PFontLib g_ptFontLibs;


void FontLibRegister(PFontLib ptFontLib)
{
    ptFontLib->pNext = g_ptFontLibs;
    g_ptFontLibs =  ptFontLib;
}

PFontLib __GetFontLib(char *name)
{
    PFontLib pTmp = g_ptFontLibs;
    while (pTmp)
    {
        if (strcmp(pTmp->name,name) == 0)
        {
            return pTmp;
        }
        pTmp = pTmp->pNext;
    }
    return NULL;
}
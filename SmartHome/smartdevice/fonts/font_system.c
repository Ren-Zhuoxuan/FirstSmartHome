#include <font_system.h>

//可以添加众多字库
void AddFontLibs(void)
{
    AddFontLibASCII();
}

PFontLib GetFontLib(char *name)
{
    return __GetFontLib(name);
}
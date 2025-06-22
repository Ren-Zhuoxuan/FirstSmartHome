#ifndef __FONT_MANAGER_H
#define __FONT_MANAGER_H

//描述这个字体
typedef struct FontBitMap {
	int iLeftUpX;     /* 位图左上角X坐标 */
	int iLeftUpY;     /* 位图左上角Y坐标 */
	int iWidth;       /* 字体宽度 */
	int iRows;        /* 字体高度 */
	int iCurOriginX;  /* 原点X坐标 */
	int iCurOriginY;  /* 原点Y坐标 */
	int iNextOriginX; /* 下一个字符X坐标 */ 
	int iNextOriginY; /* 下一个字符Y坐标 */ 
	unsigned char *pucBuffer; /* 字符点阵 */
}FontBitMap, *PFontBitMap;



typedef struct FontLib {
	char *name;
	int (*FontInit)(struct FontOpr *pFontLib);  /* 初始化字库 */
	int (*GetFontSize)(void);                   /* 获取字体大小 */
	int (*SetFontSize)(int iFontSize);          /* 设置字体大小 */
	int (*GetFontBitMap)(unsigned int dwCode, PFontBitMap ptFontBitMap);  /* 获取某个字符的字库 dwCode传入字符，ptFontBitMap获得点阵*/
	struct FontLib *ptNext;
}FontLib, *PFontLib;

//注册的时候会把这些lib放入链表，还可以从链表中取出字库

void FontLibRegister(PFontLib ptFontLib);

PFontLib GetFontLib(char *name);


#endif

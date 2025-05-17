/*  Copyright (s) 2019 深圳百问网科技有限公司
 *  All rights reserved
 * 
 * 文件名称：ring_buffer.c
 * 摘要：
 *  
 * 修改历史     版本号        Author       修改内容
 *--------------------------------------------------
 * 2021.8.21      v01         百问科技      创建文件
 *--------------------------------------------------
*/

#include "input_buffer.h"

static InputEventBuffer g_tInputBuffer;


int PutInputEvent(PInputEvent ptInputEvent)
{
    int i = (g_tInputBuffer.pW + 1) % BUFFER_SIZE;
    //防止指针为空
    if (!ptInputEvent)
    {
        return -1;
    }
    if (i != g_tInputBuffer.pR)
    {
        g_tInputBuffer.buffer[g_tInputBuffer.pW] = *ptInputEvent;
        g_tInputBuffer.pW  = i;
        return 0;
    }
    return -1;
}


int GetInputEvent(PInputEvent ptInputEvent)
{
    if (!ptInputEvent)
    {
        return -1;
    }
    if(g_tInputBuffer.pR == g_tInputBuffer.pW)
    {
        return -1;
    }
    else
    {
        *ptInputEvent = g_tInputBuffer.buffer[g_tInputBuffer.pR];
        g_tInputBuffer.pR = (g_tInputBuffer.pR + 1) %  BUFFER_SIZE;
        return 0;
    }
}

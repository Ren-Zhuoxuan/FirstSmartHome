/*  Copyright (s) 2019 深圳百问网科技有限公司
 *  All rights reserved
 * 
 * 文件名称：input_buffer.h
 * 摘要：
 *  
 * 修改历史     版本号        Author       修改内容
 *--------------------------------------------------
 * 2021.8.21      v01         百问科技      创建文件
 *--------------------------------------------------
*/
#ifndef __INPUT_BUFFER_H
#define __INPUT_BUFFER_H

#include "input_system.h"

#define BUFFER_SIZE 10        /* 环形缓冲区的大小 */
typedef struct
{
    InputEvent buffer[BUFFER_SIZE];  /* 缓冲区空间 */
    volatile unsigned int pW;           /* 写地址 */
    volatile unsigned int pR;           /* 读地址 */
} InputEventBuffer;


int GetInputEvent(PInputEvent PtInputEvent);
int PutInputEvent(PInputEvent PtInputEvent);



#endif /* __INPUT_BUFFER_H */

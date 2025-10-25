#pragma once

#include "defines.h"

// 指向窗口指针/句柄等状态对象，由于平台不同，具体内容由各个平台实现定义。
typedef struct platform_state {
    void* internal_state;
} platform_state;

b8 platform_setup(
    platform_state* plat_stat,
    const char* application_name,
    i32 x,
    i32 y,
    i32 width,
    i32 height);

void platform_shutdown(platform_state* plat_state);

// 处理平台消息队列，返回是否继续运行应用程序
b8 platform_pump_messages(platform_state* plat_state);

// 平台相关的内存操作函数接口
void* platform_allocate(u64 size, b8 aligned);
void platform_free(void* block, b8 aligned);
void* platform_zero_memory(void* block, u64 size);
void* platform_copy_memory(void* dest, const void* source, u64 size);
void* platform_set_memory(void* dest, i32 value, u64 size);

void platform_console_write(const char* message, u8 colour);
void platform_console_write_error(const char* message, u8 colour);

f64 platform_get_absolute_time();

// Sleep on the thread for the provided ms. This blocks the main thread.
// Should only be used for giving time back to the OS for unused update power.
// Therefore it is not exported.
void platform_sleep(u64 ms);
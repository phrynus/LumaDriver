#pragma once

#include <ntifs.h>

// 基础配置
#define SHARED_MEM_SIZE                 1024                        // 共享内存大小
#define XOR_KEY                         {0xAA, 0xBB, 0xCC}          // 异或密钥
#define XOR_KEY_SIZE                    8                           // 异或密钥大小
#define DEVICE_NAME                     L"\\Device\\LumaDriver"     // 设备名
#define DEVICE_LINK_NAME                L"\\??\\LumaDriver"         // 符号链接名

// IO通讯
#define IOCTL_IO CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)  // 通讯码

// 指令码
// 进程管理
#define CMD_GET_PROCESS_ID       0x01  // 获取进程ID
#define CMD_TERMINATE_PROCESS    0x03  // 终止进程
#define CMD_HIDE_PROCESS         0x04  // 隐藏进程
// 模块管理
#define CMD_GET_MODULE_BASE      0x05  // 获取模块基址
#define CMD_GET_MODULE_EXPORTS   0x06  // 获取模块导出函数
#define CMD_ENUM_MODULES         0x07  // 枚举模块
// 内存管理
#define CMD_READ_WRITE_MEM       0x08  // 读写内存
#define CMD_FORCE_RW_MEM         0x09  // 强读写内存
#define CMD_ALLOC_MEM            0x0A  // 申请内存
#define CMD_FREE_MEM             0x0B  // 释放内存
#define CMD_PROTECT_MEM          0x0C  // 保护内存
#define CMD_SCAN_MEM             0x0D  // 内存扫描
#define CMD_HIDE_MEM             0x0E  // 内存隐藏
// 窗口管理
#define CMD_HIDE_WINDOW          0x0F  // 隐藏窗口
#define CMD_SHOW_WINDOW          0x10  // 显示窗口
// 驱动管理
#define CMD_HIDE_DRIVER          0x12  // 驱动隐藏
// 输入模拟
#define CMD_SIMULATE_KEY         0x14  // 模拟按键
#define CMD_SIMULATE_MOUSE       0x15  // 模拟鼠标
// DLL 管理
#define CMD_INJECT_DLL           0x16  // 注入DLL
#define CMD_UNLOAD_DLL           0x17  // 卸载DLL

// 结构体
// 通讯结构体
typedef struct _IO_STRUCT
{
	ULONG64 Command;					// 指令码      
	ULONG64 ProcessId;                  // 进程ID
	ULONG64 Address;                    // 内存地址
	ULONG64 Size;                       // 大小
	ULONG64 Type;                       // 类型
	ULONG64 Buffer;                     // 缓冲区
} IO_STRUCT, * PIO_STRUCT;
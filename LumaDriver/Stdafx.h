#pragma once

#include <ntifs.h>

// ��������
#define SHARED_MEM_SIZE                 1024                        // �����ڴ��С
#define XOR_KEY                         {0xAA, 0xBB, 0xCC}          // �����Կ
#define XOR_KEY_SIZE                    8                           // �����Կ��С
#define DEVICE_NAME                     L"\\Device\\LumaDriver"     // �豸��
#define DEVICE_LINK_NAME                L"\\??\\LumaDriver"         // ����������

// IOͨѶ
#define IOCTL_IO CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)  // ͨѶ��

// ָ����
// ���̹���
#define CMD_GET_PROCESS_ID       0x01  // ��ȡ����ID
#define CMD_TERMINATE_PROCESS    0x03  // ��ֹ����
#define CMD_HIDE_PROCESS         0x04  // ���ؽ���
// ģ�����
#define CMD_GET_MODULE_BASE      0x05  // ��ȡģ���ַ
#define CMD_GET_MODULE_EXPORTS   0x06  // ��ȡģ�鵼������
#define CMD_ENUM_MODULES         0x07  // ö��ģ��
// �ڴ����
#define CMD_READ_WRITE_MEM       0x08  // ��д�ڴ�
#define CMD_FORCE_RW_MEM         0x09  // ǿ��д�ڴ�
#define CMD_ALLOC_MEM            0x0A  // �����ڴ�
#define CMD_FREE_MEM             0x0B  // �ͷ��ڴ�
#define CMD_PROTECT_MEM          0x0C  // �����ڴ�
#define CMD_SCAN_MEM             0x0D  // �ڴ�ɨ��
#define CMD_HIDE_MEM             0x0E  // �ڴ�����
// ���ڹ���
#define CMD_HIDE_WINDOW          0x0F  // ���ش���
#define CMD_SHOW_WINDOW          0x10  // ��ʾ����
// ��������
#define CMD_HIDE_DRIVER          0x12  // ��������
// ����ģ��
#define CMD_SIMULATE_KEY         0x14  // ģ�ⰴ��
#define CMD_SIMULATE_MOUSE       0x15  // ģ�����
// DLL ����
#define CMD_INJECT_DLL           0x16  // ע��DLL
#define CMD_UNLOAD_DLL           0x17  // ж��DLL

// �ṹ��
// ͨѶ�ṹ��
typedef struct _IO_STRUCT
{
	ULONG64 Command;					// ָ����      
	ULONG64 ProcessId;                  // ����ID
	ULONG64 Address;                    // �ڴ��ַ
	ULONG64 Size;                       // ��С
	ULONG64 Type;                       // ����
	ULONG64 Buffer;                     // ������
} IO_STRUCT, * PIO_STRUCT;
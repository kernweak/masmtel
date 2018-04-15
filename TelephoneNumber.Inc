.386				;汇编语言伪指令，在386及以后的处理器使用
.model flat,stdcall		;模式定义“model 内存模式[,调用模式]”
option casemap:none		;选定设定（设定大小写敏感）


include windows.inc
include msvcrt.inc		;包含C语言的库
includelib msvcrt.lib		;包含c语言库对应的lib文件

include kernel32.inc
includelib kernel32.lib
.data

CONTACTSSTRUCT struct
	szName     BYTE  25 dup(0h)	;名字
	szPhNumber BYTE  12 dup(0h)	;电话号码
CONTACTSSTRUCT ends

PCONTACTSSTRUCT TYPEDEF PTR CONTACTSSTRUCT	;取别名
;[新的类型名]	TYPEDEF	PTR [原来的类型名]	;表示取一个指针类型的类型

;声明全局变量
g_stContacts  CONTACTSSTRUCT 100 dup(<'0'>)	;定义结构体数组
;_stContacts2 CONTACTSSTRUCT 100 dup(<'0'>)	;定义结构体数组

temp DWORD 0
g_nCount DWORD 0				;元素个数
g_nCountMax DWORD 100				;最大存放元素
g_szAddStr db '请输入新用户:',0ah,0dh,0		;地址
g_szAddStr1 db '请输入要查询的用户:',0ah,0dh,0
g_szAddStr2 db '请输入要修改的用户:',0ah,0dh,0	
g_strTemContacts CONTACTSSTRUCT <'0','0'>	;接收输入信息

;；定义格式控制符	用于输入输出时候用到的格式控制符
g_szScanfFormat	BYTE '%s %s',0
g_szScanName BYTE '%s',0
g_szSelectForm BYTE '%d',0
g_szSelect dword 0
g_szNotSearch db '查无此人',0ah,0dh,0
g_szOK db '删除成功',0ah,0dh,0
g_szqinping db 'cls',0
g_szStart db '---------------------选择---------------------',0ah,0dh,
	   '------------------1.添加用户------------------',0ah,0dh,
	   '------------------2.查询用户------------------',0ah,0dh,
	   '------------------3.修改用户------------------',0ah,0dh,
	   '------------------4.删除用户------------------',0ah,0dh,
	   '---------------------选择---------------------',0ah,0dh,0
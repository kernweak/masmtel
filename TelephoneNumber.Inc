.386				;�������αָ���386���Ժ�Ĵ�����ʹ��
.model flat,stdcall		;ģʽ���塰model �ڴ�ģʽ[,����ģʽ]��
option casemap:none		;ѡ���趨���趨��Сд���У�


include windows.inc
include msvcrt.inc		;����C���ԵĿ�
includelib msvcrt.lib		;����c���Կ��Ӧ��lib�ļ�

include kernel32.inc
includelib kernel32.lib
.data

CONTACTSSTRUCT struct
	szName     BYTE  25 dup(0h)	;����
	szPhNumber BYTE  12 dup(0h)	;�绰����
CONTACTSSTRUCT ends

PCONTACTSSTRUCT TYPEDEF PTR CONTACTSSTRUCT	;ȡ����
;[�µ�������]	TYPEDEF	PTR [ԭ����������]	;��ʾȡһ��ָ�����͵�����

;����ȫ�ֱ���
g_stContacts  CONTACTSSTRUCT 100 dup(<'0'>)	;����ṹ������
;_stContacts2 CONTACTSSTRUCT 100 dup(<'0'>)	;����ṹ������

temp DWORD 0
g_nCount DWORD 0				;Ԫ�ظ���
g_nCountMax DWORD 100				;�����Ԫ��
g_szAddStr db '���������û�:',0ah,0dh,0		;��ַ
g_szAddStr1 db '������Ҫ��ѯ���û�:',0ah,0dh,0
g_szAddStr2 db '������Ҫ�޸ĵ��û�:',0ah,0dh,0	
g_strTemContacts CONTACTSSTRUCT <'0','0'>	;����������Ϣ

;�������ʽ���Ʒ�	�����������ʱ���õ��ĸ�ʽ���Ʒ�
g_szScanfFormat	BYTE '%s %s',0
g_szScanName BYTE '%s',0
g_szSelectForm BYTE '%d',0
g_szSelect dword 0
g_szNotSearch db '���޴���',0ah,0dh,0
g_szOK db 'ɾ���ɹ�',0ah,0dh,0
g_szqinping db 'cls',0
g_szStart db '---------------------ѡ��---------------------',0ah,0dh,
	   '------------------1.�����û�------------------',0ah,0dh,
	   '------------------2.��ѯ�û�------------------',0ah,0dh,
	   '------------------3.�޸��û�------------------',0ah,0dh,
	   '------------------4.ɾ���û�------------------',0ah,0dh,
	   '---------------------ѡ��---------------------',0ah,0dh,0
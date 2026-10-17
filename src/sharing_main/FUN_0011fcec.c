/* HSTMATCH module=hstp_trans_main.prx start=0x0011fcec end=0x0011fd10 symbol=FUN_0011fcec lang=c99 */
/* Clone of src/eboot/FUN_00114fdc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


int FUN_0011fcec(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + param_2 * 4);
  return (int)(short)(*(short *)(iVar1 + 8) - *(short *)(iVar1 + 4));
}

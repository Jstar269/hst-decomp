/* HSTMATCH module=hstp_trans_main.prx start=0x0019709c end=0x001970ac symbol=FUN_0019709c lang=c99 */
/* Clone of src/eboot/FUN_0018a950.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00113a50();

void FUN_0019709c(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x78);
  *(undefined4 *)(iVar1 + 0xf8) = param_2;
  *(undefined4 *)(iVar1 + 0x138) = 0;
  FUN_00113a50(iVar1);
  return;
}

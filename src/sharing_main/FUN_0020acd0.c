/* HSTMATCH module=hstp_trans_main.prx start=0x0020acd0 end=0x0020ad2c symbol=FUN_0020acd0 lang=c99 */
/* Clone of src/eboot/FUN_001fc5b8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108f54();
extern void FUN_0020ae30();

void FUN_0020acd0(int param_1,undefined1 param_2)
{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x54) = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0x3c) + 0x90) = param_2;
  iVar1 = *(int *)(param_1 + 0x44);
  FUN_00108f54(iVar1);
  *(undefined1 *)(iVar1 + 0x5c) = param_2;
  FUN_0020ae30(param_1,0);
  return;
}

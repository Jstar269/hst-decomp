/* HSTMATCH module=hstp_trans_main.prx start=0x001c8c14 end=0x001c8c40 symbol=FUN_001c8c14 lang=c99 */
/* Clone of src/eboot/FUN_001baecc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


undefined1 FUN_001c8c14(int param_1,int param_2)
{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(**(int **)(*(int *)(param_1 + 4) + param_2 * 4) + 0x5c);
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = *(undefined1 *)(iVar2 + 0x171);
  }
  return uVar1;
}

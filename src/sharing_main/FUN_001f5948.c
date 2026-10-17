/* HSTMATCH module=hstp_trans_main.prx start=0x001f5948 end=0x001f5988 symbol=FUN_001f5948 lang=c99 */
/* Clone of src/eboot/FUN_001e7730.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_001fc5c8();

void FUN_001f5948(char *param_1)
{
  char *iVar1;
  
  iVar1 = (char *)(FUN_001fc5c8());
  *(int *)(param_1 + 0x2350) = *(int *)(iVar1 + 0x8178) + 4;
  *(undefined4 *)(param_1 + 0x2354) = 0xf;
  return;
}

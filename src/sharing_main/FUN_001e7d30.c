/* HSTMATCH module=hstp_trans_main.prx start=0x001e7d30 end=0x001e7d7c symbol=FUN_001e7d30 lang=c99 */
/* Clone of src/eboot/FUN_001d9c78.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001e77e4();
extern void FUN_001e35f4();

void FUN_001e7d30(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(iVar1 + 0xd4) = 3;
  *(undefined4 *)(iVar1 + 0x520) = 4;
  FUN_001e77e4(iVar1 + 0x1110,8);
  FUN_001e35f4(iVar1,5,0);
  return;
}

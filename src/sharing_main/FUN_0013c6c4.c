/* HSTMATCH module=hstp_trans_main.prx start=0x0013c6c4 end=0x0013c714 symbol=FUN_0013c6c4 lang=c99 */
/* Clone of src/eboot/FUN_0013110c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0001ef14();
extern void FUN_0012f2d0();
extern undefined4 FUN_001303ec();

void FUN_0013c6c4(int param_1)
{
  undefined4 uVar1;
  
  FUN_0001ef14(*(undefined4 *)(param_1 + 0x80),1);
  FUN_0012f2d0(*(undefined4 *)(param_1 + 0x80),0,0);
  uVar1 = FUN_001303ec(*(undefined4 *)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x88) = uVar1;
  *(undefined4 *)(param_1 + 0x8c) = 3;
  return;
}

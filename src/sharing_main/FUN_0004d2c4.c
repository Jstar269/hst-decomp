/* HSTMATCH module=hstp_trans_main.prx start=0x0004d2c4 end=0x0004d31c symbol=FUN_0004d2c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_003b3e6c;
extern undefined DAT_003b8ec5;
extern undefined4 DAT_003ba498;
extern void FUN_0001c340();
extern int FUN_002c7518();

undefined4 FUN_0004d2c4(void)
{
  undefined4 uVar1;
  
  if (DAT_003ba498 == 0) {
    if (DAT_003b8ec5 != '\0') {
      FUN_0001c340((int)&DAT_003b3e6c);
      return 0;
    }
  }
  else {
    DAT_003ba498 = DAT_003ba498 + -1;
  }
  uVar1 = FUN_002c7518();
  return uVar1;
}

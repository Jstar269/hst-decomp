/* HSTMATCH module=EBOOT.BIN start=0x0022c07c end=0x0022c0d4 symbol=FUN_0022c07c lang=c99 */
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

extern undefined * DAT_003415a8;

void FUN_0022c07c(int param_1)
{
  if (param_1 == 0) {
    *(ushort *)(DAT_003415a8 + 0xd504) = *(ushort *)(DAT_003415a8 + 0xd504) & 0xfffe;
  }
  else {
    *(ushort *)(DAT_003415a8 + 0xd504) = *(ushort *)(DAT_003415a8 + 0xd504) | 1;
  }
  return;
}

// NEAR MISS: 18/22 words. Sets/clears bit 0 of the halfword at DAT_003415a8+0x10000-11004 when param!=0/==0; retail computes that address TWICE with different registers (lui 0x1 / move / addu / lhu / addu / sh), every inline spelling lets MWCC CSE it to 16 words.
// near miss from lane fm5 (unreviewed)

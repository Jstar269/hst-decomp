/* HSTMATCH module=hstp_trans_main.prx start=0x0001c848 end=0x0001c8a0 symbol=FUN_0001c848 lang=c99 */
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

extern undefined4 DAT_003751d0;
extern void * DAT_003b8efc;
extern void * DAT_003b8f00;
extern void * DAT_003b8f04;
extern void * FUN_00010184();

void FUN_0001c848(void)
{
  if (DAT_003b8efc == 0) {
    DAT_003b8efc = FUN_00010184(0x40,DAT_003751d0);
    DAT_003b8f00 = DAT_003b8efc;
    DAT_003b8f04 = (char *)DAT_003b8efc + DAT_003751d0;
  }
  return;
}

// Near miss: three words differ; retail loads the global through v0, while this candidate uses v1 for the load and branch.
// A cached local pointer kept the same mismatch, and the GCC profile worsened the match.
// near miss from lane u1r2-1 (unreviewed)

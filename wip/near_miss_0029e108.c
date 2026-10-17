/* HSTMATCH module=EBOOT.BIN start=0x0029e108 end=0x0029e160 symbol=FUN_0029e108 lang=c99 */
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

extern char DAT_002cb5e8[];
extern char DAT_002cb63c[];
extern void FUN_0029a584();
extern int FUN_002b7cc0();

void FUN_0029e108(void)
{
  int iVar1;
  
  iVar1 = FUN_002b7cc0(0x101);
  if (iVar1 < 0) {
    FUN_0029a584(DAT_002cb63c,iVar1);
  }
  iVar1 = FUN_002b7cc0(0x100);
  if (iVar1 < 0) {
    FUN_0029a584(DAT_002cb5e8,iVar1);
  }
  return;
}

// Near miss: five words remain around the second negative-result check.
// Retail branches on v0 and loads ra in the likely slot; this candidate copies v0 to a1 before the branch.
// near miss from lane u5cr1-0 (unreviewed)

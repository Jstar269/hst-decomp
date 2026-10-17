/* HSTMATCH module=EBOOT.BIN start=0x0029a5b0 end=0x0029a660 symbol=FUN_0029a5b0 lang=c99 */
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

extern int DAT_002ffcc8;
extern char DAT_002ffd3c[];
extern char DAT_002ffd74[];
extern char DAT_002ffda4[];
extern char DAT_002ffdd4[];
extern void FUN_0029a584(const char *, int);
extern int FUN_002b7d70();
extern int FUN_002b7d78();
extern int FUN_002b7d90();
extern int FUN_002b7e40();

void FUN_0029a5b0(void)
{
  int iVar1;
  int initial_count = DAT_002ffcc8;
  
  if (0 < initial_count) {
    iVar1 = FUN_002b7d70();
    if (iVar1 < 0) {
      FUN_0029a584(DAT_002ffd3c,iVar1);
    }
    DAT_002ffcc8 = -1;
  }
  iVar1 = FUN_002b7d78();
  if (iVar1 < 0) {
    FUN_0029a584(DAT_002ffd74,iVar1);
  }
  iVar1 = FUN_002b7e40();
  if (iVar1 < 0) {
    FUN_0029a584(DAT_002ffda4,iVar1);
  }
  iVar1 = FUN_002b7d90();
  if (iVar1 < 0) {
    FUN_0029a584(DAT_002ffdd4,iVar1);
  }
  return;
}
// Near miss: 2 words differ in the first global load and signed branch register (retail uses a0; this source uses v0). Typed the global as signed, passed the final status argument, and kept every later word exact.
// near miss from lane u5cr1-1 (unreviewed)

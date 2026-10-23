/* HSTMATCH module=EBOOT.BIN start=0x0028637c end=0x002863e4 symbol=FUN_0028637c lang=c99 */
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

extern undefined4 DAT_003415ac;
extern void FUN_002805fc();

void FUN_0028637c(int param_1)
{
  *(undefined1 *)(param_1 + 0xc5) = 1;
  if ((*(uchar *)(param_1 + 4) == '\0') &&
     (((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0 ||
      (*(int *)(DAT_003415ac + 0x68) != 6)))) {
    FUN_002805fc(param_1 + 5);
  }
  return;
}

// Near miss: retail uses t0 for the global context pointer; this draft uses a1 at four words.
// Tried byte-pointer and void-pointer globals, a typed struct view, pointer-typed input and callee,
// scoped context locals, nested guards, early returns, and inline context accessors; none reduced the gap.
// near miss from lane km3 (unreviewed)

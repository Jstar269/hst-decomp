/* HSTMATCH module=EBOOT.BIN start=0x00290da4 end=0x00290f68 symbol=FUN_00290da4 lang=c99 */
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

extern undefined DAT_0034a80c;
extern undefined4 DAT_0034a810;
extern undefined4 DAT_0034a814;
extern char DAT_002ff830[];
extern char DAT_002ff85c[];
extern char DAT_002ff890[];
extern char DAT_002ff8bc[];
extern uint * FUN_000114c0();
extern undefined4 FUN_000615f4();
extern undefined4 FUN_0006171c();
extern void FUN_0028fb44();
extern void FUN_002b7958();
extern void FUN_002b79b0();
extern int FUN_002b7a78();
extern int FUN_002b7ed0();
extern int FUN_002b7ee0();

undefined4 FUN_00290da4(int param_1)
{
  int iVar1;
  
  do {
    if (DAT_0034a80c != '\0') {
      iVar1 = *(int *)(param_1 + 0xe0);
      goto LAB_00290ec0;
    }
    iVar1 = FUN_002b7ee0(param_1);
    if (iVar1 < 0) {
      FUN_0028fb44(DAT_002ff85c,iVar1);
      goto LAB_00290ebc;
    }
    if (iVar1 == 2) goto LAB_00290ebc;
    iVar1 = FUN_002b7ed0(param_1,*(undefined4 *)(param_1 + *(int *)(param_1 + 0xe0) * 4 + 0xd4));
    if (iVar1 != -0x7f9e9ff4) {
      if (iVar1 < 0) {
        FUN_0028fb44(DAT_002ff890,iVar1);
        goto LAB_00290ebc;
      }
      if (iVar1 == 0) {
        iVar1 = FUN_000615f4(0,DAT_0034a810,DAT_0034a814,
                             *(undefined4 *)(param_1 + *(int *)(param_1 + 0xe0) * 4 + 0xd4));
        if (iVar1 < 0) {
          FUN_0028fb44(DAT_002ff8bc,iVar1);
          iVar1 = *(int *)(param_1 + 0xe0);
        }
        else {
          iVar1 = *(int *)(param_1 + 0xe0);
        }
        *(uint *)(param_1 + 0xe0) = iVar1 + 1U & 1;
      }
    }
    iVar1 = FUN_002b7a78();
  } while (-1 < iVar1);
  FUN_0028fb44(DAT_002ff830,iVar1);
LAB_00290ebc:
  iVar1 = *(int *)(param_1 + 0xe0);
LAB_00290ec0:
  FUN_000114c0(*(undefined4 *)(iVar1 * 4 + param_1 + 0xd4),0,*(undefined4 *)(param_1 + 0xdc));
  iVar1 = FUN_000615f4(0,0,0,*(undefined4 *)(*(int *)(param_1 + 0xe0) * 4 + param_1 + 0xd4));
  if (iVar1 < 0) {
    FUN_0028fb44(DAT_002ff8bc,iVar1);
  }
  iVar1 = *(int *)(param_1 + 0xe0);
  *(uint *)(param_1 + 0xe0) = iVar1 + 1U & 1;
  iVar1 = FUN_0006171c(0);
  while (iVar1 != 0) {
    FUN_002b7958(1000);
    iVar1 = FUN_0006171c(0);
  }
  FUN_002b79b0(0);
  return 0;
}
// near miss: 114/113 words, 54 differ, first at +0x18. Retail's entry test is the inline-bool idiom
// `lbu v0,G; sltu v0,zero,v0; xori v0,1; beqzl v0,<join>` - i.e. a bool helper returning `!flag`
// tested with a negation - where our `if (G != '\0')` is a plain `beqzl` on the lbu (2 words short at
// the top) and that shifts every block. Tried and rejected: `int off = !G; if (off == 0)` (adds 2
// words, 102 differ), `if (!(!G))` (unchanged). The rest of the body (0x290dcc..) is otherwise
// unexamined; the remaining 52 diffs are all downstream of that 2-word shift.
// near miss from lane fm9 (unreviewed)
// near miss from lane dsn3 (unreviewed)

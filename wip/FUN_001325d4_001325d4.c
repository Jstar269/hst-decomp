/* HSTMATCH module=EBOOT.BIN start=0x001325d4 end=0x0013292c symbol=FUN_001325d4 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned int uint;
typedef int code();

extern undefined4 DAT_003402a4;
extern undefined4 DAT_003402ac;

extern void FUN_000009e4();
extern void FUN_002026cc();
extern void FUN_0013cef0();
extern void FUN_0013ce34();
extern void FUN_0013cd78();
extern void FUN_00140d58();

#define TEAR(p, cnt, base)                                                    \
  uVar4 = 0;                                                                  \
  if (*(int *)((char *)(p) + (cnt)) != 0) {                                   \
    iVar3 = *(int *)((char *)(p) + (base));                                   \
    while (1) {                                                               \
      int *q_ = *(int **)(iVar3 + uVar4 * 4);                                 \
      if (q_ != (int *)0x0) {                                                 \
        (**(code **)(*q_ + 8))(q_, 1);                                        \
        *(undefined4 *)(*(int *)((char *)(p) + (base)) + uVar4 * 4) = 0;      \
      }                                                                       \
      uVar1 = *(uint *)((char *)(p) + (cnt));                                 \
      {                                                                       \
        uVar4 = uVar4 + 1;                                                    \
      }                                                                       \
      if (uVar1 <= uVar4) break;                                              \
      iVar3 = *(int *)((char *)(p) + (base));                                 \
    }                                                                         \
  }                                                                           \
  *(undefined4 *)((char *)(p) + (cnt)) = 0;

void FUN_001325d4(int param_1)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;

  if (DAT_003402a4 != 0) {
    FUN_000009e4();
    DAT_003402a4 = 0;
  }
  if (DAT_003402ac == 0) {
    piVar2 = *(int **)(param_1 + 0x1384);
  }
  else {
    FUN_000009e4();
    DAT_003402ac = 0;
    piVar2 = *(int **)(param_1 + 0x1384);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2, 1);
    *(undefined4 *)(param_1 + 0x1384) = 0;
  }
  iVar3 = *(int *)(param_1 + 5000);
  if (iVar3 != 0) {
    FUN_002026cc(iVar3, 1);
    *(undefined4 *)(param_1 + 5000) = 0;
  }
  TEAR(param_1, 0x1390, 0x138c);
  TEAR(param_1, 0x139c, 0x1398);
  TEAR(param_1, 0x13a8, 0x13a4);
  TEAR(param_1, 0x13c0, 0x13bc);
  FUN_0013cef0(param_1 + 0x13e4, *(undefined4 *)(param_1 + 0x13e8), 0);
  TEAR(param_1, 0x13b4, 0x13b0);
  FUN_0013ce34(param_1 + 0x13d8, *(undefined4 *)(param_1 + 0x13dc), 0);
  TEAR(param_1, 0x13f4, 0x13f0);
  FUN_0013cd78(param_1 + 0x13cc, *(undefined4 *)(param_1 + 0x13d0), 0);
  FUN_00140d58(param_1 + 0x40);
  *(undefined1 *)(param_1 + 0x13c8) = 0;
  return;
}
// near miss from lane fm10 (unreviewed)

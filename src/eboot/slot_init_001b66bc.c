/* HSTMATCH module=EBOOT.BIN start=0x001b66bc end=0x001b6868 symbol=FUN_001b66bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3, via the km4 near miss) corrected by hand: the 4/5/6/7 selector is a nested if on bytes 0x90/0x93/0x94 (else 0x91), each arm storing its own result; the final test calls an inline int !*p helper (retail's sltu/xori/bnezl); exact match verified; names and types await human review. Matching idiom: int-returning inline IsClear(). */
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

extern undefined DAT_003386b8;
static inline int IsClear(unsigned char *p) { return !*p; }
extern undefined * DAT_00338b44;
extern undefined DAT_0034179c;
extern void FUN_000622d4();
extern int FUN_001b2af0(int *, int);
extern void FUN_001b3e2c();
extern void FUN_001b41c8();
extern void FUN_001b4530();

void FUN_001b66bc(int param_1)
{
  int iVar1;
  undefined2 *puVar2;
  
  if (*(unsigned char *)(param_1 + 0x90) != 0) {
    if (*(unsigned char *)(param_1 + 0x93) != 0) {
      *(int *)(param_1 + 0x4c) = FUN_001b2af0((int *)&DAT_0034179c,6);
    }
    else if (*(unsigned char *)(param_1 + 0x94) != 0) {
      *(int *)(param_1 + 0x4c) = FUN_001b2af0((int *)&DAT_0034179c,5);
    }
    else {
      *(int *)(param_1 + 0x4c) = FUN_001b2af0((int *)&DAT_0034179c,4);
    }
  }
  else if (*(unsigned char *)(param_1 + 0x91) != 0) {
    *(int *)(param_1 + 0x4c) = FUN_001b2af0((int *)&DAT_0034179c,7);
  }
  else {
    *(int *)(param_1 + 0x4c) = FUN_001b2af0((int *)&DAT_0034179c,4);
  }
  FUN_001b3e2c((int *)&DAT_0034179c);
  FUN_001b41c8((int *)&DAT_0034179c);
  FUN_000622d4(3,0x80,0x80,0);
  *(undefined1 *)(param_1 + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x79) = 1;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  if ((DAT_003386b8 == 0) || !IsClear((unsigned char *)(DAT_00338b44 + 0x45))) {
    FUN_001b4530((int *)&DAT_0034179c);
  }
  iVar1 = 0;
  do {
    puVar2 = *(undefined2 **)(param_1 + 0xa0);
    iVar1 = iVar1 + 6;
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xa4);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xa8);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xac);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xb0);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xb4);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    param_1 = param_1 + 0x18;
  } while (iVar1 < 0x12);
  return;
}

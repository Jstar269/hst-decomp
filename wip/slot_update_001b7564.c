/* HSTMATCH module=EBOOT.BIN start=0x001b7564 end=0x001b7664 symbol=FUN_001b7564 lang=c99 */
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

extern undefined * DAT_003386b0;
extern char DAT_002e99f8[];
extern void FUN_0005548c();
extern void FUN_001b2218();
extern undefined4 FUN_001b2438();

void FUN_001b7564(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
  undefined4 local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  undefined4 auStack_50 [12];
  
  iVar4 = 0;
  iVar3 = 0;
  do {
    piVar2 = (int *)(*(int *)(param_1 + 0x5c) + iVar3);
    if (-1 < *piVar2) {
      if (*(char *)(*(int *)(param_1 + 0x60) + iVar4) == '\0') {
        FUN_001b2438(0x34179c,piVar2);
      }
      else {
        if (DAT_003386b0 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(DAT_003386b0 + iVar3 + 0x70);
        }
        if ((iVar1 != 0) && (*(int *)(iVar1 + 0x5bc) != 0)) {
          FUN_0005548c(auStack_50,*(int **)(*(int *)(iVar1 + 0x5bc) + 0x58),
                       (byte *)DAT_002e99f8);
          local_8 = local_18;
          local_10 = local_20;
          local_c = local_1c;
          local_4 = local_14;
          FUN_001b2218();
        }
      }
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar4 < 4);
  return;
}

// NEAR MISS: best draft 52/64 words. Retail is a 4-iteration loop (s1 = 0..3, s0 = s1*4)
// over three parallel arrays at +0x5c/+0x60 plus a global at 0x3386b0: signed test on
// arr1[s0], byte test on arr2[s1], then a chain of null tests (global -> +0x70 -> +0x5bc)
// before building a temporary on the stack (0x60-byte frame: a 16-byte src at sp+16 copied
// through FUN_0005548c from a 0x2e99f8 descriptor, then four floats gathered from
// sp+64..sp+76 into sp+80..sp+92) and calling FUN_001b2218(&DAT_0034179c, arr1+s0,
// sp+80, 0, 1); the byte-test failure path calls FUN_001b2438(&DAT_0034179c).
// Not converged: the stack temporary's layout/order and the number of hoisted loads.
// near miss from lane fm5 (unreviewed)

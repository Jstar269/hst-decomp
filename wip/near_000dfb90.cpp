/* HSTMATCH module=EBOOT.BIN start=0x000dfb90 end=0x000dfd78 symbol=FUN_000dfb90 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


extern "C" undefined4 FUN_000dfb90(int *param_1,undefined4 *param_2)
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  piVar6 = (int *)(param_2 + -2);
  if ((param_1 == (int *)0x0) || ((int)param_1 - 1 != *param_1)) {
    uVar3 = 0xfffffffc;
  }
  else {
    uVar3 = 0xffffffff;
    if (param_2 != (undefined4 *)0x0) {
      if (((int *)param_2[-2] == param_1) && (iVar8 = param_2[-1], 0 < iVar8)) {
        uVar3 = 0xfffffffe;
        if ((param_1 + 6 <= piVar6) && (piVar6 < (int *)((int)param_1 + param_1[2]))) {
          piVar4 = (int *)param_1[5];
          if (piVar6 <= piVar4) goto LAB_000dfc10;
          piVar7 = (int *)*piVar4;
          piVar5 = piVar4;
          if (piVar6 < piVar7) {
            bVar1 = piVar6 < piVar7;
LAB_000dfc5c:
            if (((!bVar1) || (uVar3 = 0xfffffffd, piVar6 + iVar8 * 2 <= piVar7)) &&
               ((piVar6 <= piVar5 || (uVar3 = 0xfffffffd, piVar5 + piVar5[1] * 2 <= piVar6)))) {
              if (iVar8 < 2) {
                iVar9 = param_1[3];
              }
              else {
                *param_2 = 0xdeadbeef;
                param_2[1] = 0xdeadbeef;
                if (piVar5[1] >= 3) {
                  iVar8 = param_2[-1];
                  piVar6[iVar8 * 2 + -1] = -0x21524111;
                  piVar6[iVar8 * 2 + -2] = -0x21524111;
                }
                iVar8 = param_2[-1];
                iVar9 = param_1[3];
              }
              param_1[3] = iVar9 - iVar8;
              if ((piVar6 + param_2[-1] * 2 == piVar7) && (0 < piVar7[1])) {
                iVar8 = *piVar7;
                param_2[-1] = param_2[-1] + piVar7[1];
                *piVar6 = iVar8;
                piVar7[1] = 0;
                *piVar7 = 0;
              }
              else {
                *piVar6 = (int)piVar7;
              }
              if (piVar6 == piVar5 + piVar5[1] * 2) {
                iVar8 = *piVar6;
                piVar5[1] = piVar5[1] + param_2[-1];
                *piVar5 = iVar8;
                param_2[-1] = 0;
                *piVar6 = 0;
              }
              else {
                *piVar5 = (int)piVar6;
              }
              param_1[5] = (int)piVar5;
              uVar3 = 0;
            }
          }
          else {
            bVar2 = piVar4 < piVar6;
            while (uVar3 = 0xfffffffd, piVar6 != piVar5) {
              piVar4 = (int *)*piVar5;
              if ((piVar4 <= piVar5) &&
                 (bVar1 = piVar6 < piVar4, piVar7 = piVar4, piVar6 < piVar4 || bVar2))
              goto LAB_000dfc5c;
              if (piVar4 < piVar6) {
                piVar7 = (int *)*piVar4;
                piVar5 = piVar4;
                if (piVar6 < piVar7) {
                  bVar1 = piVar6 < piVar7;
                  goto LAB_000dfc5c;
                }
                bVar2 = piVar4 < piVar6;
              }
              else {
LAB_000dfc10:
                bVar2 = piVar4 < piVar6;
                piVar5 = piVar4;
              }
            }
          }
        }
      }
      else {
        uVar3 = 0xffffffff;
      }
    }
  }
  return uVar3;
}

// NEAR: best compile is 135/122 words, 133 differing. Retail puts p2-8 in a2,
// loads *p1 into v0 and p1-1 into a3, then uses a plain beq; this source uses
// v1/a2 and a branch-likely failure path. Tried C++ and C99 bool forms, signed
// return, typed Pool/Span headers, inline accessors, nested and split guards,
// declaration order changes, and loop/strength-reduction pragmas; none reduced
// the 133-word best difference. Control-flow and register placement remain open.
// near miss from lane km4 (unreviewed)

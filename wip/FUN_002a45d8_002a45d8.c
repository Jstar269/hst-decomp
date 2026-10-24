/* HSTMATCH module=EBOOT.BIN start=0x002a45d8 end=0x002a4938 symbol=FUN_002a45d8 lang=c99 */
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

extern undefined DAT_002cc0a4;
extern undefined4 DAT_002cc0d0;
extern undefined * DAT_003415a8;
extern undefined4 DAT_0034a0e2;
extern int FUN_001c062c();
extern undefined4 FUN_0022c194();
extern void FUN_0022c8d8();
extern int FUN_0022c928();
extern int FUN_0022c988();
extern void FUN_0023165c();
extern void FUN_002a1a64();
extern void FUN_002a2488();

void FUN_002a45d8(int param_1)
{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  iVar4 = FUN_0022c194();
  if (0 <= iVar4) {
    iVar5 = FUN_0022c928(iVar4);
    if (iVar5 != 0) {
      if (iVar4 != 7) {
        FUN_0022c8d8(iVar4,0);
      }
      FUN_0023165c(iVar4);
      iVar5 = FUN_0022c988(8);
      if (iVar5 != 0) {
        FUN_002a1a64(param_1,0x20);
        uVar8 = *(undefined4 *)(&DAT_002cc0a4 + iVar4 * 4);
        *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1b8);
        uVar7 = DAT_002cc0d0;
        *(undefined4 *)(param_1 + 0x1b8) = uVar8;
        *(undefined4 *)(param_1 + 0x1bc) = uVar7;
      }
    else {
        FUN_002a1a64(param_1,0x21);
        uVar7 = *(undefined4 *)(&DAT_002cc0a4 + iVar4 * 4);
        *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1b8);
        *(undefined4 *)(param_1 + 0x1b8) = uVar7;
        *(undefined4 *)(param_1 + 0x1bc) = 0;
      }
      if (((iVar4 == 9) && ((uint)(*(byte *)(DAT_003415a8 + 0x324) - 4) < 2)) &&
         (*(undefined1 *)(DAT_003415a8 + 0x86d24) == '\0')) {
        *(undefined1 *)(DAT_003415a8 + 0x86d24) = '\x01';
        *(undefined4 *)(param_1 + 0x1b8) = 0x35;
      }
    }
    else {
      if ((uint)(*(byte *)(DAT_003415a8 + 0x394) - 4) < 2) {
        if (*(undefined1 *)(DAT_003415a8 + 0x86d25) == '\0') {
          *(undefined1 *)(DAT_003415a8 + 0x86d25) = '\x01';
          if (*(int *)(param_1 + 0x1b0) != 5) {
            *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1b8);
            *(undefined4 *)(param_1 + 0x1b8) = 0x37;
            *(undefined4 *)(param_1 + 0x1bc) = 0;
            FUN_002a2488(param_1);
          }
          if (!((uint)(*(byte *)(DAT_003415a8 + 0x324) - 4) < 2)) {
            return;
          }
          if (*(undefined1 *)(DAT_003415a8 + 0x86d24) != '\0') {
            return;
          }
          *(undefined1 *)(DAT_003415a8 + 0x86d24) = '\x01';
          return;
        }
        bVar1 = *(byte *)(DAT_003415a8 + 0x35c);
      }
      else {
        bVar1 = *(byte *)(DAT_003415a8 + 0x35c);
      }
      if ((uint)(bVar1 - 4) < 2) {
        if (*(undefined1 *)(DAT_003415a8 + 0x86d26) == '\0') {
          *(undefined1 *)(DAT_003415a8 + 0x86d26) = '\x01';
          uVar6 = FUN_001c062c(DAT_003415a8 + 0x80);
          uVar9 = (uint)DAT_0034a0e2;
          if (*(int *)(param_1 + 0x1b0) != 5) {
            *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1b8);
            if (uVar9 == uVar6) {
              uVar7 = 0x33;
            }
            else {
              uVar7 = 0x34;
            }
            *(undefined4 *)(param_1 + 0x1b8) = uVar7;
            *(undefined4 *)(param_1 + 0x1bc) = 0;
            FUN_002a2488(param_1,1);
          }
          if (!((uint)(*(byte *)(DAT_003415a8 + 0x324) - 4) < 2)) {
            return;
          }
          if (*(undefined1 *)(DAT_003415a8 + 0x86d24) != '\0') {
            return;
          }
          *(undefined1 *)(DAT_003415a8 + 0x86d24) = '\x01';
          return;
        }
        bVar1 = *(byte *)(DAT_003415a8 + 0x324);
      }
      else {
        bVar1 = *(byte *)(DAT_003415a8 + 0x324);
      }
      if (((uint)(bVar1 - 4) < 2) && (*(undefined1 *)(DAT_003415a8 + 0x86d24) == '\0')) {
        bVar3 = true;
        if (2 < *(int *)(param_1 + 0x1b0) - 1U) {
          bVar2 = false;
          if (*(int *)(param_1 + 0x1b0) == 5) {
            bVar2 = **(int **)(param_1 + 0x1d0) == 2;
          }
          if (!bVar2) {
            bVar3 = false;
          }
        }
        if (((!bVar3) || (*(int *)(param_1 + 0x1b8) != 0x35)) &&
           (*(undefined1 *)(DAT_003415a8 + 0x86d24) = '\x01', *(int *)(param_1 + 0x1b0) != 5)) {
          *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1b8);
          *(undefined4 *)(param_1 + 0x1b8) = 0x36;
          *(undefined4 *)(param_1 + 0x1bc) = 0;
          FUN_002a2488(param_1);
        }
      }
    }
  }
  return;
}

// NEAR MISS 0x002a45d8: 214/216 words but ~115 words differ (offset shift plus
// three open points). Fixed and worth keeping: `if (0 <= iVar4)` for retail's
// bltzl early return; the outer `if (iVar5 != 0) {<else>} else {<then>}` arm
// order (the big block is out of line); the same arm-order swap on the inner
// `FUN_0022c988(8)` test; `(uint)(x - 4) < 2` for the sltiu range tests; the
// 0x86d2x flags as unsigned char (lbu). Open: (a) the `DAT_002cc0a4[iVar4]`
// store block has a0/a1 swapped (retail loads the table entry into a0 and the
// 0x1b8 field into a1); (b) the second `DAT_003415a8` block needs a base+0x80
// local so the fields read `lbu 732/860(...)` off it with the outer pointer in
// a2 and `addiu a1,a2,0x80` (ours keeps the outer pointer in a1 and uses
// absolute displacements); (c) two words still missing overall.
// near miss from lane fm10 (unreviewed)

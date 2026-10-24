/* HSTMATCH module=EBOOT.BIN start=0x001a9f74 end=0x001aa1cc symbol=FUN_001a9f74 lang=c99 */
/* STATUS CORRECTION 2026-10-24 (single pointer): 145/150 words, 119 differ, first diff +0x28.
   Was 146/150, differ 131, and `sw a0,60(sp)` at word 10 -- the parameter spilled to the frame
   because four loop-derived pointers (0x340/0x2c8/0x304/0x37c) stayed live across the calls.
   Replacing them with one `int *p`, rebound immediately before each use, frees the register:
   the stream now opens `move s7,a0` where retail has `move s5,a0`, and the prologue matches
   retail word for word. Net cost one word; differ fell 12. Remaining difference is the
   callee-saved register the allocator picks (s7 vs s5), which the source does not name. */
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

extern void FUN_000ffb3c();
extern void FUN_0010b980();
extern undefined4 FUN_0019d474();

void FUN_001a9f74(int param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *p;
  int iVar10;
  uint uVar11;
  
  iVar1 = FUN_0019d474();
  uVar2 = *(uint *)(iVar1 + 700);
  iVar1 = FUN_0019d474();
  iVar3 = FUN_0019d474();
  uVar11 = 0;
  iVar10 = 0;
  do {
    if (uVar11 < *(uint *)(iVar1 + 0x358)) {
      p = (int *)(param_1 + iVar10 + 0x304);
      FUN_000ffb3c(*p,0);
      p = (int *)(param_1 + iVar10 + 0x37c);
      FUN_000ffb3c(*p,0);
      iVar4 = uVar11 * 4;
      iVar5 = *(int *)(*(int *)(iVar3 + 0x348) + iVar4);
      if (iVar5 == 3) {
        p = (int *)(param_1 + iVar10 + 0x304);
        *(int *)(*p + 0x24) = *(int *)(*p + 0x28) + 2;
        p = (int *)(param_1 + iVar10 + 0x37c);
        *(undefined4 *)(*p + 0x24) = *(undefined4 *)(*p + 0x28);
LAB_001aa0b0:
        iVar5 = *(int *)(iVar1 + 0x354);
      }
      else {
        if (iVar5 == 2) {
          p = (int *)(param_1 + iVar10 + 0x304);
          *(int *)(*p + 0x24) = *(int *)(*p + 0x28) + 1;
          p = (int *)(param_1 + iVar10 + 0x37c);
          *(int *)(*p + 0x24) = *(int *)(*p + 0x28) + 1;
          goto LAB_001aa0b0;
        }
        if (iVar5 == 1) {
          p = (int *)(param_1 + iVar10 + 0x304);
          *(undefined4 *)(*p + 0x24) = *(undefined4 *)(*p + 0x28);
          p = (int *)(param_1 + iVar10 + 0x37c);
          *(int *)(*p + 0x24) = *(int *)(*p + 0x28) + 1;
          goto LAB_001aa0b0;
        }
        iVar5 = *(int *)(iVar1 + 0x354);
      }
      if (*(int *)(iVar5 + iVar4) == 0) {
        p = (int *)(param_1 + iVar10 + 0x340);
        FUN_000ffb3c(*p,1);
        p = (int *)(param_1 + iVar10 + 0x2c8);
        FUN_000ffb3c(*p,0);
      }
      else {
        if (uVar11 == uVar2) {
          if (*(int *)(*(int *)(iVar3 + 0x348) + iVar4) == 3) {
            p = (int *)(param_1 + iVar10 + 0x340);
            *(undefined4 *)(*p + 0x24) = *(undefined4 *)(*p + 0x28);
          }
          else {
            p = (int *)(param_1 + iVar10 + 0x340);
            *(int *)(*p + 0x24) = *(int *)(*p + 0x28) + 1;
          }
          p = (int *)(param_1 + iVar10 + 0x340);
          FUN_000ffb3c(*p,0);
          p = (int *)(param_1 + iVar10 + 0x2c8);
          uVar6 = *p;
        }
        else {
          p = (int *)(param_1 + iVar10 + 0x340);
          FUN_000ffb3c(*p,1);
          p = (int *)(param_1 + iVar10 + 0x2c8);
          uVar6 = *p;
        }
        FUN_000ffb3c(uVar6,1);
      }
    }
    else {
      p = (int *)(param_1 + iVar10 + 0x340);
      FUN_000ffb3c(*p,1);
      p = (int *)(param_1 + iVar10 + 0x2c8);
      FUN_000ffb3c(*p,1);
      p = (int *)(param_1 + iVar10 + 0x304);
      FUN_000ffb3c(*p,1);
      p = (int *)(param_1 + iVar10 + 0x37c);
      FUN_000ffb3c(*p,1);
    }
    uVar11 = uVar11 + 1;
    iVar10 = iVar10 + 0x14;
    if (2 < (int)uVar11) {
      FUN_0010b980(*(undefined4 *)(param_1 + 0x3fc),uVar2,0);
      return;
    }
  } while( true );
}
// near miss from lane fm9 (unreviewed)
// improved by lane fm10 (unreviewed): 131 -> 119 differing words

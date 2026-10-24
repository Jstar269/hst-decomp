/* HSTMATCH module=EBOOT.BIN start=0x002628b4 end=0x00262c14 symbol=FUN_002628b4 lang=c99 */
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

extern undefined * DAT_00338ac4;
extern undefined4 DAT_003415ac;
extern undefined DAT_0034179c;
extern int FUN_000bbba4();
extern void FUN_00103628();
extern void FUN_0010b6d4();
extern void FUN_0010b8cc();
extern void FUN_00114168();
extern undefined1 * FUN_0018c9f4(int, int);
extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;
extern void FUN_00114168(int, int, char *, int, int);
extern int FUN_001b1c44();

void FUN_002628b4(int param_1, undefined4 param_2)
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  *(undefined4 *)(param_1 + 0x1854) = param_2;
  *(undefined4 *)(param_1 + 0x1858) = 0;
  iVar5 = *(int *)(param_1 + 0x1854);
  switch (iVar5) {
  case 0:
      FUN_00103628(DAT_003415ac);
      bVar2 = true;
      if ((DAT_00338ac4 != 0) && (*(char *)(DAT_00338ac4 + 0x178) == '\0')) {
        bVar2 = false;
      }
      if (bVar2) {
        piVar6 = *(int **)(param_1 + 0x58);
      }
      else {
        iVar5 = 4;
        if (*(int *)(*(int *)(param_1 + 0x640) + 0x80) == 1) {
          iVar5 = 3;
        }
        iVar11 = 0;
        if (iVar5 != 0) {
          iVar10 = 0;
          iVar9 = param_1;
          do {
            iVar8 = *(int *)(param_1 + 0x640);
            bVar2 = false;
            iVar3 = FUN_000bbba4(DAT_00338ac4,(byte *)(DAT_00338ac4 + 0x3e));
            iVar4 = FUN_000bbba4(DAT_00338ac4,(byte *)(DAT_00338ac4 + 0x3e));
            if (*(int *)(iVar8 + iVar4 * 0x458 + iVar10 + 0x940) == *(int *)(DAT_00338ac4 + 0x198))
            {
              bVar1 = false;
            }
            else {
              bVar1 = -1 < *(int *)(iVar8 + iVar3 * 0x458 + iVar10 + 0x940);
            }
            if ((!bVar1) && (*(int *)(iVar9 + 0x520) == 3)) {
              bVar2 = true;
            }
            if (bVar2) {
              FUN_0010b8cc(*(int *)(param_1 + 0x58),iVar11,2);
              break;
            }
            iVar11 = iVar11 + 1;
            iVar10 = iVar10 + 4;
            iVar9 = iVar9 + 4;
          } while (iVar11 < iVar5);
        }
        piVar6 = *(int **)(param_1 + 0x58);
      }
      (**(code **)(*piVar6 + 0xc))(piVar6,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 0x44))();
      *(undefined1 *)(*(int *)(param_1 + 0x58) + 0xe8) = 0;
      if (*(int *)(*(int *)(param_1 + 0x640) + 0x80) == 1) {
        FUN_0010b6d4(*(int *)(param_1 + 0x58),0,2);
      }
  break;
  case 1:
      *(undefined4 *)(*(int *)(param_1 + 0x640) + 0x4f8) = 0xffffffff;
      (**(code **)(**(int **)(param_1 + 0x58) + 0xc))(*(int *)(param_1 + 0x58), 1);
      FUN_0018c9f4(0x11,1);
      {
        int obj = *(int *)(param_1 + 0x640);
        char *msg;
        if (*(int *)(obj + 4) == 0) {
          msg = &DAT_002c0e20;
        }
        else {
          int v1 = *(int *)(*(int *)(obj + 8) + 8);
          if (v1 < 17) {
            msg = &DAT_002c0e1c;
          }
          else {
            int v0 = *(int *)(v1 + 0xc4);
            if (v0 < 11) {
              msg = &DAT_002c0e18;
            }
            else {
              msg = (char *)*(int *)(v0 + 0x28);
            }
          }
        }
        FUN_00114168(DAT_003415ac, 2, msg, 0, 0);
      }
  break;
  case 2:
    FUN_001b1c44((int *)&DAT_0034179c,5);
    *(undefined4 *)(*(int *)(param_1 + 0x640) + 0x4f8) = 0xffffffff;
    uVar7 = 1;
    (**(code **)(**(int **)(param_1 + 0x58) + 0xc))();
    FUN_0018c9f4(0x11,5);
    FUN_00114168(DAT_003415ac, 0, (char *)*(int *)(*(int *)(param_1 + 0x640) + 0x24), 0, 0);
  break;
  }
  return;
}

// NEAR MISS 0x002628b4: 191/216 words, 212 differing (was 183/216 with 211 differing and six invented
// parameters). Rewritten to retail's two-argument signature `(int param_1, int param_2)`; the six extra
// params had been contributing ~18 words of argument moves, so the signature change alone measured 165/216
// before the rest of the rewrite went in. Case 1 now stores retail's `-1` into `+0x4f8` (it previously
// stored `*(param_1+0x58)+0xdc`) and carries the message-select tail: `obj->f4 == 0` -> DAT_002c0e20;
// otherwise `*(*(obj+8)+8) < 17` -> DAT_002c0e1c, else `*(v1+0xc4) < 11` -> DAT_002c0e18, else
// `*(v0+0x28)`, feeding `FUN_00114168(DAT_003415ac, 2, msg, 0, 0)`. Remaining gap 25 words lives in the
// dispatch ladder: retail keeps every arm out of line as `beql a0,2 / li a1,1 / beql a0,1 / beqzl a0`.
// near miss from lane fm10 (unreviewed)

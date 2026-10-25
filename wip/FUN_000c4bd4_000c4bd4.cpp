/* HSTMATCH module=EBOOT.BIN start=0x000c4bd4 end=0x000c4eb8 symbol=FUN_000c4bd4 lang=c99 */
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

extern "C" {
extern undefined DAT_002d5b08;
extern undefined * DAT_00338ac4;
extern undefined DAT_00338af4;
extern undefined1 DAT_003417b8;
extern void * FUN_00000bcc(int);
extern void FUN_000bd378(void *, void *, int);
extern void FUN_000bd480(void *, int, void *, int);
extern void FUN_000c4a24(void *);
extern undefined4 * FUN_00285f28(void *);
}

extern "C" void FUN_000c4bd4(int param_1)
{
  bool bVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  uint iVar9;
  int *piVar8;
  int *piVar7;
  int iVar6;
  int iVar5;
  int iVar4;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  
  puVar2 = (undefined4 *)FUN_00000bcc(200);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = FUN_00285f28(puVar2);
  }
  *(undefined4 **)(param_1 + 0x784) = puVar2;
  FUN_000c4a24((void *)param_1);
  *(undefined4 *)(param_1 + 0x780) = 1;
  iVar12 = *(int *)(DAT_00338ac4 + 0x198);
  if (DAT_003417b8 == '\0') {
    iVar11 = 2;
  }
  else {
    iVar11 = 4;
  }
  iVar5 = 0;
  if (iVar11 > 0) {
    iVar9 = 0;
    piVar8 = (int *)&DAT_00338af4;
    piVar7 = (int *)(&DAT_002d5b08);
    do {
      if (*(unsigned char *)(DAT_00338ac4 + iVar9 + 0x5e) != '\0') {
        if (iVar5 == iVar12) {
          iVar6 = *piVar8;
          puVar10 = (undefined1 *)(param_1 + *piVar7 * 0x1d0 + 0x40);
          FUN_000bd378(DAT_00338ac4,puVar10,iVar6 * 0x1d0);
          iVar4 = 0;
          if (iVar6 < 1) goto LAB_000c4e74;
          if (iVar6 < 9) {
LAB_000c4d44:
            bVar1 = iVar4 < iVar6;
          }
          else {
            bVar1 = false;
            if ((-1 < iVar6) && (iVar6 < 0x7fffffff)) {
              bVar1 = true;
            }
            puVar3 = puVar10;
            if (bVar1) {
              do {
                *puVar3 = 1;
                puVar3[0x1d0] = 1;
                puVar3[0x3a0] = 1;
                puVar3[0x570] = 1;
                puVar3[0x740] = 1;
                puVar3[0x910] = 1;
                puVar3[0xae0] = 1;
                iVar4 = iVar4 + 8;
                puVar3[0xcb0] = 1;
                puVar3 = puVar3 + 0xe80;
              } while (iVar4 < iVar6 + -8);
              goto LAB_000c4d44;
            }
            bVar1 = 0 < iVar6;
          }
          if (bVar1) {
            puVar10 = puVar10 + iVar4 * 0x1d0;
            do {
              iVar4 = iVar4 + 1;
              *puVar10 = 1;
              puVar10 = puVar10 + 0x1d0;
            } while (iVar4 < iVar6);
          }
        }
        else {
          iVar6 = *piVar8;
          puVar10 = (undefined1 *)(param_1 + *piVar7 * 0x1d0 + 0x40);
          FUN_000bd480(DAT_00338ac4,iVar5,puVar10,iVar6 * 0x1d0);
          iVar4 = 0;
          if (iVar6 < 1) goto LAB_000c4e74;
          if (iVar6 < 9) {
LAB_000c4e38:
            bVar1 = iVar4 < iVar6;
          }
          else {
            bVar1 = false;
            if ((-1 < iVar6) && (iVar6 < 0x7fffffff)) {
              bVar1 = true;
            }
            puVar3 = puVar10;
            if (bVar1) {
              do {
                *puVar3 = 0;
                puVar3[0x1d0] = 0;
                puVar3[0x3a0] = 0;
                puVar3[0x570] = 0;
                puVar3[0x740] = 0;
                puVar3[0x910] = 0;
                puVar3[0xae0] = 0;
                iVar4 = iVar4 + 8;
                puVar3[0xcb0] = 0;
                puVar3 = puVar3 + 0xe80;
              } while (iVar4 < iVar6 + -8);
              goto LAB_000c4e38;
            }
            bVar1 = 0 < iVar6;
          }
          if (bVar1) {
            puVar10 = puVar10 + iVar4 * 0x1d0;
            do {
              iVar4 = iVar4 + 1;
              *puVar10 = 0;
              puVar10 = puVar10 + 0x1d0;
            } while (iVar4 < iVar6);
          }
        }
      }
LAB_000c4e74:
      iVar5 = iVar5 + 1;
      iVar9 = iVar9 + 7;
      piVar8 = piVar8 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar5 < iVar11);
  }
  return;
}
// Near miss: 140 differing words remain; retail prologue, allocation/null branch, bool global load, and helper call setup are close.
// Remaining differences are concentrated in saved-register mapping and the long strided byte-clear loops.
// Tried GCC 171/131 O1, O2, O3, and Os profiles, MWCC, signedness, loop condition, declaration order, and typed helper prototypes.
// near miss from lane km5 (unreviewed)

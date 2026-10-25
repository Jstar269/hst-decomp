/* HSTMATCH module=EBOOT.BIN start=0x001ad89c end=0x001ade94 symbol=FUN_001ad89c lang=c99 */
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
extern void FUN_0010d4a8();
extern undefined4 FUN_0016bb7c();
extern undefined4 FUN_0019d474();
extern undefined * FUN_001fea10();

void FUN_001ad89c(int param_1,char param_2)
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  
  iVar2 = FUN_0019d474();
  iVar2 = *(int *)(iVar2 + 0x314);
  iVar3 = FUN_0019d474();
  piVar12 = (int *)(iVar3 + 0x318);
  iVar11 = 0;
  iVar10 = 0;
  iVar9 = 0x59;
  iVar3 = 0x5a;
  do {
    piVar14 = (int *)(param_1 + iVar10 + 0x768);
    puVar5 = (undefined4 *)(param_1 + iVar9 * 0x14 + 0x24);
    puVar7 = (undefined4 *)(param_1 + iVar3 * 0x14 + 0x24);
    puVar13 = (undefined4 *)(param_1 + iVar10 + 0x790);
    if (param_2 == '\0') {
      FUN_000ffb3c(*puVar5,1);
      FUN_000ffb3c(*puVar7,1);
      FUN_000ffb3c(*puVar13,1);
LAB_001ada10:
      iVar6 = *piVar14;
    }
    else {
      if (iVar2 != iVar11) {
        FUN_000ffb3c(*puVar5,1);
        FUN_000ffb3c(*puVar7,1);
        FUN_000ffb3c(*puVar13,1);
        goto LAB_001ada10;
      }
      if (*piVar12 < 1) {
        FUN_000ffb3c(*puVar5,0);
        FUN_000ffb3c(*puVar7,1);
        uVar4 = *puVar13;
      }
      else {
        if (*piVar12 < 2) {
          FUN_000ffb3c(*puVar5,0);
          FUN_000ffb3c(*puVar7,0);
        }
        else {
          FUN_000ffb3c(*puVar5,1);
          FUN_000ffb3c(*puVar7,0);
        }
        uVar4 = *puVar13;
      }
      FUN_000ffb3c(uVar4,0);
      iVar6 = *piVar14;
    }
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 0x14;
    iVar9 = iVar9 + 2;
    *(int *)(iVar6 + 0x24) = *(int *)(iVar6 + 0x28) + *piVar12;
    iVar3 = iVar3 + 2;
    piVar12 = piVar12 + 1;
    if (1 < iVar11) {
      iVar3 = FUN_0019d474();
      iVar10 = 7;
      iVar9 = param_1 + 0x54;
      do {
        (**(code **)(**(int **)(iVar9 + 0x870) + 0xc))(*(int **)(iVar9 + 0x870),1);
        iVar10 = iVar10 + 1;
        iVar9 = iVar9 + 0xc;
      } while (iVar10 < 0xd);
      if ((*(char *)(iVar3 + 0x11c) == '\x04') || (*(char *)(iVar3 + 0x11c) == '\0')) {
        iVar9 = 0;
        iVar3 = 0;
        do {
          iVar10 = FUN_0019d474();
          iVar10 = *(int *)(iVar10 + 0x160) + iVar9 * 0x30;
          cVar1 = *(char *)(iVar10 + 10);
          if ((iVar9 == 0) || (iVar9 == 2)) {
            if (iVar9 == 0) {
              iVar11 = param_1 + 0x8c0;
            }
            else {
              iVar11 = param_1 + 0x8cc;
            }
            (**(code **)(**(int **)(iVar11 + 4) + 0xc))(*(int **)(iVar11 + 4),0);
            iVar6 = FUN_0019d474();
            if (*(char *)(*(int *)(iVar6 + 0x88) + iVar9 + 0x10) == '\0') {
              uVar4 = (unsigned int)(FUN_001fea10(0x13,0,0));
              iVar10 = *(int *)(iVar11 + 4);
              *(undefined4 *)(iVar10 + 0xf8) = uVar4;
              *(undefined4 *)(iVar10 + 0x138) = 0;
              FUN_0010d4a8();
            }
            else if (cVar1 == '\0') {
              iVar6 = FUN_0019d474();
              iVar6 = *(int *)(iVar6 + iVar3 + 0x3a4);
              if (iVar6 == 3) {
                iVar11 = *(int *)(iVar11 + 4);
                *(int *)(iVar11 + 0xf8) = iVar10 + 0x10;
                *(undefined4 *)(iVar11 + 0x138) = 0;
                FUN_0010d4a8();
              }
              else if (iVar6 == 2) {
                iVar10 = FUN_0019d474();
                uVar4 = (unsigned int)(FUN_001fea10(0xc,0,(int)**(short **)(iVar10 + iVar3 + 0x3b4)));
                iVar10 = *(int *)(iVar11 + 4);
                *(undefined4 *)(iVar10 + 0xf8) = uVar4;
                *(undefined4 *)(iVar10 + 0x138) = 0;
                FUN_0010d4a8();
              }
              else if (iVar6 == 1) {
                iVar10 = FUN_0019d474();
                uVar4 = (unsigned int)(FUN_001fea10(7,0,(int)**(short **)(iVar10 + iVar3 + 0x3b4)));
                iVar10 = *(int *)(iVar11 + 4);
                *(undefined4 *)(iVar10 + 0xf8) = uVar4;
                *(undefined4 *)(iVar10 + 0x138) = 0;
                FUN_0010d4a8();
              }
              else if (iVar6 == 0) {
                iVar10 = FUN_0016bb7c();
                iVar11 = *(int *)(iVar11 + 4);
                *(int *)(iVar11 + 0xf8) = iVar10 + 0x20;
                *(undefined4 *)(iVar11 + 0x138) = 0;
                FUN_0010d4a8();
              }
            }
            else {
              uVar4 = (unsigned int)(FUN_001fea10(0x13,0,0));
              iVar10 = *(int *)(iVar11 + 4);
              *(undefined4 *)(iVar10 + 0xf8) = uVar4;
              *(undefined4 *)(iVar10 + 0x138) = 0;
              FUN_0010d4a8();
            }
          }
          iVar9 = iVar9 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar9 < 4);
      }
      else {
        iVar10 = 0;
        iVar9 = 0;
        iVar3 = 0;
        do {
          iVar11 = param_1 + iVar9;
          iVar6 = FUN_0019d474();
          iVar8 = *(int *)(iVar6 + 0x160) + iVar10 * 0x30;
          cVar1 = *(char *)(iVar8 + 10);
          (**(code **)(**(int **)(iVar11 + 0x8dc) + 0xc))(*(int **)(iVar11 + 0x8dc),0);
          iVar6 = FUN_0019d474();
          if (*(char *)(*(int *)(iVar6 + 0x88) + iVar10 + 0x10) == '\0') {
            uVar4 = (unsigned int)(FUN_001fea10(0x13,0,0));
            iVar11 = *(int *)(iVar11 + 0x8dc);
            *(undefined4 *)(iVar11 + 0xf8) = uVar4;
            *(undefined4 *)(iVar11 + 0x138) = 0;
            FUN_0010d4a8();
          }
          else if (cVar1 == '\0') {
            iVar6 = FUN_0019d474();
            iVar6 = *(int *)(iVar6 + iVar3 + 0x3a4);
            if (iVar6 == 3) {
              iVar11 = *(int *)(iVar11 + 0x8dc);
              *(int *)(iVar11 + 0xf8) = iVar8 + 0x10;
              *(undefined4 *)(iVar11 + 0x138) = 0;
              FUN_0010d4a8();
            }
            else if (iVar6 == 2) {
              iVar6 = FUN_0019d474();
              uVar4 = (unsigned int)(FUN_001fea10(0xc,0,(int)**(short **)(iVar6 + iVar3 + 0x3b4)));
              iVar11 = *(int *)(iVar11 + 0x8dc);
              *(undefined4 *)(iVar11 + 0xf8) = uVar4;
              *(undefined4 *)(iVar11 + 0x138) = 0;
              FUN_0010d4a8();
            }
            else if (iVar6 == 1) {
              iVar6 = FUN_0019d474();
              uVar4 = (unsigned int)(FUN_001fea10(7,0,(int)**(short **)(iVar6 + iVar3 + 0x3b4)));
              iVar11 = *(int *)(iVar11 + 0x8dc);
              *(undefined4 *)(iVar11 + 0xf8) = uVar4;
              *(undefined4 *)(iVar11 + 0x138) = 0;
              FUN_0010d4a8();
            }
            else if (iVar6 == 0) {
              iVar6 = FUN_0016bb7c();
              iVar11 = *(int *)(iVar11 + 0x8dc);
              *(int *)(iVar11 + 0xf8) = iVar6 + 0x20;
              *(undefined4 *)(iVar11 + 0x138) = 0;
              FUN_0010d4a8();
            }
          }
          else {
            uVar4 = (unsigned int)(FUN_001fea10(0x13,0,0));
            iVar11 = *(int *)(iVar11 + 0x8dc);
            *(undefined4 *)(iVar11 + 0xf8) = uVar4;
            *(undefined4 *)(iVar11 + 0x138) = 0;
            FUN_0010d4a8();
          }
          iVar10 = iVar10 + 1;
          iVar9 = iVar9 + 0xc;
          iVar3 = iVar3 + 4;
        } while (iVar10 < 4);
      }
      if (param_2 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x914) + 0xc))(*(int **)(param_1 + 0x914),0);
        FUN_0010b980(*(undefined4 *)(param_1 + 0x914),iVar2,0);
      }
      return;
    }
  } while( true );
}
// near miss from lane fm11 (unreviewed)

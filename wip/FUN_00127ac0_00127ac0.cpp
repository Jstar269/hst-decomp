/* HSTMATCH module=EBOOT.BIN start=0x00127ac0 end=0x00127d5c symbol=FUN_00127ac0 lang=c99 */
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

extern int DAT_0033b4b0;
extern int DAT_0033b564;
extern int DAT_0033b56c;
extern int DAT_0033b570;
extern "C" void FUN_0012b2b0(float, void *, int, int);
extern "C" int FUN_0012b72c(void *, void *, int);

extern "C" void FUN_00127ac0(char *param_1,unsigned char param_2)
{
  int iVar1;
  bool bVar8;
  bool bVar7;
  bool bVar6;
  bool bVar5;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar9;
  
    if (param_2 != *(unsigned char *)(param_1 + 0x338)) {
    *(unsigned char *)(param_1 + 0x338) = param_2;
    if (*(unsigned char *)(param_1 + 0x338) == '\0') {
      int currentTime = *(int *)(param_1 + 0x334);
      int atOrAfterLower = (currentTime < DAT_0033b564) ^ 1;
      if (atOrAfterLower != 0) {
        if (currentTime > DAT_0033b570)
          return;
      }
      {
        iVar2 = -1;
        *(undefined4 *)(param_1 + 0x334) = 0xffffffff;
        char *object1 = *(char **)(param_1 + 0x58);
        if (object1 != 0) {
          iVar2 = *(int *)(object1 + 0xf0);
          iVar9 = *(int *)(object1 + 0x110);
        }
        bVar8 = true;
        bVar6 = true;
        iVar1 = FUN_0012b72c(param_1,(void *)*(undefined4 *)(param_1 + 0x35c),0);
        int currentIndex = *(int *)(param_1 + 0x354) + iVar1 * 2;
        char *object2 = *(char **)(param_1 + 0x58);
        iVar3 = -1;
        if (object2 != 0) {
          iVar3 = *(int *)(object2 + 0xf0);
        }
        bVar7 = true;
        iVar1 = DAT_0033b4b0 + currentIndex;
        bVar5 = false;
        if ((iVar3 == iVar1) && (*(int *)(object2 + 0x110) < 0)) {
          bVar5 = true;
        }
        if ((!bVar5) && (*(int *)(object2 + 0x110) != iVar1)) {
          bVar7 = false;
        }
        if ((!bVar7) && ((iVar2 < DAT_0033b564 || DAT_0033b570 < iVar2) || -1 < iVar9)) {
          bVar6 = false;
        }
        if ((!bVar6) && (iVar9 < DAT_0033b564 || DAT_0033b570 < iVar9)) {
          bVar8 = false;
        }
        if (bVar8) {
          FUN_0012b2b0(-1.0f,param_1,1,1);
        }
      }
    }
    else if (*(int *)(param_1 + 0x334) < 0) {
      iVar1 = FUN_0012b72c(param_1,(void *)*(undefined4 *)(param_1 + 0x35c),0);
      if (iVar1 == 3) {
        iVar1 = DAT_0033b56c + *(int *)(param_1 + 0x354);
      }
      else {
        iVar1 = DAT_0033b564 + *(int *)(param_1 + 0x354);
      }
      *(int *)(param_1 + 0x334) = iVar1;
      iVar1 = FUN_0012b72c(param_1,(void *)*(undefined4 *)(param_1 + 0x35c),0);
      iVar2 = *(int *)(param_1 + 0x58);
      if (iVar2 == 0) {
        iVar4 = -1;
      }
      else {
        iVar4 = *(int *)(iVar2 + 0xf0);
      }
      bVar8 = true;
      iVar1 = DAT_0033b4b0 + *(int *)(param_1 + 0x354) + iVar1 * 2;
      bVar6 = false;
      if ((iVar4 == iVar1) && (*(int *)(iVar2 + 0x110) < 0)) {
        bVar6 = true;
      }
      if ((!bVar6) && (*(int *)(iVar2 + 0x110) != iVar1)) {
        bVar8 = false;
      }
      if (bVar8) {
        FUN_0012b2b0(-1.0f,param_1,1,1);
      }
    }
  }
  return;
}
// Near miss: 143 differing words remain; retail prologue, unsigned state loads, and initial signed-bound comparisons are represented.
// Remaining differences include branch layout, object-field/call-argument scheduling, and saved-register control flow.
// Tried signed global bounds, explicit inverted comparisons, declaration-order permutations, typed object pointers, and reordered address arithmetic.
// near miss from lane km5 (unreviewed)

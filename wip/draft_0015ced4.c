/* HSTMATCH module=EBOOT.BIN start=0x0015ced4 end=0x0015d0f0 symbol=FUN_0015ced4 lang=c99 */
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

extern undefined DAT_0034040c;
extern undefined DAT_0034080c;
extern undefined DAT_00340c0c;
extern undefined DAT_0034110c;
extern int FUN_0015cce8();

void FUN_0015ced4(undefined4 param_1)
{
  char *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  
  if (DAT_0034110c == '\0') {
    DAT_0034110c = '\x01';
    iVar9 = 0;
    piVar8 = (int *)&DAT_0034040c;
    puVar7 = (undefined4 *)&DAT_00340c0c;
    puVar6 = (undefined4 *)&DAT_0034080c;
    do {
      pcVar1 = (char *)FUN_0015cce8(param_1,iVar9);
      if ((pcVar1 == (char *)0x0) || (*pcVar1 < '\0')) {
        *piVar8 = 0x101;
        *puVar7 = 9999;
      }
      else {
        *piVar8 = iVar9;
        *puVar7 = *(undefined4 *)(pcVar1 + 0x24);
      }
      iVar9 = iVar9 + 1;
      *puVar6 = 0;
      piVar8 = piVar8 + 1;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar9 < 0x100);
    piVar8 = (int *)&DAT_00340c0c;
    puVar6 = (undefined4 *)&DAT_0034040c;
    iVar9 = 0;
    do {
      iVar5 = iVar9 + 1;
      if (iVar5 < 0x100) {
        piVar3 = (int *)(&DAT_00340c0c + iVar5 * 4);
        puVar7 = (undefined4 *)(&DAT_0034040c + iVar5 * 4);
        do {
          iVar4 = *piVar8;
          if (*piVar3 < iVar4) {
            *piVar8 = *piVar3;
            *piVar3 = iVar4;
            uVar2 = *puVar6;
            *puVar6 = *puVar7;
            *puVar7 = uVar2;
          }
          iVar5 = iVar5 + 1;
          piVar3 = piVar3 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar5 < 0x100);
      }
      iVar9 = iVar9 + 1;
      piVar8 = piVar8 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar9 < 0x100);
    iVar9 = 0;
    piVar8 = (int *)&DAT_0034040c;
    do {
      iVar5 = piVar8[1];
      *(int *)(&DAT_0034080c + *piVar8 * 4) = iVar9 + 1;
      iVar4 = piVar8[2];
      *(int *)(&DAT_0034080c + iVar5 * 4) = iVar9 + 2;
      iVar5 = piVar8[3];
      *(int *)(&DAT_0034080c + iVar4 * 4) = iVar9 + 3;
      iVar4 = piVar8[4];
      *(int *)(&DAT_0034080c + iVar5 * 4) = iVar9 + 4;
      iVar5 = piVar8[5];
      *(int *)(&DAT_0034080c + iVar4 * 4) = iVar9 + 5;
      *(int *)(&DAT_0034080c + iVar5 * 4) = iVar9 + 6;
      iVar5 = piVar8[7];
      iVar4 = iVar9 + 7;
      iVar9 = iVar9 + 8;
      *(int *)(&DAT_0034080c + piVar8[6] * 4) = iVar4;
      *(int *)(&DAT_0034080c + iVar5 * 4) = iVar9;
      piVar8 = piVar8 + 8;
    } while (iVar9 < 0x100);
  }
  return;
}
// near miss from lane fm9 (unreviewed)

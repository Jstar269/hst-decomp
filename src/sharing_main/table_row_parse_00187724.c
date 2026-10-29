/* HSTMATCH module=hstp_trans_main.prx start=0x00187724 end=0x00187954 symbol=FUN_00187724 lang=c99 */
/* Clone of src/eboot/table_row_parse_0017b030.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: FUN_000660f0 returns float (no int-to-float casts), opt_strength_reduction off, stores use (offset & ~3), locals declared outer index, offset, inner index; exact match verified; names and types await human review. */
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

#pragma opt_strength_reduction off
extern undefined DAT_00387ccc;
extern char * FUN_00014b74();
extern undefined4 FUN_00065fac();
extern int FUN_00066038();
extern float FUN_000660f0();
extern int FUN_000661a8();
extern undefined4 FUN_00066260();

void FUN_00187724(int param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar11;
  int iVar10;
  int iVar9;
  float fVar12;
  float fVar13;
  float fVar14;
  
  FUN_00066260(param_2,param_3,0,0,&DAT_00387ccc);
  iVar2 = FUN_00065fac(param_2,0);
  uVar11 = 0;
  if (param_5 != 0) {
    do {
      iVar10 = 0;
      iVar9 = 1;
      iVar8 = param_1 + param_4 * uVar11;
      if (1 < iVar2) {
        do {
          FUN_000661a8(param_2,0,iVar9);
          pcVar3 = (char *)FUN_000661a8(param_2,1,iVar9);
          cVar1 = *pcVar3;
          if (cVar1 == 'f') {
            fVar12 = FUN_000660f0(param_2,uVar11 + 4,iVar9);
            fVar13 = FUN_000660f0(param_2,2,iVar9);
            fVar14 = FUN_000660f0(param_2,3,iVar9);
            if ((fVar13 <= fVar12) && (fVar12 <= fVar14)) {
              *(float *)(iVar8 + (iVar10 & ~3)) = fVar12;
              iVar10 = iVar10 + 4;
            }
          }
          else if (cVar1 == 'i') {
            iVar4 = FUN_00066038(param_2,uVar11 + 4,iVar9);
            iVar5 = FUN_00066038(param_2,2,iVar9);
            iVar6 = FUN_00066038(param_2,3,iVar9);
            if ((iVar5 <= iVar4) && (iVar4 <= iVar6)) {
              *(int *)(iVar8 + (iVar10 & ~3)) = iVar4;
              iVar10 = iVar10 + 4;
            }
          }
          else if (cVar1 == 's') {
            uVar7 = FUN_000661a8(param_2,uVar11 + 4,iVar9);
            FUN_00014b74(iVar8 + iVar10,uVar7,0x20);
            iVar10 = iVar10 + 8;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar2);
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < param_5);
  }
  return;
}

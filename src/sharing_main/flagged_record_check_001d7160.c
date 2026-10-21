/* HSTMATCH module=hstp_trans_main.prx start=0x001d7160 end=0x001d725c symbol=FUN_001d7160 lang=c99 */
/* Clone of src/eboot/flagged_record_check_001c8ccc.c (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: one result variable that the loop sets to 0 and leaves with `break`, no else branch (earlier early `return 0` and `else { r = 0; }` forms moved the joins); exact match verified; names and types await human review. */
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

extern undefined * DAT_003e48b4;
extern int FUN_00157d48();
extern int FUN_0019f8d4();
extern undefined4 FUN_0019f9ac();
extern int FUN_0023a6f8();

undefined4 FUN_001d7160(void)
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = 0;
  bVar1 = false;
  if ((DAT_003e48b4 != 0) &&
     (piVar2 = (int *)FUN_00157d48(*(undefined4 *)(DAT_003e48b4 + 0x1324),0xbe), *piVar2 >= 2)) {
    bVar1 = true;
  }
  if (bVar1) {
    bVar1 = false;
    if ((DAT_003e48b4 != 0) &&
       (piVar2 = (int *)FUN_00157d48(*(undefined4 *)(DAT_003e48b4 + 0x1324),0xbf), *piVar2 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar4 = 1;
      iVar5 = 0;
      iVar3 = FUN_0019f9ac();
      if (0 < iVar3) {
        do {
          iVar3 = FUN_0019f8d4(iVar5);
          if (((iVar3 != 0) && (*(char *)(iVar3 + 0x2f) != '\0')) &&
             (iVar3 = FUN_0023a6f8((int)*(short *)(iVar3 + 0x36),(int)*(short *)(iVar3 + 0x38)),
             iVar3 == 0)) {
            uVar4 = 0;
            break;
          }
          iVar5 = iVar5 + 1;
          iVar3 = FUN_0019f9ac();
        } while (iVar5 < iVar3);
      }
    }
  }
  return uVar4;
}

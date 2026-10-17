/* HSTMATCH module=hstp_trans_main.prx start=0x001c1d9c end=0x001c1ec4 symbol=FUN_001c1d9c lang=c99 */
/* Clone of src/eboot/FUN_001b3a0c.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: combined the range and slot-present tests and stored the incoming mode value; exact match verified; names and types await human review. */
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

extern int FUN_00063304();
extern void FUN_001be964();

void FUN_001c1d9c(int *param_1,int param_2,int param_3)
{
  int bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *param_1;
  if ((*(int *)(iVar3 + 0x7a4) >= 0) && (param_3 != 0)) {
    iVar2 = *(int *)(iVar3 + 0x7a4) + 0x28;
    bVar1 = (iVar2 < 0x1da) && (*(int *)(iVar3 + iVar2 * 4) != 0);
    if (bVar1) {
      piVar4 = (int *)(iVar3 + iVar2 * 4);
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        FUN_00063304(iVar2,1);
        *piVar4 = 0;
      }
    }
  }
  FUN_001be964(iVar3,param_2 + 0x28,param_3,0,0);
  FUN_001be964(iVar3,param_2 + 0x84,0,0,0);
  if (param_2 == 6) {
    FUN_001be964(iVar3,0x81,0,0,0);
    *(undefined4 *)(iVar3 + 0x7a4) = param_2;
  }
  else {
    FUN_001be964(iVar3,param_2 * 2 + 0x98,0,0,0);
    FUN_001be964(iVar3,param_2 * 2 + 0x99,0,0,0);
    *(int *)(iVar3 + 0x7a4) = param_2;
  }
  return;
}

/* HSTMATCH module=EBOOT.BIN start=0x0014dc3c end=0x0014dd38 symbol=FUN_0014dc3c lang=c99 rodata=0x002c1a00 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern undefined DAT_003402f4;
extern undefined DAT_00340374;
extern int FUN_0022a940();
extern undefined * FUN_0022a958();
extern int FUN_0022a970();
extern int FUN_0022a98c();

int FUN_0014dc3c(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  
  iVar1 = 0;
  switch(*(undefined4 *)(param_1 + 8)) {
  case 0:
    piVar2 = (int *)FUN_0022a940(*(int *)(param_1 + 0xc));
    iVar1 = *piVar2;
    break;
  case 1:
    pfVar3 = (float *)FUN_0022a958(*(int *)(param_1 + 0xc));
    iVar1 = (int)*pfVar3;
    break;
  case 2:
    piVar2 = (int *)FUN_0022a970(*(int *)(param_1 + 0xc));
    iVar1 = *piVar2;
    break;
  case 3:
    pfVar3 = (float *)FUN_0022a98c(*(int *)(param_1 + 0xc));
    iVar1 = (int)*pfVar3;
    break;
  case 4:
    iVar1 = *(int *)(param_2 + *(int *)(param_1 + 0xc) * 4 + 0xc);
    break;
  case 5:
    iVar1 = (int)*(float *)(param_2 + *(int *)(param_1 + 0xc) * 4 + 0x10c);
    break;
  case 8:
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) * 4 + (int)&DAT_003402f4);
    break;
  case 9:
    iVar1 = (int)*(float *)(*(int *)(param_1 + 0xc) * 4 + (int)&DAT_00340374);
  }
  return iVar1;
}

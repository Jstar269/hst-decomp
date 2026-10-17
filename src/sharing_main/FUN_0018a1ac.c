/* HSTMATCH module=hstp_trans_main.prx start=0x0018a1ac end=0x0018a244 symbol=FUN_0018a1ac lang=c99 */
/* Clone of src/eboot/FUN_0017dab8.c (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a, variant v0) corrected by hand: if/else order inverted and the float product regrouped to the retail evaluation order; exact match verified; names and types await human review. */
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

extern int FUN_00177ea4();
extern int FUN_00212c68();

float FUN_0018a1ac(int param_1,int param_2)
{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  float fVar5;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x60);
  iVar4 = 0;
  if (iVar1 != 0) {
    iVar4 = *(int *)(iVar1 + 0x1b4);
  }
  if ((iVar4 >= 0) && (iVar4 <= 0xe)) {
    pfVar2 = (float *)FUN_00212c68();
    pfVar3 = (float *)FUN_00177ea4();
    fVar5 = *pfVar2 * (*(float *)(param_1 + 0x4c) * *pfVar3);
  }
  else {
    pfVar2 = (float *)FUN_00177ea4();
    fVar5 = *(float *)(param_1 + 0x4c) * *pfVar2;
  }
  return fVar5;
}

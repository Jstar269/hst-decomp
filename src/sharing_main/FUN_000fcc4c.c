/* HSTMATCH module=hstp_trans_main.prx start=0x000fcc4c end=0x000fcd74 symbol=FUN_000fcc4c lang=c99 */
/* Clone of src/eboot/FUN_000f7558.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0c) corrected by hand: typed helper arguments and reused the allocation result; exact match verified; names and types await human review. */
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

extern char DAT_0037ef90[];
extern char DAT_0037efc0[];
extern char DAT_0037efc8[];
extern char DAT_0037efd4[];
extern int FUN_00000bcc();
extern undefined4 * FUN_000fbaf4();
extern void FUN_000fbe68();
extern int FUN_00108124();
extern undefined4 * FUN_0010873c();
extern void FUN_00108e6c(float param_1,int param_2);
extern void FUN_001090f4(int param_1,int param_2);
extern int FUN_00109304();
extern void FUN_00109a44();

undefined4 * FUN_000fcc4c(undefined4 *param_1)
{
  undefined4 *puVar1;
  int iVar3;
  
  FUN_000fbaf4(param_1);
  puVar1 = (undefined4 *)FUN_00000bcc(0x54);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = FUN_0010873c(puVar1);
  }
  *param_1 = (unsigned int)(puVar1);
  FUN_00109a44((int)*param_1,(uint *)DAT_0037ef90,0);
  FUN_00108e6c(3099.0f,*param_1);
  FUN_001090f4(*param_1,-4096);
  FUN_00108e6c(3099.0f,*param_1);
  FUN_001090f4(*param_1,-4096);
  FUN_000fbe68((int)param_1,0xf);
  iVar3 = FUN_00109304(*param_1,(byte *)DAT_0037efc0,0);
  param_1[5] = iVar3;
  iVar3 = FUN_00108124(iVar3,(byte *)DAT_0037efc8);
  param_1[8] = *(undefined4 *)(iVar3 + 0x24);
  param_1[6] = iVar3;
  iVar3 = FUN_00108124(param_1[5],(byte *)DAT_0037efd4);
  param_1[9] = *(undefined4 *)(iVar3 + 0x24);
  param_1[7] = iVar3;
  param_1[0x20f] = 0x41a00000;
  param_1[0x210] = 0;
  param_1[0x211] = 0x40a00000;
  param_1[0x212] = 0x3f19999a;
  param_1[0x218] = 0x42800000;
  param_1[0x219] = 0x42800000;
  param_1[0x21a] = 0x42800000;
  param_1[0x21b] = 0x42800000;
  return param_1;
}




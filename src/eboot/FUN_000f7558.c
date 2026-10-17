/* HSTMATCH module=EBOOT.BIN start=0x000f7558 end=0x000f7680 symbol=FUN_000f7558 lang=c99 */
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

extern char DAT_002d81b8[];
extern char DAT_002d81e8[];
extern char DAT_002d81f0[];
extern char DAT_002d81fc[];
extern int FUN_00000bcc();
extern undefined4 * FUN_000f6400();
extern void FUN_000f6774();
extern int FUN_001026b8();
extern undefined4 * FUN_00102e38();
extern void FUN_00103540(float param_1,int param_2);
extern void FUN_001037c8(int param_1,int param_2);
extern int FUN_001039d8();
extern void FUN_00104118();

undefined4 * FUN_000f7558(undefined4 *param_1)
{
  undefined4 *puVar1;
  int iVar3;
  
  FUN_000f6400(param_1);
  puVar1 = (undefined4 *)FUN_00000bcc(0x54);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = FUN_00102e38(puVar1);
  }
  *param_1 = (unsigned int)(puVar1);
  FUN_00104118((int)*param_1,(uint *)DAT_002d81b8,0);
  FUN_00103540(3099.0f,*param_1);
  FUN_001037c8(*param_1,-4096);
  FUN_00103540(3099.0f,*param_1);
  FUN_001037c8(*param_1,-4096);
  FUN_000f6774((int)param_1,0xf);
  iVar3 = FUN_001039d8(*param_1,(byte *)DAT_002d81e8,0);
  param_1[5] = iVar3;
  iVar3 = FUN_001026b8(iVar3,(byte *)DAT_002d81f0);
  param_1[8] = *(undefined4 *)(iVar3 + 0x24);
  param_1[6] = iVar3;
  iVar3 = FUN_001026b8(param_1[5],(byte *)DAT_002d81fc);
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




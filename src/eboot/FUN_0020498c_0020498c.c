/* HSTMATCH module=EBOOT.BIN start=0x0020498c end=0x00204ac8 symbol=FUN_0020498c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: shared the allocation and table store across the null path and used a zeroed four-word local array; exact match verified; names and types await human review. */
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

extern undefined DAT_002bc410;
extern undefined DAT_0034b340;
extern int FUN_00000bcc();
extern undefined4 * FUN_00091830(void *);
extern void FUN_00093434();
extern void FUN_0009345c();
extern void FUN_00093484(float param_1,int param_2);

int * FUN_0020498c(int *param_1,int param_2,undefined1 param_3)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_values[4];
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 2) = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[1] = param_2;
  if (*(int *)(&DAT_0034b340 + param_2 * 4) == 0) {
    puVar1 = (undefined4 *)FUN_00000bcc(0xe0);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = FUN_00091830(puVar1);
    }
    *(undefined4 **)(&DAT_0034b340 + param_1[1] * 4) = puVar1;
  }
  *param_1 = *(int *)(&DAT_0034b340 + param_1[1] * 4);
  local_values[0] = 0;
  local_values[1] = 0;
  local_values[2] = 0;
  local_values[3] = 0;
  FUN_0009345c(*param_1,local_values);
  FUN_00093484(1.0f,*param_1);
  FUN_00093434(*param_1,&DAT_002bc410);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x10] = 0x3f800000;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0x3f800000;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)(param_1 + 0x1d) = 0;
  *(undefined1 *)((int)param_1 + 0x75) = 0;
  *(undefined1 *)((int)param_1 + 0x76) = 0;
  *(undefined1 *)((int)param_1 + 0x77) = 0;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  return param_1;
}

/* HSTMATCH module=EBOOT.BIN start=0x002298e8 end=0x0022995c symbol=FUN_002298e8 lang=c99 */
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

extern undefined4 * FUN_00229d60();

void FUN_002298e8(int *param_1,char *param_2,uint *param_3)
{
  undefined4 *puVar1;
  
  puVar1 = FUN_00229d60(param_2,param_3,*(undefined4 **)(param_2 + 4),(undefined4 *)(param_2 + 4));
  if ((puVar1 == (undefined4 *)(param_2 + 4)) || (*param_3 < (uint)puVar1[3])) {
    *param_1 = (int)(param_2 + 4);
  }
  else {
    *param_1 = (int)puVar1;
  }
  return;
}

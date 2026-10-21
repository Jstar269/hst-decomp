/* HSTMATCH module=EBOOT.BIN start=0x00002b60 end=0x00002bf4 symbol=FUN_00002b60 lang=c99 */
/* Clone of src/sharing_main/construct_child_00002b60.c (hstclone.py tag c171220): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the store of the allocated child pointer to param_1[1] comes before the cleanup call FUN_00002bfc (retail puts it in that call's delay slot; Ghidra printed it after the later call); found with hstnearperm.py and reduced to this one change; exact match verified; names and types await human review. */
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

extern int FUN_00000bcc();
extern void FUN_00002bf4();
extern undefined4 FUN_00002bfc();
extern undefined4 * FUN_00002c3c();
extern undefined4 FUN_00002d3c();
extern int FUN_00002df8();

undefined4 * FUN_00002b60(undefined4 *param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 auStack_8 [8];
  undefined1 local_c [4];
  
  local_c[0] = param_3;
  *param_1 = param_2;
  FUN_00002d3c(auStack_8,param_2,local_c);
  if ((iVar1 = FUN_00000bcc(0x10)) == 0) {
  }
  else {
    FUN_00002c3c(iVar1,param_2,local_c);
  }
  param_1[1] = iVar1;
  FUN_00002bfc(auStack_8);
  FUN_00002bf4(param_1,param_2,param_2);
  FUN_00002df8(auStack_8,0xffffffff);
  return param_1;
}

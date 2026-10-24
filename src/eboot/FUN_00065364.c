/* HSTMATCH module=EBOOT.BIN start=0x00065364 end=0x000653ac symbol=FUN_00065364 lang=c99 */
/* CSV table reader: column index by header name; see docs/DATA-TABLES.md */
/* Clone of src/sharing_main/FUN_00066400.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper arguments, used pointer arithmetic for the object subobject, and reversed the comparison arms; exact match verified; names and types await human review. */
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

extern void FUN_00065c60(int *,undefined4 *,undefined4 *);

undefined4 FUN_00065364(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int local_8 [2];
  undefined4 local_c;
  
  local_c = param_2;
  FUN_00065c60(local_8,(undefined4 *)param_1 + 8,&local_c);
  if (local_8[0] != param_1 + 0x24) {
    uVar1 = *(undefined4 *)(local_8[0] + 0x10);
  } else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* HSTMATCH module=EBOOT.BIN start=0x00000788 end=0x000007f4 symbol=FUN_00000788 lang=c99 */
/* Clone of src/sharing_main/iterate_callback_desc_00000788.c (hstclone.py tag c164820): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the pointer is decremented before each callback call, not after it (Ghidra printed the post-decrement form, 4 words off); found with hstnearperm.py and reduced to this one change; exact match verified; names and types await human review. */
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


void FUN_00000788(int param_1,code *param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = param_1 + param_3 * param_4;
  if (param_4 != 0) {
    do {
      iVar1 = iVar1 - param_3;
      (*param_2)(iVar1,0xffffffff);
      param_4 = param_4 - 1;
    } while (param_4 != 0);
  }
  return;
}

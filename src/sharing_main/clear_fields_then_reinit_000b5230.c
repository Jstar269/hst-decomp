/* HSTMATCH module=hstp_trans_main.prx start=0x000b5230 end=0x000b52a4 symbol=FUN_000b5230 lang=c99 */
/* Clone of src/eboot/clear_fields_then_reinit_000b2218.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the 11-argument callee prototype interleaves its floats among the ints (float, 5 ints, float, 3 ints, float) which reproduces retail argument-setup order; exact match verified; names and types await human review. */
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

extern void FUN_000b53d0(float, int, int, int, int, int, float, int, int, int, float);
extern undefined4 FUN_000b65a8();

void FUN_000b5230(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_000b65a8(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x444) = 0;
    *(undefined4 *)(param_1 + 0x448) = 0;
    *(undefined4 *)(param_1 + 0x44c) = 0;
    *(undefined4 *)(param_1 + 0x450) = 0;
    *(undefined4 *)(param_1 + 0x454) = 0;
    *(undefined4 *)(param_1 + 0x458) = 0;
    FUN_000b53d0(0.0f,param_1,0,1,1,1,0.0f,1,0,0,0.0f);
  }
  return;
}

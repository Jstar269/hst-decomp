/* HSTMATCH module=hstp_trans_main.prx start=0x00225d64 end=0x00225de4 symbol=FUN_00225d64 lang=c99 */
/* Clone of src/eboot/FUN_00216d60_00216d60.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: placed the nonzero dispatch arm first to match the target branch layout; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002d9e00;
extern undefined4 DAT_002d9e04;
extern undefined4 DAT_002d9e08;
extern undefined4 DAT_002d9e0c;
extern void FUN_00051d40();

void FUN_00225d64(undefined1 *param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_00051d40(*(undefined4 *)(param_1 + 4),1);
    *(undefined4 *)(param_1 + 0x108) = DAT_002d9e04;
    *(undefined4 *)(param_1 + 0x10c) = DAT_002d9e00;
    *param_1 = 1;
  }
  else {
    FUN_00051d40(*(undefined4 *)(param_1 + 4),2);
    *(undefined4 *)(param_1 + 0x108) = DAT_002d9e0c;
    *(undefined4 *)(param_1 + 0x10c) = DAT_002d9e08;
    *param_1 = 1;
  }
  return;
}


/* HSTMATCH module=hstp_trans_main.prx start=0x00095028 end=0x00095080 symbol=FUN_00095028 lang=c99 data=0x00378d28 */
/* Clone of src/eboot/is_asset_available_00093194.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00378d28-0x00378d33) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1/v2) corrected by hand: used an integer result and the retail early return layout; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern char DAT_00378aac[];
extern int FUN_00014934();
extern uint * FUN_000149a8();

int FUN_00095028(int param_1)
{
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = FUN_00014934(param_1,DAT_00378aac);
    if (iVar2 == 0) {
      FUN_000149a8(param_1,"Bip01LHand");
      return 1;
    }
  }
  return 0;
}

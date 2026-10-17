/* HSTMATCH module=hstp_trans_main.prx start=0x001f36f4 end=0x001f373c symbol=FUN_001f36f4 lang=c99 */
/* Clone of src/eboot/FUN_001e54dc.c (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the first call's receiver argument and the member load at +0x175c; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern void FUN_00108f54();
extern void FUN_001f08e8();
extern void FUN_001f373c();

void FUN_001f36f4(int param_1,undefined4 param_2)
{
  FUN_001f08e8(param_1);
  FUN_00108f54(*(int *)(param_1 + 0x175c),0);
  FUN_001f373c(param_1,param_2);
  return;
}

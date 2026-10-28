/* HSTMATCH module=hstp_trans_main.prx start=0x000d2328 end=0x000d2348 symbol=FUN_000d2328 lang=c99 data=0x0037cddc */
/* Clone of src/eboot/FUN_000ce72c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0037cddc-0x0037ce1c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

extern void FUN_000692a8();

void FUN_000d2328(void)
{
  FUN_000692a8("data/court/particle/texlist.csv","data/court/particle/motlist.csv"
               ,0x10,0,1);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x000d2308 end=0x000d2328 symbol=FUN_000d2308 lang=c99 data=0x0037cd8c */
/* Clone of src/eboot/FUN_000ce70c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0037cd8c-0x0037cddc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_000692a8();

void FUN_000d2308(void)
{
  FUN_000692a8("data/menu/game_eff/particle/texlist.csv",
               "data/menu/game_eff/particle/motlist.csv",0x10,0,0);
  return;
}

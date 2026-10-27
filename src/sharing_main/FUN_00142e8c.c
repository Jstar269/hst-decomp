/* HSTMATCH module=hstp_trans_main.prx start=0x00142e8c end=0x00142ed8 symbol=FUN_00142e8c lang=c99 data=0x00382bf0 */
/* Clone of src/eboot/FUN_00137840.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00382bf0-0x00382c19) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined4 DAT_003e95e4;
extern void FUN_000143b0();
extern void FUN_0014cc34();

void FUN_00142e8c(int param_1)
{
  undefined1 auStack_100 [256];
  
  FUN_000143b0(auStack_100,"data/court/%s/setting/c%02d_areaclip.csv",DAT_003e95e4,
               *(undefined4 *)(param_1 + 0x1364));
  FUN_0014cc34(param_1 + 0x40,0,auStack_100);
  return;
}

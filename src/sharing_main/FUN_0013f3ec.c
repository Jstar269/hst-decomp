/* HSTMATCH module=hstp_trans_main.prx start=0x0013f3ec end=0x0013f468 symbol=FUN_0013f3ec lang=c99 data=0x00382954 */
/* Clone of src/eboot/FUN_00133da0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00382954-0x0038298a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern void FUN_0014e8ac();

undefined4 FUN_0013f3ec(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined1 auStack_100 [256];
  
  uVar1 = DAT_003e95e4;
  FUN_000143b0(auStack_100,"data/adcourt/%s/haichi/%s__haichi.i3m",DAT_003e95e4,DAT_003e95e4);
  FUN_0014e8ac(param_1 + 0x40,auStack_100,"data/adcourt/",uVar1,param_3,0,0);
  return 1;
}

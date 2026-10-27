/* HSTMATCH module=hstp_trans_main.prx start=0x002b44d0 end=0x002b4648 symbol=FUN_002b44d0 lang=c99 data=0x003a9850 */
/* Hand-written reconstruction (port of src/eboot/FUN_002a4d40_002a4d40.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003a9850-0x003a988e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern unsigned char DAT_003b8ec6;
extern unsigned char DAT_003ba329;
extern unsigned char DAT_003b7ebc;
extern void FUN_0001c684();
extern void FUN_0001c73c();
extern void FUN_002b4648();
extern void FUN_002b46a8();
extern int FUN_002c74f0();
extern void FUN_002c7628();

void FUN_002b44d0(int param_1)
{
  uint uVar1;
  int local_4;
  int local_8;
  
  if (*(int *)(param_1 + 0x5d0) == 0) {
    uVar1 = FUN_002c74f0("fatms0:",0x2425823,0,0,&local_4,4);
    uVar1 = ((int)uVar1 < 0) ? uVar1 : (uint)(local_4 == 1);
    if ((int)uVar1 < 1) {
      FUN_002b46a8(param_1,2);
    }
    else {
      DAT_003ba329 = '\0';
      FUN_0001c684(&DAT_003b7ebc,1,"common/loading.xb");
      FUN_0001c73c(&DAT_003b7ebc);
      if ((DAT_003b8ec6 != '\0') && (DAT_003ba329 != '\0')) {
        uVar1 = FUN_002c74f0("fatms0:",0x2425823,0,0,&local_8,4);
        uVar1 = ((int)uVar1 < 0) ? uVar1 : (uint)(local_8 == 1);
        if ((int)uVar1 < 1) {
          FUN_002c7628(0x200000);
        }
        FUN_0001c684(&DAT_003b7ebc,1,"common/loading.xb");
        FUN_0001c73c(&DAT_003b7ebc);
      }
      if (DAT_003b8ec6 != 0) {
        FUN_002b46a8(param_1,1);
      }
      else {
        FUN_002b46a8(param_1,2);
      }
    }
  }
  else {
    FUN_002b4648("ERROR: Start(): already started.\n");
  }
  return;
}

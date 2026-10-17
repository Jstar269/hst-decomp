/* HSTMATCH module=hstp_trans_main.prx start=0x00110be0 end=0x00110c70 symbol=FUN_00110be0 lang=c99 */
/* Clone of src/eboot/FUN_0010ae20.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_0037ff94[];
extern char DAT_0037ffbc[];
extern void FUN_00012ad0();
extern uint FUN_0004cd8c();
extern undefined4 FUN_00110adc();

undefined4 FUN_00110be0(undefined1 *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  int local_4;
  
  iVar1 = FUN_0004cd8c(param_2,&local_4,0x10,1);
  if (iVar1 == 0) {
    FUN_00012ad0(DAT_0037ff94,param_2);
    uVar2 = 0;
  }
  else if (local_4 < 1) {
    FUN_00012ad0(DAT_0037ffbc,param_2);
    uVar2 = 0;
  }
  else {
    *param_1 = 1;
    uVar2 = FUN_00110adc(param_1,iVar1);
  }
  return uVar2;
}

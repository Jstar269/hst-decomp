/* HSTMATCH module=hstp_trans_main.prx start=0x0019d32c end=0x0019d3b0 symbol=FUN_0019d32c lang=c99 */
/* Clone of src/eboot/FUN_0011cc1c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00000a00();
extern uint * FUN_0019d3b0();
extern void FUN_0019d810();
extern void FUN_0019e050();

int FUN_0019d32c(int param_1,short param_2)
{
  char auStack_18 [24];
  undefined1 auStack_30 [24];
  
  if (param_1 != 0) {
    FUN_0019e050(auStack_30,param_1,*(undefined4 *)(param_1 + 0x14));
    FUN_0019e050(auStack_18,param_1,0);
    FUN_0019d810(param_1,auStack_18,auStack_30);
    FUN_0019d3b0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

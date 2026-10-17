/* HSTMATCH module=hstp_trans_main.prx start=0x000688ec end=0x00068954 symbol=FUN_000688ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_003b0438;
extern undefined4 * FUN_0001ec44();
extern void FUN_00068d80();
extern undefined4 * FUN_00068f7c();

undefined4 * FUN_000688ec(undefined4 *param_1)
{
  undefined1 auStack_4 [4];
  undefined4 local_8;
  undefined4 *local_c;
  
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b0438);
  FUN_00068f7c(param_1 + 0xf);
  local_c = param_1 + 0x10;
  local_8 = param_1[0x11];
  FUN_00068d80(auStack_4,param_1 + 0xf,&local_8,&local_c);
  param_1[0x12] = 0x3f800000;
  return param_1;
}

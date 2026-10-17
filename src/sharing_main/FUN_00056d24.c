/* HSTMATCH module=hstp_trans_main.prx start=0x00056d24 end=0x00056dac symbol=FUN_00056d24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the first helper as an object receiver and stored the allocated pointer after the guarded initialization; exact match verified; names and types await human review. */
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

extern int FUN_00000bcc();
extern undefined4 FUN_00056a58();
extern void FUN_00056ecc(undefined4 *);

undefined4 * FUN_00056d24(undefined4 *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  
  FUN_00056ecc(param_1);
  puVar1 = (undefined4 *)FUN_00000bcc(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    FUN_00056a58(puVar1,param_2,param_3);
  }
  *param_1 = (unsigned int)puVar1;
  *(undefined1 *)(param_1 + 2) = 1;
  return param_1;
}

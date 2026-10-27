/* HSTMATCH module=hstp_trans_main.prx start=0x00138d08 end=0x00138d68 symbol=FUN_00138d08 lang=c99 data=0x00381ef4 */
/* Clone of src/eboot/FUN_0012d7a8.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00381ef4-0x00381f21) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern void FUN_000143b0();
extern int FUN_000661a8();

void FUN_00138d08(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  uVar1 = FUN_000661a8(*(undefined4 *)(param_1 + 0x1398),*(undefined4 *)(param_1 + 0x1390),0);
  FUN_000143b0(param_2,"data/lobby/%s/setting/l%02d_r%02d_sedata.dat",uVar1,
               *(int *)(param_1 + 0x1390) + 1,*(int *)(param_1 + 0x1394) + 1);
  return;
}

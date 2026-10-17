/* HSTMATCH module=hstp_trans_main.prx start=0x0020bc3c end=0x0020bcdc symbol=FUN_0020bc3c lang=c99 */
/* Clone of src/eboot/helper_001fd46c.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a/v1) corrected by hand: modelled the zero block as two four-word arrays and typed the float arguments; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_003daec4;
extern void FUN_0001ef14();
extern void FUN_000646f4(float param_1,float param_2,undefined4 param_3,undefined4 *param_4,undefined4 *param_5,int param_6,int param_7,int param_8);
extern void FUN_0020bcdc();

void FUN_0020bc3c(int param_1,undefined1 param_2,int param_3)
{
  struct ZeroBlocks {
    undefined4 first[4];
    undefined4 second[4];
  } zeroBlocks;
  
  *(char *)(param_1 + 0x1290) = (char)param_3;
  *(undefined1 *)(param_1 + 0x1292) = param_2;
  FUN_0020bcdc();
  if (param_3 != 0) {
    zeroBlocks.first[0] = 0;
    zeroBlocks.first[1] = 0;
    zeroBlocks.first[2] = 0;
    zeroBlocks.first[3] = 0;
    zeroBlocks.second[0] = 0;
    zeroBlocks.second[1] = 0;
    zeroBlocks.second[2] = 0;
    zeroBlocks.second[3] = 0;
    FUN_000646f4(65535.0f,-1.0f,DAT_003daec4,zeroBlocks.second,zeroBlocks.first,0,0,0);
  }
  FUN_0001ef14(param_1,0);
  return;
}

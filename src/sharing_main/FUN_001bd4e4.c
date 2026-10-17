/* HSTMATCH module=hstp_trans_main.prx start=0x001bd4e4 end=0x001bd544 symbol=FUN_001bd4e4 lang=c99 */
/* Clone of src/eboot/FUN_001afe0c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001bde64();

void FUN_001bd4e4(int param_1)
{
  *(undefined4 *)(param_1 + 0x7cc) = 0x1da;
  FUN_001bde64(param_1,0x3e);
  FUN_001bde64(param_1,0x53);
  FUN_001bde64(param_1,0xaf);
  FUN_001bde64(param_1,0xae);
  FUN_001bde64(param_1,1);
  return;
}

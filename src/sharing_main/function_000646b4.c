/* HSTMATCH module=hstp_trans_main.prx start=0x000646b4 end=0x000646f4 symbol=FUN_000646b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used unsigned-byte fields, an int flag accumulator, and a float helper parameter to preserve the retail loads and call; exact match verified; names and types await human review. */
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

extern void FUN_00063f4c(float);

void FUN_000646b4(int param_1)
{
  unsigned char *p = (unsigned char *)param_1;
  int bVar1 = p[0x52] != 0;
  if (bVar1)
    bVar1 = (p[0x51] != 0) ^ 1;
  if (bVar1)
    FUN_00063f4c(*(float *)(p + 0x54));
}

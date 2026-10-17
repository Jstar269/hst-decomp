/* HSTMATCH module=hstp_trans_main.prx start=0x0006901c end=0x00069040 symbol=FUN_0006901c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
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


float FUN_0006901c(float param_1,float param_2,float param_3)
{
  return param_1 + (param_2 - param_1) * (1.0f - (1.0f - param_3) * (1.0f - param_3));
}

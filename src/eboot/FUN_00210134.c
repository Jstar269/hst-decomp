/* HSTMATCH module=EBOOT.BIN start=0x00210134 end=0x00210164 symbol=FUN_00210134 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern float DAT_00341174;
extern float DAT_0034117c;

float FUN_00210134(float param_1)
{
  return DAT_00341174 * 0.01f + DAT_0034117c * 0.01f * param_1;
}

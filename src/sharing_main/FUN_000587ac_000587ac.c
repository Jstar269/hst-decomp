/* HSTMATCH module=hstp_trans_main.prx start=0x000587ac end=0x00058814 symbol=FUN_000587ac lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern int FUN_00058588(int, int, float, int, float);

unsigned char FUN_000587ac(float param_1, int param_2, int param_3, int param_4)
{
  int int_values[2];
  float float_values[2];
  int i;
  int *ip;
  float *fp;
  i = 0;
  ip = int_values;
  fp = float_values;
  do {
    if (i == param_3) {
      *ip = param_4;
      *fp = param_1;
    }
    else {
      *ip = 0x7fff;
      *fp = 0.0f;
    }
    i++;
    ip++;
    fp++;
  } while (i < 2);
  return FUN_00058588(param_2, int_values[0], float_values[0], int_values[1], float_values[1]);
}
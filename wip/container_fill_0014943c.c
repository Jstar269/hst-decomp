/* HSTMATCH module=EBOOT.BIN start=0x0014943c end=0x001494e4 symbol=FUN_0014943c lang=c99 */
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

extern undefined4 FUN_00002f60();
extern uint * FUN_00146e1c();

typedef struct { char bytes[40]; } Elem_28;

void FUN_0014943c(int *param_1,int param_2,undefined4 param_3)
{
  Elem_28 *cursor;
  int *p;
  int n;

  cursor = (Elem_28 *)*param_1 + param_1[4];
  cursor = cursor + param_1[1];
  if (param_2 != 0) {
    do {
      p = (int *)FUN_00002f60(sizeof(Elem_28),cursor);
      if (p != (int *)0x0) {
        FUN_00146e1c(p,param_3);
      }
      n = param_1[1];
      param_1[1] = n + 1;
      cursor = cursor + 1;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}

// Near miss: 2 words differ. Body instructions match; candidate frame is 32 bytes while retail uses 48.
// near miss from lane u2r1-1 (unreviewed)

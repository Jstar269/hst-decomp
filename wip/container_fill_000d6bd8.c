/* HSTMATCH module=EBOOT.BIN start=0x000d6bd8 end=0x000d6c80 symbol=FUN_000d6bd8 lang=c99 */
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
extern uint * FUN_000d5948();

typedef struct { char bytes[24]; } Elem_18;

void FUN_000d6bd8(int *param_1,int param_2,undefined4 param_3)
{
  Elem_18 *cursor;
  int *p;
  int n;

  cursor = (Elem_18 *)*param_1 + param_1[4];
  cursor = cursor + param_1[1];
  if (param_2 != 0) {
    do {
      p = (int *)FUN_00002f60(sizeof(Elem_18),cursor);
      if (p != (int *)0x0) {
        FUN_000d5948(p,param_3);
      }
      n = param_1[1];
      param_1[1] = n + 1;
      cursor = cursor + 1;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}

// Near miss: 2 words differ. Body instructions match; candidate frame is 32 bytes while retail uses 48. An empty fourth FalseTag argument emitted extra `move`/`seb` instructions and changed register allocation, so it was ruled out.
// near miss from lane u2r1-1 (unreviewed)

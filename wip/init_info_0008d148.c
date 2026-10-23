/* HSTMATCH module=EBOOT.BIN start=0x0008d148 end=0x0008d1ec symbol=FUN_0008d148 lang=c99 */
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

extern char DAT_002beaa8[];
extern void FUN_000114c0(void *, int, int);
extern void FUN_0008cae8(const void *);

void FUN_0008d148(undefined1 *param_1)
{
  register short invalid = -1;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 1;
  param_1[0x22] = 2;
  param_1[0x23] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x30] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  FUN_000114c0(param_1 + 0x38,0,0x6c);
  {
    short *fields = (short *)(param_1 + 0xa0);
    fields[0] = invalid;
    fields[1] = invalid;
  }
  *(short *)(param_1 + 0x5c) = invalid;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  FUN_0008cae8(DAT_002beaa8);
  return;
}

// NEAR 4 words. The only remaining mismatch is the register used for the shared -1 constant: this source emits li v0,-1; retail emits li v1,-1 for the three halfword stores.
// Tried signed/unsigned short and int locals, register locals, C++ mode, typed helper prototypes, pointer grouping, and reordered stores; all retained v0.
// near miss from lane km3 (unreviewed)

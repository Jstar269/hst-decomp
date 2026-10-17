/* HSTMATCH module=EBOOT.BIN start=0x001fa2b4 end=0x001fa35c symbol=FUN_001fa2b4 lang=c99 */
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

extern undefined DAT_003417b8;
extern void FUN_001bbcd4(float param_1,byte *param_2);

typedef struct SelfView {
  char pad0[0x3cc];
  int index0;
  int index1;
  char pad1[0x1c8];
  unsigned char enabled;
  char pad2[0xb73];
  float value0;
  char pad3[0xe0];
  float value1;
} SelfView;

void FUN_001fa2b4(SelfView *self,char *buffer)
{
  FUN_001bbcd4(self->value0,
               (byte *)(buffer +
                       *(short *)((char *)&DAT_003417b8 + self->index0 * 0x120 + 0x18) * 0x38));
  if (self->enabled != 0) {
    FUN_001bbcd4(self->value1,
                 (byte *)(buffer +
                         *(short *)((char *)&DAT_003417b8 + self->index1 * 0x120 + 0x18) * 0x38));
  }
  return;
}
// Near miss: 6 words differ in the first index and receiver register assignment. The corrected table base and unsigned flag match; the remaining first-call setup still uses a0/a1 in a different allocation.
// near miss from lane u5cr1-1 (unreviewed)

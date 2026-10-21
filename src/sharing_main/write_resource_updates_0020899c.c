/* HSTMATCH module=hstp_trans_main.prx start=0x0020899c end=0x00208a44 symbol=FUN_0020899c lang=c99 */
/* Clone of src/eboot/write_resource_updates_001fa2b4.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag u5cr1-1) corrected by hand: struct view of the object, FUN_001c9abc declared (byte *, float) so the buffer address is computed before the float load and self is copied to s1 first; exact match verified; matching idiom: pointer-before-float parameter order; names and types await human review. */
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

extern undefined DAT_003eaaf0;
extern void FUN_001c9abc(byte *param_2,float param_1);

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

void FUN_0020899c(SelfView *self,char *buffer)
{
  FUN_001c9abc((byte *)(buffer +
                       *(short *)((char *)&DAT_003eaaf0 + self->index0 * 0x120 + 0x18) * 0x38),
               self->value0);
  if (self->enabled != 0) {
    FUN_001c9abc((byte *)(buffer +
                         *(short *)((char *)&DAT_003eaaf0 + self->index1 * 0x120 + 0x18) * 0x38),
                 self->value1);
  }
  return;
}

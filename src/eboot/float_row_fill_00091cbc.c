/* HSTMATCH module=EBOOT.BIN start=0x00091cbc end=0x00091d90 symbol=FUN_00091cbc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: the 7-float table as float pointer, the three float arguments of FUN_0006e094 (EABI float regs), the >= 0 test, and the local order (pointer before offset) for the saved registers; readability pass; exact match verified; names and types await human review. */
#include "hst/model_set_full.h"
typedef int code();

extern float DAT_002d28b8;
extern int * FUN_000008d8(int *table,code *ctor,code *dtor,int elemSize,u32 count);
extern int FUN_00000a90();
extern void FUN_0006e094(u32 *entry,int mode,float a,float b,float scale);
extern void FUN_0006dfe4();
extern void FUN_0006e024();

/* Build the entry table on first use, then (re)initialise every entry from the float table. */
void FUN_00091cbc(ModelSetFull *self)
{
  int tmp; /* table address first, then the entry mode */
  u32 index;
  float *weight;
  int offset;
  float scale;
  float value;

  if (self->entries == 0) {
    tmp = FUN_00000a90(0x48);
    tmp = (int)(FUN_000008d8((int *)(tmp),(code *)(FUN_0006dfe4),(code *)(FUN_0006e024),MSET_ENTRY_SIZE,MSET_ENTRY_COUNT));
    self->entries = (void *)tmp;
  }
  if (self->level >= 0) {
    index = 0;
    weight = (float *)&DAT_002d28b8;
    offset = 0;
    do {
      value = *weight;
      if (self->level == 0) {
        tmp = 2;
        scale = 0.5f;
      }
      else {
        tmp = 1;
        scale = 1.0f;
      }
      FUN_0006e094((u32 *)((int)self->entries + offset),tmp,value,value,scale);
      index = index + 1;
      weight = weight + 1;
      offset = offset + MSET_ENTRY_SIZE;
    } while (index < MSET_ENTRY_COUNT);
  }
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001317c8 end=0x00131868 symbol=FUN_001317c8 lang=c99 */
/* Clone of src/eboot/FUN_00126558.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b1310;
extern void FUN_00000a00();
extern void FUN_002c7680();
extern void FUN_002c76a0();
extern void FUN_002c7ba0();

/* Object with two kernel ids and a pointer to a flag byte it raises on destruction. */
typedef struct WorkerObj {
  void *vtbl;      /* 0x00 */
  int unk04;       /* 0x04 kernel id, positive while in use */
  int unk08;       /* 0x08 */
  u32 unk0c;       /* 0x0c kernel id, released on destruction */
  int unk10;       /* 0x10 */
  u8 *stop_flag;   /* 0x14 set to 1 on destruction */
} WorkerObj;

/* Destructor: raise the stop flag, release the two ids, free the object when `flags` > 0. */
WorkerObj * FUN_001317c8(WorkerObj *self,short flags)
{
  int id;
  u32 id2;
  
  if (self != (WorkerObj *)0x0) {
    self->vtbl = &DAT_003b1310;
    if (self->stop_flag != (u8 *)0x0) {
      *self->stop_flag = 1;
    }
    id = self->unk04;
    if (id >= 1) {
      FUN_002c7ba0(self->unk0c,0);
      FUN_002c7680(self->unk04,0);
      FUN_002c76a0(self->unk04);
    }
    id2 = self->unk0c;
    FUN_002c7ba0(id2,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}

/* HSTMATCH module=EBOOT.BIN start=0x0012f41c end=0x0012f698 symbol=FUN_0012f41c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/camera_obj.h"

/* Number of entries in the record table, each starting zeroed with unk40 = 1. */
#define CAM_RECORD_COUNT 0xe0

typedef struct CamRecord {
  u32 unk00;
  u32 unk04;
  u32 unk08;
  u32 unk0c;
  u32 unk10;
  u32 unk14;
  u32 unk18;
  u32 unk1c;
  u32 unk20;
  u32 unk24;
  u32 unk28;
  u32 unk2c;
  u32 unk30;
  u32 unk34;
  u32 unk38;
  u32 unk3c;
  u32 unk40;
  u16 unk44;
  u16 unk46;
  u16 unk48;
  u8 unk4a;
  u8 unk4b;
  u8 unk4c;
  u8 unk4d;
  u8 unk4e;
  u8 unk4f;
  u8 unk50;
  u8 unk51;
  u8 unk52;
  u8 unk53;
  u8 unk54;
  u8 unk55;
  u8 unk56;
  u8 unk57;
} CamRecord;

extern u8 DAT_003081f0;
extern CamRecord DAT_0033b584[];
extern CameraObj * DAT_00340284;
extern void * FUN_00000bcc(unsigned int);
extern void FUN_0001f06c();
extern void FUN_0001f1fc(void *, int);
extern void FUN_0001f21c(void *, void *);
extern void * FUN_000b7e7c(void *);
extern void * FUN_00122888(void *);
extern u32 FUN_0012f698(void *);
extern void * FUN_001b9760(void *);

/* Camera constructor: reset the record table and every field, then create the three sub-objects. */
CameraObj * FUN_0012f41c(CameraObj *self)
{
  void *part;
  int i;
  CamRecord *rec;
  int j;
  
  FUN_0001f06c();
  self->vtable = &DAT_003081f0;
  self->parts[0] = 0;
  self->parts[1] = 0;
  self->parts[2] = 0;
  DAT_00340284 = self;
  i = 0;
  rec = DAT_0033b584;
  do {
    rec->unk00 = 0;
    rec->unk04 = 0;
    rec->unk08 = 0;
    rec->unk0c = 0;
    rec->unk4a = 0;
    rec->unk10 = 0;
    rec->unk14 = 0;
    rec->unk18 = 0;
    rec->unk4b = 0;
    rec->unk4c = 0;
    rec->unk4e = 0;
    rec->unk4f = 0;
    rec->unk1c = 0;
    rec->unk50 = 0;
    rec->unk44 = 0;
    rec->unk46 = 0;
    rec->unk51 = 0;
    rec->unk38 = 0;
    rec->unk48 = 0;
    rec->unk52 = 0;
    rec->unk3c = 0;
    rec->unk53 = 0;
    rec->unk34 = 0;
    rec->unk54 = 0;
    rec->unk55 = 0;
    rec->unk56 = 0;
    rec->unk57 = 0;
    rec->unk20 = 0;
    rec->unk24 = 0;
    rec->unk28 = 0;
    rec->unk2c = 0;
    rec->unk30 = 0;
    i = i + 1;
    rec->unk40 = 1;
    rec++;
  } while (i < CAM_RECORD_COUNT);
  for (j = 0; j < 11; j++) {
    self->unk50[j] = 1.0f;
  }
  self->unkb0 = 0;
  self->unkb4 = 0;
  self->unkc0 = 0;
  self->unkc4 = 0;
  self->unkc8 = 0;
  self->unkcc = 1.0f;
  self->unk90 = 0;
  self->unka0 = 0;
  self->unka4 = 0;
  self->unka8 = 0;
  self->unkac = 1.0f;
  self->unkd0 = 0;
  self->unk44 = 0;
  self->unke0 = 0;
  self->unke4 = 0;
  self->unke8 = 0;
  self->unkec = 1.0f;
  /* state starts as CAM_STATE_FOLLOW, stored byte by byte */
  ((u8 *)&self->state)[0] = 1;
  self->unk134 = 0;
  ((u8 *)&self->state)[1] = 0;
  ((u8 *)&self->state)[2] = 0;
  ((u8 *)&self->state)[3] = 0;
  self->unkf4 = 0;
  self->src = 0;
  self->unkfc = 0;
  self->unk100 = 0;
  self->unk110 = 0;
  self->unk114 = 0;
  self->unk118 = 0;
  self->unk11c = 1.0f;
  self->unk120 = -1;
  self->unk124 = -1;
  self->unk3c = 0;
  self->unk40 = -1;
  self->unk48 = 0;
  self->unk4c = 1;
  self->unk128 = 0;
  self->unk12c = 1;
  self->unk130 = 0;
  self->unk88 = 0;
  self->unk8c = 0;
  FUN_0012f698(self);
  part = FUN_00000bcc(0x100);
  if (part != 0) {
    part = FUN_000b7e7c(part);
  }
  self->parts[0] = part;
  FUN_0001f21c(self,part);
  FUN_0001f1fc(self->parts[0],1);
  part = FUN_00000bcc(0xa0);
  if (part != 0) {
    part = FUN_00122888(part);
  }
  self->parts[1] = part;
  FUN_0001f21c(self,part);
  FUN_0001f1fc(self->parts[1],0);
  part = FUN_00000bcc(0x48);
  if (part != 0) {
    part = FUN_001b9760(part);
  }
  self->parts[2] = part;
  FUN_0001f21c(self,part);
  FUN_0001f1fc(self->parts[2],0);
  return self;
}

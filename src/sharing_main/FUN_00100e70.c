/* HSTMATCH module=hstp_trans_main.prx start=0x00100e70 end=0x00100ef4 symbol=FUN_00100e70 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Info { char pad[0xc]; int kind; } Info;
typedef struct Mgr { char pad[0x94]; Info *info; } Mgr;
typedef struct Target { char pad[0x4c]; int state; } Target;
typedef struct Cur { char pad[0x3c]; int mode; } Cur;
typedef struct Self { char pad[0x3c]; Mgr *mgr; Target *target; } Self;
extern Cur *DAT_003e19f0;

int FUN_00100e70(Self *self)
{
  if (DAT_003e19f0 == 0 || (DAT_003e19f0->mode != 9 && DAT_003e19f0->mode != 2)) {
    if (self->mgr->info->kind == 0xb) {
      if (self->target == 0 || self->target->state == 5) return 1;
    }
  } else {
    return 1;
  }
  return 0;
}

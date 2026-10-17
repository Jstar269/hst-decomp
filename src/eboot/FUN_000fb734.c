/* HSTMATCH module=EBOOT.BIN start=0x000fb734 end=0x000fb7b8 symbol=FUN_000fb734 lang=c99 */
/* Clone of src/sharing_main/FUN_00100e70.c (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Info { char pad[0xc]; int kind; } Info;
typedef struct Mgr { char pad[0x94]; Info *info; } Mgr;
typedef struct Target { char pad[0x4c]; int state; } Target;
typedef struct Cur { char pad[0x3c]; int mode; } Cur;
typedef struct Self { char pad[0x3c]; Mgr *mgr; Target *target; } Self;
extern Cur *DAT_003386b0;

int FUN_000fb734(Self *self)
{
  if (DAT_003386b0 == 0 || (DAT_003386b0->mode != 9 && DAT_003386b0->mode != 2)) {
    if (self->mgr->info->kind == 0xb) {
      if (self->target == 0 || self->target->state == 5) return 1;
    }
  } else {
    return 1;
  }
  return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x001b5354 end=0x001b53ec symbol=FUN_001b5354 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj { char pad0[0x48]; unsigned char flag; } Obj;
typedef struct Cfg { char pad0[0x120]; int value; } Cfg;

#define STATUS_BIT_20 0x20 /* status bit that makes the flag follow the helper alone */

extern Cfg *DAT_00340284;
extern int DAT_0034179c;
extern int FUN_000487c8(void);
extern void FUN_001b23c0(int *, int);
extern unsigned int FUN_002b79e8(void);

/* Recompute the object's flag and, when it changed, pass the new value on to the DAT_0034179c object. */
void FUN_001b5354(Obj *self)
{
  int enabled;
  unsigned char status;
  unsigned char new_flag;
  FUN_000487c8();
  status = (unsigned char)FUN_002b79e8();
  if ((status & STATUS_BIT_20) != 0) {
    enabled = FUN_000487c8();
  } else {
    enabled = (FUN_000487c8() != 0) || (DAT_00340284->value >= 0);
  }
  new_flag = (unsigned char)enabled;
  if (self->flag == new_flag)
    return;
  self->flag = new_flag;
  FUN_001b23c0(&DAT_0034179c, self->flag);
}

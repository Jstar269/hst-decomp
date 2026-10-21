/* HSTMATCH module=EBOOT.BIN start=0x001b5354 end=0x001b53ec symbol=FUN_001b5354 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj { char pad0[0x48]; unsigned char flag; } Obj;
typedef struct Cfg { char pad0[0x120]; int value; } Cfg;
extern Cfg *DAT_00340284;
extern int DAT_0034179c;
extern int FUN_000487c8(void);
extern void FUN_001b23c0(int *, int);
extern unsigned int FUN_002b79e8(void);
void FUN_001b5354(Obj *self)
{
  int result;
  unsigned char mode;
  unsigned char next;
  FUN_000487c8();
  mode = (unsigned char)FUN_002b79e8();
  if ((mode & 0x20) != 0) {
    result = FUN_000487c8();
  } else {
    result = (FUN_000487c8() != 0) || (DAT_00340284->value >= 0);
  }
  next = (unsigned char)result;
  if (self->flag == next)
    return;
  self->flag = next;
  FUN_001b23c0(&DAT_0034179c, self->flag);
}

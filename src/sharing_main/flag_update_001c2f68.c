/* HSTMATCH module=hstp_trans_main.prx start=0x001c2f68 end=0x001c3000 symbol=FUN_001c2f68 lang=c99 */
/* Clone of src/eboot/flag_update_001b5354.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj { char pad0[0x48]; unsigned char flag; } Obj;
typedef struct Cfg { char pad0[0x120]; int value; } Cfg;
extern Cfg *DAT_003e95c4;
extern int DAT_003eaad8;
extern int FUN_00048958(void);
extern void FUN_001c0454(int *, int);
extern unsigned int FUN_002c7788(void);
void FUN_001c2f68(Obj *self)
{
  int result;
  unsigned char mode;
  unsigned char next;
  FUN_00048958();
  mode = (unsigned char)FUN_002c7788();
  if ((mode & 0x20) != 0) {
    result = FUN_00048958();
  } else {
    result = (FUN_00048958() != 0) || (DAT_003e95c4->value >= 0);
  }
  next = (unsigned char)result;
  if (self->flag == next)
    return;
  self->flag = next;
  FUN_001c0454(&DAT_003eaad8, self->flag);
}

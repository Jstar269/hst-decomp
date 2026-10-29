/* HSTMATCH module=hstp_trans_main.prx start=0x0029134c end=0x00291364 symbol=FUN_0029134c lang=c99 */
/* Clone of src/eboot/FUN_0027fed8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
typedef struct Source {
  char pad0[4];
  short unk4;   /* 0x04 */
} Source;

typedef struct Cursor {
  Source *source; /* 0x00 */
  short unk4;     /* 0x04 copied from the source */
  int unk8;       /* 0x08 */
  signed char flag; /* 0x0c */
} Cursor;

/* Initializes a cursor over a source object. */
void FUN_0029134c(Cursor *self,Source *source,signed char flag)
{
  self->source = source;
  self->unk8 = 0;
  self->unk4 = source->unk4;
  self->flag = flag;
  return;
}

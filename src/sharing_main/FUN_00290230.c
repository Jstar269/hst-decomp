/* HSTMATCH module=hstp_trans_main.prx start=0x00290230 end=0x0029027c symbol=FUN_00290230 lang=c99 */
/* Clone of src/eboot/FUN_0027edbc.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char pad0[4]; unsigned char *data; unsigned count; } Self;
typedef struct { int a; short flag; char pad[0x28 - 6]; } Elem;

Elem *FUN_00290230(Self *self, int idx)
{
  Elem *t;
  Elem *r;

  if (0 <= idx && idx < self->count && (t = (Elem *)(self->data + idx * 0x28))->flag >= 0)
    r = t;
  else
    r = 0;
  return r;
}

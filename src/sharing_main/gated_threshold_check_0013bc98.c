/* HSTMATCH module=hstp_trans_main.prx start=0x0013bc98 end=0x0013bd24 symbol=FUN_0013bc98 lang=c99 */
/* Clone of src/eboot/gated_threshold_check_001306e0.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003f39a8;
extern float DAT_00382398;
extern int FUN_0023c334(void);

typedef struct { char pad[0x68]; float f68; } Sub80;
typedef struct { char pad[0x40]; unsigned char f40; } Sub84;
typedef struct { char pad[0x80]; Sub80 *p80; Sub84 *p84; } Obj;

/* One conditional expression: the int-typed ?: result is converted to the
   unsigned char return type once, in the shared exit block (retail's single
   trailing andi), and the && short-circuit gives the bnezl/b layout. */
unsigned char FUN_0013bc98(Obj *self)
{
  return (DAT_003f39a8 == 0x2a && FUN_0023c334() != 0)
             ? (self->p80->f68 > 30.0f * DAT_00382398)
             : self->p84->f40;
}

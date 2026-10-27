/* HSTMATCH module=EBOOT.BIN start=0x001306e0 end=0x0013076c symbol=FUN_001306e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a678;
extern float DAT_002db18c;
extern int FUN_0022c860(void);

typedef struct { char pad[0x68]; float f68; } Sub80;
typedef struct { char pad[0x40]; unsigned char f40; } Sub84;
typedef struct { char pad[0x80]; Sub80 *p80; Sub84 *p84; } Obj;

/* One conditional expression: the int-typed ?: result is converted to the
   unsigned char return type once, in the shared exit block (retail's single
   trailing andi), and the && short-circuit gives the bnezl/b layout. */
unsigned char FUN_001306e0(Obj *self)
{
  return (DAT_0034a678 == 0x2a && FUN_0022c860() != 0)
             ? (self->p80->f68 > 30.0f * DAT_002db18c)
             : self->p84->f40;
}

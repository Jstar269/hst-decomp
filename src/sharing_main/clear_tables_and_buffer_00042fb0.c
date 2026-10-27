/* HSTMATCH module=hstp_trans_main.prx start=0x00042fb0 end=0x000430d8 symbol=FUN_00042fb0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Clears the first halfword of every entry of three tables (8-byte entries in a, 4-byte entries in b and c) and fills
   the w*h/2-byte buffer with zero. The members sit beyond 0x7fff, so every access is `lui 2; addu; lw -N`, and the
   short stores may alias the table pointers, so MWCC reloads them on every pass. The single early-return `||` guard
   gives retail's dead original of the likely-slot `lui` after the last test. FUN_00022da4 is a VFPU memset
   (dst, byte, count): it replicates the byte into a vector register and stores 64-byte blocks with sv.q. */
typedef struct { short v; short pad; int w; } Rec8;
typedef struct { short v; short pad; } Rec4;
typedef struct {
  char pad[0x19084];
  void *buf;
  char pad19088[0x190a0 - 0x19088];
  int count;
  Rec8 *a;
  Rec4 *b;
  Rec4 *c;
  char pad190b0[0x190b4 - 0x190b0];
  int w;
  int h;
} Obj;
extern void FUN_00022da4(void *dst, int c, int n);
void FUN_00042fb0(Obj *o)
{
  int i;
  if (o->a == 0 || o->b == 0 || o->c == 0 || o->buf == 0)
    return;
  for (i = 0; i < o->count; i++) {
    o->a[i].v = 0;
    o->b[i].v = 0;
    o->c[i].v = 0;
  }
  FUN_00022da4(o->buf, 0, o->w * o->h / 2);
}

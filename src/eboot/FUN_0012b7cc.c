/* HSTMATCH module=EBOOT.BIN start=0x0012b7cc end=0x0012b868 symbol=FUN_0012b7cc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Inner { char pad0[0xf0]; int f0; };
struct Outer { char pad0[0x58]; struct Inner *f58; };
extern int DAT_0033b4b0[]; extern int DAT_0033b4b4[]; extern int DAT_0033b4b8[];
extern int FUN_0012b568(void);
int FUN_0012b7cc(struct Outer *o)
{
  struct Inner *in = o->f58;
  int v, i;
  int r;
  if (in == 0) return 0;
  v = in->f0;
  r = 0;
  i = FUN_0012b568();
  if (i >= 0 && (v == DAT_0033b4b0[i] || v == DAT_0033b4b4[i] || v == DAT_0033b4b8[i])) r = 1;
  return r;
}

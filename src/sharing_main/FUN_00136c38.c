/* HSTMATCH module=hstp_trans_main.prx start=0x00136c38 end=0x00136cd4 symbol=FUN_00136c38 lang=c99 */
/* Clone of src/eboot/FUN_0012b7cc.c (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Inner { char pad0[0xf0]; int f0; };
struct Outer { char pad0[0x58]; struct Inner *f58; };
extern int DAT_003e47f0[]; extern int DAT_003e47f4[]; extern int DAT_003e47f8[];
extern int FUN_001369d4(void);
int FUN_00136c38(struct Outer *o)
{
  struct Inner *in = o->f58;
  int v, i;
  int r;
  if (in == 0) return 0;
  v = in->f0;
  r = 0;
  i = FUN_001369d4();
  if (i >= 0 && (v == DAT_003e47f0[i] || v == DAT_003e47f4[i] || v == DAT_003e47f8[i])) r = 1;
  return r;
}

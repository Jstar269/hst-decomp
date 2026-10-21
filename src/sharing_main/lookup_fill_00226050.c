/* HSTMATCH module=hstp_trans_main.prx start=0x00226050 end=0x002260f0 symbol=FUN_00226050 lang=c99 */
/* Clone of src/eboot/lookup_fill_0021704c.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Res { int f0; char pad[0x1c]; int f20; } Res;
typedef struct Out { Res *res; int f4; int f8; } Out;
typedef struct In { unsigned char idx; char name[32]; } In;

extern Res *FUN_00108124(Res *, char *);

void FUN_00226050(Out *out, Res **base, In *in, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    Res *p = FUN_00108124(base[in[i].idx], in[i].name);
    if (p != 0) {
      out[i].res = p;
      int v = p->f20;
      out[i].f4 = v;
      if (v != 0) {
        out[i].f8 = p->f0;
      }
    }
  }
}

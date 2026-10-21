/* HSTMATCH module=EBOOT.BIN start=0x0021704c end=0x002170ec symbol=FUN_0021704c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Res { int f0; char pad[0x1c]; int f20; } Res;
typedef struct Out { Res *res; int f4; int f8; } Out;
typedef struct In { unsigned char idx; char name[32]; } In;

extern Res *FUN_001026b8(Res *, char *);

void FUN_0021704c(Out *out, Res **base, In *in, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    Res *p = FUN_001026b8(base[in[i].idx], in[i].name);
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

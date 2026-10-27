/* HSTMATCH module=EBOOT.BIN start=0x0015a4c8 end=0x0015a62c symbol=FUN_0015a4c8 lang=c++ */
/* Hand-written reconstruction (port of src/sharing_main/replace_slot_object_00166aa0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Matching idiom: `int off = slot * 4; (Snd **)(off + (int)self + 0x34)` (offset-first addu; `&self->snd[slot]` gives `addu v0,s1,v0`, one word off). The flag is an `int` (a uchar local adds `andi 0xff`); `*pp` is re-read after the new/ctor (lw a0,0(s2)); the virtual deleting dtor is slot 0 of Snd (`delete *pp`). */
struct Snd { virtual ~Snd(); };
struct Chan { char b[0x100]; };
struct Vv { int x, y, z; float w; };
struct Self { char pad0[0x34]; Snd *snd[3]; Vv v[3]; Chan ch[3]; char str[1]; };
extern "C" {
extern unsigned char DAT_003417cc;
extern int DAT_0034a65c;
extern char DAT_002de050[];
extern char DAT_002de074[];
extern char DAT_0030ebf4[];
extern void FUN_000143b0(void *, char *, int);
extern int FUN_00014934(void *, void *);
extern void FUN_000149a8(void *, void *);
extern void FUN_0001cad0(char *, int, void *);
extern void FUN_0001cb88(char *);
extern Snd *FUN_00050fc0(void *);
extern void FUN_000511c4(Snd *, void *, int);
extern void FUN_00051398(float, Snd *);
}
extern "C" void FUN_0015a4c8(Self *self, int slot)
{
  int flag = 1;
  if (DAT_0034a65c == 0)
    flag = DAT_003417cc;
  FUN_000143b0(self->str, DAT_002de050, flag);
  FUN_0001cad0(DAT_0030ebf4, 1, self->str);
  FUN_000143b0(self->str, DAT_002de074, flag);
  int off = slot * 4;
  Snd **pp = (Snd **)(off + (int)self + 0x34);
  if (*pp == 0 || FUN_00014934(&self->ch[slot], self->str) != 0) {
    if (*pp != 0) {
      delete *pp;
      *pp = 0;
    }
    Snd *p = (Snd *)operator new(0x48);
    if (p != 0)
      p = FUN_00050fc0(p);
    *pp = p;
    FUN_000511c4(p, self->str, 0);
    FUN_00051398(3000.0f, *pp);
    FUN_000149a8(&self->ch[slot], self->str);
    self->v[slot].x = 0;
    self->v[slot].y = 0;
    self->v[slot].z = 0;
    self->v[slot].w = 1.0f;
  }
  FUN_0001cb88(DAT_0030ebf4);
}

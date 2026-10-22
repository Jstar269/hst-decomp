/* HSTMATCH module=EBOOT.BIN start=0x0006d8e0 end=0x0006dab0 symbol=FUN_0006d8e0 lang=c++ */
struct Mgr;
extern "C" void FUN_0006eaa0(Mgr *p, int b);

struct Mgr {
  void **items;
  unsigned count;
  unsigned cap;
  unsigned n3;
  void *data4;
  int f5;
  Mgr() {
    items = 0;
    count = 0;
    FUN_0006eaa0(this, 0);
    cap = 0;
    n3 = 0;
    data4 = 0;
    f5 = 0;
  }
  void shrink(int n) { count -= n; }
};

extern "C" void FUN_0006de30();
extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_000143b0(char *buf, const char *fmt, int a, int b);
extern "C" void FUN_000149a8(char *dst, const char *src);
extern "C" void FUN_00014788(char *dst, const char *src);
extern "C" int FUN_0004ccb8(const char *path, int a, int b);
extern "C" void FUN_0004cfd0(int h);
extern "C" void *FUN_00050ff4(void *p, const char *name, int flag);
extern "C" void FUN_00051398(float v, void *p);
extern "C" void FUN_000513fc(void *p, int b);
struct Tag { char c; };
extern "C" void FUN_0006ea5c(Mgr *m, void **item, Tag t);
extern "C" void FUN_0006e9bc(void *sub, unsigned n);
extern "C" void FUN_0006dab0(float f, void *out, void *data, void *end);

extern Mgr *DAT_00331c2c;
extern float DAT_00331c34;
extern char DAT_002d12f4[];
extern char DAT_002d1304[];

extern "C" void FUN_0006d8e0(int p2, int p3, float scale)
{
  FUN_0006de30();
  int i;
  Mgr *p = new Mgr;
  DAT_00331c2c = p;
  i = 0;
  {
    int n = p->count;
    p->shrink(n);
  }
  char name[256];
  char name2[256];
  void *item;
  char out[20];
  do {
    FUN_000143b0(name, DAT_002d12f4, p2, i);
    FUN_000149a8(name2, name);
    FUN_00014788(name2, DAT_002d1304);
    int r = FUN_0004ccb8(name2, 1, 1);
    if (r < 0) {
      break;
    }
    FUN_0004cfd0(r);
    void *q = FUN_00000bcc(0x48);
    if (q != 0) {
      q = FUN_00050ff4(q, name, 1);
    }
    item = q;
    FUN_00051398(2000.0f, item);
    FUN_000513fc(item, 1);
    Mgr *m = DAT_00331c2c;
    if (m->count < m->cap) {
      m->count = m->count + 1;
      m->items[m->count - 1] = item;
    } else {
      FUN_0006ea5c(m, &item, Tag());
    }
    i++;
  } while (i < 100);
  DAT_00331c34 = scale;
  FUN_0006e9bc((int *)DAT_00331c2c + 3, p3);
  FUN_0006dab0(DAT_00331c34, out, DAT_00331c2c->data4, (char *)DAT_00331c2c->data4 + DAT_00331c2c->n3 * 0x70);
}
// NEAR MISS: 116/116 words, 9 differ.
// Diff 1 (4 words, +0x40): the ctor's `count = 0` store is sunk into the jal FUN_0006eaa0
//   delay slot (ours `sw zero,4(s0)` at +0x4c); retail keeps it BEFORE the call and puts
//   `sw zero,8(s0)` (cap = 0) in the delay slot.  Ruled out: ctor written as assignments vs
//   member-init list, `new Mgr` vs operator new + explicit `if (p)`, the stores split into a
//   second inline member, ctor body order permutations, `this->` qualification, a local
//   `this` copy, and the prototype taking void*.  MWCC always moves ONE pre-call store into
//   the delay slot; retail does not.
// Diff 2 (5 words, +0xe4): the final FUN_0006dab0 setup - retail loads the float global
//   DAT_00331c34 first (lwc1 $f12) and then the pointer global DAT_00331c2c into v0, reading
//   both fields from v0; ours loads the pointer global into v1 first and the float second.
//   Ruled out: reading the globals into named locals first, char* vs void* for data4, and
//   reordering the argument expressions.
// near miss from lane om1 (unreviewed)

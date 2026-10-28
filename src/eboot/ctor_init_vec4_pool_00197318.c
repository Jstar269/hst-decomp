/* HSTMATCH module=EBOOT.BIN start=0x00197318 end=0x00197458 symbol=FUN_00197318 lang=c99 */
/* Clone of src/sharing_main/ctor_init_vec4_pool_001a3c68.c (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the object and pool structs, restored the dropped this/float arguments of FUN_00197458, assigned the first allocation in the null test, merged the duplicated this[0x23] store; exact match verified; names and types await human review. */

typedef struct Vec4 { float x, y, z, w; } Vec4;

typedef struct Pool {
  void *first;
  char pad4[0x1b8];
  int f1bc;
} Pool;

typedef struct Obj {
  int f0;
  int pad4[3];
  Vec4 a;
  Vec4 b;
  Vec4 c;
  int f40;
  int f44;
  char pad48[8];
  unsigned short f50;
  char pad52[0x1e];
  int f70;
  int f74;
  char pad78[8];
  unsigned char f80;
  char pad81[3];
  int f84;
  unsigned char f88;
  char pad89[3];
  int f8c;
  int f90;
  int f94;
  int f98;
  int f9c;
} Obj;

extern Pool *DAT_00341768;
extern void *FUN_00000bcc(int);
extern void *FUN_00102e38(void *);
extern void FUN_00197458(Obj *, float, float);

Obj *FUN_00197318(Obj *o, int param_2)
{
  Pool *p;
  void *q;
  int i;
  int *w;

  o->f0 = param_2;
  o->a.x = 1.0f;
  o->a.y = 1.0f;
  o->a.z = 1.0f;
  o->a.w = 1.0f;
  o->b.x = o->a.x;
  o->b.y = o->a.y;
  o->b.z = o->a.z;
  o->b.w = o->a.w;
  o->c.x = o->b.x;
  o->c.y = o->b.y;
  o->c.z = o->b.z;
  o->c.w = o->b.w;
  FUN_00197458(o, 1.0f, 1.0f);
  o->f74 = 0;
  o->f70 = 0;
  o->f44 = 0;
  o->f40 = 0;
  o->f50 = 0xffff;
  o->f80 = 0;
  o->f84 = 0;
  o->f88 = 0;
  if (DAT_00341768 == 0) {
    if ((p = (Pool *)FUN_00000bcc(0x1c0)) != 0) {
      q = FUN_00000bcc(0x54);
      if (q != 0) {
        q = FUN_00102e38(q);
      }
      p->first = q;
      i = 0;
      w = (int *)p;
      do {
        w[1] = 0;
        w[2] = 0;
        w[3] = 0;
        w[4] = 0;
        w[5] = 0;
        i += 6;
        w[6] = 0;
        w += 6;
      } while (i < 30);
      p->f1bc = 0;
    }
    DAT_00341768 = p;
  }
  o->f8c = 0;
  o->f90 = 0;
  o->f94 = 0;
  o->f98 = 0;
  o->f9c = 0;
  return o;
}

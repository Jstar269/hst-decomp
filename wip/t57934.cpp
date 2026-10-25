/* HSTMATCH module=EBOOT.BIN start=0x00057934 end=0x00057b00 symbol=FUN_00057934 lang=c++ */
typedef unsigned int u32;
typedef unsigned char u8;
extern "C" void FUN_00058e50(int,u32*,int);
extern "C" void FUN_00057f30(u32*,int);

struct TS { u32 tex; u32 *ptr; u8 pad[0x10]; float val; };
struct Ctx { u8 pad0[0xe0]; u32 *tbl; u32 cnt; u8 pad1[8]; TS slot[2]; u8 pad2[0x20]; int lo; int hi; };

extern "C" int FUN_00057934(float f0, float f1, Ctx *c, u32 id0, u32 id1)
{
  u32 ids[2]; float vals[2];
  int changed = 0; int i = 0;
  u32 *ip; float *vp; TS *s;
  char *z;

  for (z = (char*)ids; z != (char*)ids+8;) *z++ = 0;
  ids[0]=id0; ids[1]=id1;
  for (z = (char*)vals; z != (char*)vals+8;) *z++ = 0;
  vals[0]=f0; vals[1]=f1;

  ip = ids; vp = vals; s = c->slot;
  do {
    u32 id = *ip;
    if (id != 0x7fff && s->tex != id) {
      s->tex = id;
      if ((int)id < 0) s->ptr = 0;
      else if (id < c->cnt) s->ptr = (u32*)*(u32*)(c->tbl + id);
      else s->ptr = 0;
      FUN_00058e50(0,(u32*)c,i);
      changed = 1;
      s->val = *vp;
    }
    i++; ip++; s++; vp++;
  } while (i < 2);
  if (changed) {
    c->lo = 0; c->hi = 0;
    u32 j = 0;
    do {
      if (c->slot[j].ptr != 0) {
        c->lo = ((int)j < c->lo) ? (int)j : c->lo;
        c->hi = (c->hi < (int)j) ? (int)j : c->hi;
      }
      j++;
    } while (j < 2);
    FUN_00057f30((u32*)c, *(int*)((char*)c + 0x180));
  }
  return changed;
}
// near miss from lane fm11 (unreviewed)

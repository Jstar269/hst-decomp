/* HSTMATCH module=hstp_trans_main.prx start=0x000d80f4 end=0x000d841c symbol=FUN_000d80f4 lang=c++ */
/* Clone of src/eboot/init_bone_tables_000d4430.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Pushes a new 72-byte object onto the pointer vector at +0x3c (inline push_back, out-of-line grow takes an empty tag), resizes the 32-byte record vector at +0x48 to 4 entries (pad-derived local record = 8 never-written bytes above it), then fills one record per player with seven bone indices (-1 when player, part or skeleton root is missing). The first loop is written as a do-while with an explicit pointer so the compiler keeps the rolled loop; names provisional. */
struct Tag {};
struct Obj;
struct PtrVec {
  Obj **data;
  unsigned size;
  unsigned cap;
  Obj **end() { return data + size; }
  Obj *&back() { return *(end() - 1); }
  void push_back(Obj *const &x);
};
extern "C" void FUN_0007021c(PtrVec *, Obj **, Tag);
inline void PtrVec::push_back(Obj *const &x)
{
  if (size < cap) {
    size++;
    back() = x;
  } else {
    FUN_0007021c(this, (Obj **)&x, Tag());
  }
}
struct Rec {
  int v[8];
};
struct RecP : Rec {
  int pad[2];
};
struct RecVec {
  Rec *data;
  unsigned size;
  Rec &at(unsigned i) { return data[i]; }
};
struct Self {
  char pad[0x3c];
  PtrVec items;
  RecVec recs;
};
struct Skel {
  char pad[8];
  void *root;
};
struct Mdl {
  char pad[0x8c];
  Skel *skel;
};
struct Part {
  char pad[0x58];
  Mdl *mdl;
};
struct Player {
  char pad[0x5bc];
  Part *part;
};
struct Game {
  char pad[0x70];
  Player *players[4];
};
extern "C" {
extern Game *DAT_003e19f0;
extern int DAT_0037d278[];
extern char DAT_0037d27c[];
extern char DAT_0037c8f8[];
extern char DAT_0037d28c[];
extern char DAT_0037c904[];
extern char DAT_0037d29c[];
extern char DAT_0037d2ac[];
extern char DAT_0037c928[];
void *FUN_00000bcc(unsigned);
Obj *FUN_00051908(void *, int, int);
void FUN_000d9498(RecVec *, unsigned, Rec *, Tag);
void FUN_000d9488(RecVec *, unsigned, Tag);
int FUN_0002fea8(void *, char *);

#pragma opt_strength_reduction off
void FUN_000d80f4(Self *self)
{
  unsigned k = 0;
  const int *src = DAT_0037d278;
  do {
    Obj *mem = (Obj *)FUN_00000bcc(0x48);
    if (mem) mem = FUN_00051908(mem, *src, 0);
    Obj *o = mem;
    self->items.push_back(o);
    k++;
    src++;
  } while (k == 0);
  unsigned n = self->recs.size;
  if (n < 4) {
    RecP r;
    for (int j = 0; j < 7; j++) r.v[j] = -1;
    r.v[7] = 0;
    FUN_000d9498(&self->recs, 4 - n, &r, Tag());
  } else if (4 < n) {
    FUN_000d9488(&self->recs, n - 4, Tag());
  }
  int i = 0;
  int off = 0;
  for (; i < 4; i++, off += 4) {
    Player *pl = *(Player **)((char *)DAT_003e19f0 + 0x70 + off);
    if (pl == 0) {
      Rec *r = &self->recs.at(i);
      r->v[0] = -1;
      r->v[1] = -1;
      r->v[2] = -1;
      r->v[3] = -1;
      r->v[4] = -1;
      r->v[5] = -1;
      r->v[6] = -1;
      r->v[7] = 0;
    } else {
      Part *x = pl->part;
      if (x == 0) {
        Rec *r = &self->recs.at(i);
        r->v[0] = -1;
        r->v[1] = -1;
        r->v[2] = -1;
        r->v[3] = -1;
        r->v[4] = -1;
        r->v[5] = -1;
        r->v[6] = -1;
        r->v[7] = 0;
      } else {
        int b0, b1, b2, b3, b4, b5, b6;
        void *root;
        root = x->mdl->skel->root;
        if (root != 0)
          b0 = FUN_0002fea8(root, DAT_0037d27c);
        else
          b0 = -1;
        root = x->mdl->skel->root;
        if (root != 0)
          b1 = FUN_0002fea8(root, DAT_0037c8f8);
        else
          b1 = -1;
        root = x->mdl->skel->root;
        if (root != 0)
          b2 = FUN_0002fea8(root, DAT_0037d28c);
        else
          b2 = -1;
        root = x->mdl->skel->root;
        if (root != 0)
          b3 = FUN_0002fea8(root, DAT_0037c904);
        else
          b3 = -1;
        root = x->mdl->skel->root;
        if (root != 0)
          b4 = FUN_0002fea8(root, DAT_0037d29c);
        else
          b4 = -1;
        root = x->mdl->skel->root;
        if (root != 0)
          b5 = FUN_0002fea8(root, DAT_0037d2ac);
        else
          b5 = -1;
        root = x->mdl->skel->root;
        if (root != 0)
          b6 = FUN_0002fea8(root, DAT_0037c928);
        else
          b6 = -1;
        Rec *r = &self->recs.at(i);
        r->v[0] = b0;
        r->v[1] = b1;
        r->v[2] = b2;
        r->v[3] = b3;
        r->v[4] = b4;
        r->v[5] = b5;
        r->v[6] = b6;
        r->v[7] = 0;
      }
    }
  }
}
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00106984 end=0x00106b04 symbol=FUN_00106984 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: restored the reserve size argument and the empty grow tag, modelled the sprite vector and its inline push_back, and wrote the allocation as `if ((mem = new) != 0)` with the inline ctor chain (base 0x518d4, then three vtable stores) followed by an address-taken copy for push_back; exact match verified; names and types await human review. */
/* sprite.cpp: assert(!m_is_sprite_created) (line 634), reserve room for n sprites when the vector is empty, then
   create n 0x9c-byte sprites, set their owner, initialise each from ids[i] (0x106324) and push it back (the
   full case goes to the out-of-line grow 0x10cdb0). The vtable stores stand in for the inline ctor chain. */
struct Tag {};
struct Sprite;
struct SpriteVec {
  Sprite **data;
  unsigned size;
  unsigned cap;
  Sprite *&at(unsigned i) { return data[i]; }
  Sprite *&back() { return at(size - 1); }
};
struct SpriteSet;
struct Sprite {
  void *vptr;
  char base[0x44];
  SpriteSet *owner;
  int index;
  void *f50;
  void *f54;
  unsigned char f58;
};
struct SpriteSet {
  int pad0;
  SpriteVec m_sprites;
  char pad10[0xc];
  unsigned char m_is_sprite_created;
};
extern "C" {
void FUN_0010532c(...);
extern char DAT_0037f75c[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_0037f854[]; /* "!m_is_sprite_created" */
extern char DAT_0037f7a4[]; /* "sprite.cpp" */
extern char DAT_003b0e04;
extern char DAT_003b0e24;
extern char DAT_003b0e78;
void *FUN_00000bcc(unsigned);
void *FUN_000518d4(void *);
void FUN_00106324(Sprite *, void *, int, int, int);
void FUN_0010cdb0(SpriteVec *, Sprite *const *, Tag);
void FUN_0010cdf4(SpriteVec *, unsigned);
}

extern "C" void FUN_00106984(SpriteSet *self, void *arg, int *ids, int n)
{
  if (self->m_is_sprite_created) {
    FUN_0010532c(DAT_0037f75c, DAT_0037f854, DAT_0037f7a4, 634);
    for (;;) {
    }
  }
  if (self->m_sprites.size == 0) {
    unsigned need = n + self->m_sprites.size;
    if (self->m_sprites.cap < need) {
      FUN_0010cdf4(&self->m_sprites, need);
    }
  }
  for (int i = 0; i < n; i++) {
    Sprite *mem;
    if ((mem = (Sprite *)FUN_00000bcc(0x9c)) != 0) {
      FUN_000518d4(mem);
      *(char **)mem = &DAT_003b0e24;
      mem->owner = 0;
      mem->index = -1;
      *(char **)mem = &DAT_003b0e78;
      mem->f50 = 0;
      *(char **)mem = &DAT_003b0e04;
      mem->f54 = 0;
      mem->f58 = 0;
    }
    Sprite *s = mem;
    s->owner = self;
    FUN_00106324(s, arg, ids[i], 0, 0);
    if (self->m_sprites.size < self->m_sprites.cap) {
      self->m_sprites.size++;
      self->m_sprites.data[self->m_sprites.size - 1] = s;
    } else {
      FUN_0010cdb0(&self->m_sprites, &s, Tag());
    }
  }
}

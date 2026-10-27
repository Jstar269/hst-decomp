/* HSTMATCH module=hstp_trans_main.prx start=0x0010c294 end=0x0010c2ec symbol=FUN_0010c294 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug build: the sprite.h GetSprite() assertion (line 1014, strings shared with src/sharing_main/sprite_pulse_00112a80.cpp) is
   kept; GetSprite(0) folds the first half of the test away, leaving `bgtzl count`. FUN_002910e4 sets the sprite colour alpha
   from a 30-entry byte table indexed by the counter at +0xd0 and advances the counter by the last argument. */
extern "C" void FUN_0010532c(...);
extern const char DAT_002d1384[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_002d1350[];   /* "sprite_index >= 0 && sprite_index < GetSpriteNum()" */
extern const char DAT_002d1344[];   /* "sprite.h" */
#define HST_ASSERT(cond, text, file, line) do { if (!(cond)) { FUN_0010532c(DAT_002d1384, text, file, line); for (;;) {} } } while (0)

struct Sprite;

struct SpriteSet {
    char pad0[0x10];
    Sprite **sprites;
    int count;
    int GetSpriteNum() const { return count; }
    Sprite *GetSprite(int sprite_index)
    {
        HST_ASSERT(sprite_index >= 0 && sprite_index < GetSpriteNum(), DAT_002d1350, DAT_002d1344, 1014);
        return sprites[sprite_index];
    }
};

struct Sub {
    int pad;
};

struct Obj {
    SpriteSet set;
    char pad18[0xd0 - 0x18];
    Sub sub;
};

extern "C" void FUN_002910e4(Sub *, Sprite *, int);

extern "C" void FUN_0010c294(Obj *self)
{
    FUN_002910e4(&self->sub, self->set.GetSprite(0), 1);
}

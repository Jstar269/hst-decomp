/* HSTMATCH module=hstp_trans_main.prx start=0x002af6b4 end=0x002af710 symbol=FUN_002af6b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tests bits 0-1 of the first sprite's flags through the sprite.h GetSprite() accessor (its line-1019 assertion is kept in this debug build; the index 0 folds the `>= 0` half), the same accessor as src/sharing_main/menu_state_update_0017d1d4.cpp with this file's stub FUN_002ad710. */
extern "C" void FUN_002ad710(...);
extern const char DAT_002d0090[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_002d005c[];   /* "sprite_index >= 0 && sprite_index < GetSpriteNum()" */
extern const char DAT_002d0050[];   /* "sprite.h" */
#define HST_ASSERT(cond, text, file, line) do { if (!(cond)) { FUN_002ad710(DAT_002d0090, text, file, line); for (;;) {} } } while (0)

struct Sprite { char pad0[0xe]; unsigned short flags; };

struct SpriteSet {
    char pad0[0x10];
    Sprite **sprites;
    int count;
    int GetSpriteNum() const { return count; }
    Sprite *GetSprite(int sprite_index)
    {
        HST_ASSERT(sprite_index >= 0 && sprite_index < GetSpriteNum(), DAT_002d005c, DAT_002d0050, 1019);
        return sprites[sprite_index];
    }
};

struct Screen {
    char pad0[0x54];
    SpriteSet *set;
};

extern "C" bool FUN_002af6b4(Screen *s)
{
    return (s->set->GetSprite(0)->flags & 3) != 0;
}

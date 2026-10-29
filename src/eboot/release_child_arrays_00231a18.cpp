/* HSTMATCH module=EBOOT.BIN start=0x00231a18 end=0x00231b08 symbol=FUN_00231a18 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: ordered the typed cursor and count locals to match both virtual cleanup walks; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_menu.h"

extern "C" {
extern u8 DAT_00309878;
extern void FUN_00000a00(...);
extern u32 * FUN_00102ea4(...);
}
struct CharWidget { virtual ~CharWidget(); };
struct ExtraWidget { virtual ~ExtraWidget(); };

/* Deleting destructor of the challenge menu: delete the character and extra widgets, then run the base destructor. */
extern "C" ChallengeMenu * FUN_00231a18(ChallengeMenu *self,short flags)
{
  CharWidget *widget;
  int i;
  ChallengeMenu *cursor;  /* moved on by one word per step so chars[0]/extras[0] walk the arrays */
  
  if (self != (ChallengeMenu *)0x0) {
    self->vtable = (unsigned int)(&DAT_00309878);
    i = 0;
    cursor = self;
    do {
      widget = (CharWidget *)cursor->chars[0];
      if (widget != (CharWidget *)0x0) {
        delete widget;
        cursor->chars[0] = 0;
      }
      i = i + 1;
      cursor = (ChallengeMenu *)((u32 *)cursor + 1);
    } while (i < CHALLENGE_CHARS);
    i = 0;
    cursor = self;
    do {
      ExtraWidget *extra = (ExtraWidget *)cursor->extras[0];
      if (extra != (ExtraWidget *)0x0) {
        delete extra;
        cursor->extras[0] = 0;
      }
      i = i + 1;
      cursor = (ChallengeMenu *)((u32 *)cursor + 1);
    } while (i < CHALLENGE_EXTRAS);
    FUN_00102ea4(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}

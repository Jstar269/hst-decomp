/* HSTMATCH module=EBOOT.BIN start=0x00170ebc end=0x00170f08 symbol=FUN_00170ebc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Sprite {
  char pad00[0x60];
  float x;                    /* 0x60 */
  float y;                    /* 0x64 */
} Sprite;

typedef struct Screen {
  char pad00[4];
  Sprite **sprites;           /* 0x04 first entry is the main sprite */
  char pad08[0x74 - 8];
  float scale_x;              /* 0x74 */
  float scale_y;              /* 0x78 */
} Screen;

extern Screen *DAT_003415ac;

/* Resets the screen object to unit scale with its main sprite at the screen centre (480x272). */
void FUN_00170ebc(void)
{
  Screen *screen;
  
  screen = DAT_003415ac;
  if (DAT_003415ac != 0) {
    DAT_003415ac->scale_x = 1.0f;
    screen->scale_y = 1.0f;
    screen = DAT_003415ac;
    (*DAT_003415ac->sprites)->x = 240.0f;
    (*screen->sprites)->y = 136.0f;
  }
}

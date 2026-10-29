/* HSTMATCH module=hstp_trans_main.prx start=0x0017d188 end=0x0017d1d4 symbol=FUN_0017d188 lang=c99 */
/* Clone of src/eboot/FUN_00170ebc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

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

extern Screen *DAT_003ea8ec;

/* Resets the screen object to unit scale with its main sprite at the screen centre (480x272). */
void FUN_0017d188(void)
{
  Screen *screen;
  
  screen = DAT_003ea8ec;
  if (DAT_003ea8ec != 0) {
    DAT_003ea8ec->scale_x = 1.0f;
    screen->scale_y = 1.0f;
    screen = DAT_003ea8ec;
    (*DAT_003ea8ec->sprites)->x = 240.0f;
    (*screen->sprites)->y = 136.0f;
  }
}

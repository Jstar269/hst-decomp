/* HSTMATCH module=EBOOT.BIN start=0x001e521c end=0x001e532c symbol=FUN_001e521c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

enum { PANEL_COUNT = 4 };

typedef struct Panel {
  char pad00[0x20];
  int color;               /* 0x20 */
  char pad24[0x8c - 0x24];
} Panel;                   /* size 0x8c */

typedef struct Self {
  char pad000[0x270];
  int unk270;              /* 0x270 */
  char pad274[0x438 - 0x274];
  unsigned char dirty;     /* 0x438 set so the colours are refreshed */
  char pad439[0x4c8 - 0x439];
  Panel panels[PANEL_COUNT]; /* 0x4c8 */
} Self;

extern char DAT_002ec180[];
extern float FUN_000657e4(int, char *, int);
extern void FUN_000ffb3c(int, int);
extern int FUN_001ee224();
extern void FUN_0021780c(void *, int, float, float);
extern void FUN_00217834(void *, int, int, int);

/* Mark the panels dirty and set up panels 0..3 (the first three from a config value, the fourth fixed). */
void FUN_001e521c(Self *self)
{
  int color;
  float value;

  self->dirty = 1;
  color = self->panels[0].color;
  value = FUN_000657e4(FUN_001ee224(), DAT_002ec180, 1);
  FUN_00217834(&self->panels[0], color, -1, (int)value);
  color = self->panels[2].color;
  value = FUN_000657e4(FUN_001ee224(), DAT_002ec180, 1);
  FUN_00217834(&self->panels[2], color, -1, (int)value);
  color = self->panels[1].color;
  value = FUN_000657e4(FUN_001ee224(), DAT_002ec180, 1);
  FUN_00217834(&self->panels[1], color, -1, (int)value);
  FUN_000ffb3c(self->unk270, 0);
  FUN_0021780c(&self->panels[3], 0x19, 1.0f, 2.0f);
  FUN_00217834(&self->panels[3], -1, self->panels[3].color & 0xffffff, 0x19);
}

/* HSTMATCH module=EBOOT.BIN start=0x002a22d8 end=0x002a234c symbol=FUN_002a22d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct ShortRect {
  char pad00[4];
  short x0;         /* 0x04 */
  short y0;         /* 0x06 */
  short x1;         /* 0x08 */
  short y1;         /* 0x0a */
} ShortRect;

/* Scales a rectangle's horizontal coordinates by scale_x and its vertical ones by scale_y. */
void FUN_002a22d8(float scale_x,float scale_y,ShortRect *rect)
{
  rect->x0 = (short)(int)((float)(int)rect->x0 * scale_x);
  rect->x1 = (short)(int)((float)(int)rect->x1 * scale_x);
  rect->y0 = (short)(int)((float)(int)rect->y0 * scale_y);
  rect->y1 = (short)(int)((float)(int)rect->y1 * scale_y);
}

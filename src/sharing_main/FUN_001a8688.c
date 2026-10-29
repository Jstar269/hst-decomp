/* HSTMATCH module=hstp_trans_main.prx start=0x001a8688 end=0x001a86fc symbol=FUN_001a8688 lang=c99 */
/* Clone of src/eboot/FUN_002a22d8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

typedef struct ShortRect {
  char pad00[4];
  short x0;         /* 0x04 */
  short y0;         /* 0x06 */
  short x1;         /* 0x08 */
  short y1;         /* 0x0a */
} ShortRect;

/* Scales a rectangle's horizontal coordinates by scale_x and its vertical ones by scale_y. */
void FUN_001a8688(float scale_x,float scale_y,ShortRect *rect)
{
  rect->x0 = (short)(int)((float)(int)rect->x0 * scale_x);
  rect->x1 = (short)(int)((float)(int)rect->x1 * scale_x);
  rect->y0 = (short)(int)((float)(int)rect->y0 * scale_y);
  rect->y1 = (short)(int)((float)(int)rect->y1 * scale_y);
}

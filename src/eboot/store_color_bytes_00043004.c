/* HSTMATCH module=EBOOT.BIN start=0x00043004 end=0x00043150 symbol=FUN_00043004 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Vec4 {
  float x, y, z, w;
} Vec4;

/* Stores a float colour (passed by value, copied into the frame) as four
   bytes scaled by 128 at +0x68..+0x6b (callers: FUN_00197464, FUN_001975d4). */
void FUN_00043004(unsigned char *o, Vec4 c)
{
  o[0x68] = (unsigned char)(c.x * 128.0f);
  o[0x69] = (unsigned char)(c.y * 128.0f);
  o[0x6a] = (unsigned char)(c.z * 128.0f);
  o[0x6b] = (unsigned char)(c.w * 128.0f);
}

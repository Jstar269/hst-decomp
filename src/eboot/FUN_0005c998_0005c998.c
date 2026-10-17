/* HSTMATCH module=EBOOT.BIN start=0x0005c998 end=0x0005c9dc symbol=FUN_0005c998 lang=c99 */
/* Clone of src/sharing_main/FUN_0005d724_0005d724.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char pad[0x18]; int count; float *data; } FloatBuffer;
void FUN_0005c998(FloatBuffer *self, int index, float *source)
{
  if (index < self->count) {
    float *dst = self->data + index * 8;
    dst[4] = source[0];
    dst[5] = source[1];
    dst[6] = source[2];
    dst[7] = source[3];
  }
}

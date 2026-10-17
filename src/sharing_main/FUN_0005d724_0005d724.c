/* HSTMATCH module=hstp_trans_main.prx start=0x0005d724 end=0x0005d768 symbol=FUN_0005d724 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char pad[0x18]; int count; float *data; } FloatBuffer;
void FUN_0005d724(FloatBuffer *self, int index, float *source)
{
  if (index < self->count) {
    float *dst = self->data + index * 8;
    dst[4] = source[0];
    dst[5] = source[1];
    dst[6] = source[2];
    dst[7] = source[3];
  }
}

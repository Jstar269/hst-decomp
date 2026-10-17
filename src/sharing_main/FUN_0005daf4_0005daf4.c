/* HSTMATCH module=hstp_trans_main.prx start=0x0005daf4 end=0x0005dbe0 symbol=FUN_0005daf4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Hand-written experiment. */
typedef struct { char pad[0x20]; int count; float *data; } FloatTable;
void FUN_0005daf4(FloatTable *self, int index, float *out0, float *out1, float *out2, float *out3, float *out4)
{
  if (index < self->count) {
    if (out0 != 0) {
      float *base = self->data;
      float *row = (float *)(base + index * 16);
      out0[0] = row[0]; out0[1] = row[1]; out0[2] = row[2]; out0[3] = row[3];
    }
    if (out1 != 0) {
      float *base = self->data;
      float *row = (float *)(base + index * 16);
      out1[0] = row[4]; out1[1] = row[5]; out1[2] = row[6]; out1[3] = row[7];
    }
    if (out2 != 0) {
      float *base = self->data;
      float *row = (float *)(base + index * 16);
      out2[0] = row[8]; out2[1] = row[9]; out2[2] = row[10]; out2[3] = row[11];
    }
    if (out3 != 0) {
      float value = self->data[index * 16 + 12];
      out3[0] = value;
    }
    if (out4 != 0) {
      float value = self->data[index * 16 + 13];
      out4[0] = value;
    }
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x000f1b38 end=0x000f1b6c symbol=FUN_000f1b38 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The `self->f94 = x;` store must come BEFORE the call in the source: mwcc then sinks it into the `jal`
   delay slot and keeps no saved register for self. Writing the store after the call keeps `self` live
   across it (an s0 save, 17 words vs retail's 13). */
typedef struct Self {
    char pad0[144];
    float f90;                   /* 144 */
    float f94;                   /* 148 */
} Self;
extern float DAT_002d7800;
void FUN_000f1b6c(Self *self, float v);

void FUN_000f1b38(Self *self, int flag, float v)
{
    self->f90 = v * DAT_002d7800;
    if (flag != 0) {
        float x = self->f90;
        self->f94 = x;
        FUN_000f1b6c(self, x);
    }
}

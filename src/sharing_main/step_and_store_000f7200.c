/* HSTMATCH module=hstp_trans_main.prx start=0x000f7200 end=0x000f7234 symbol=FUN_000f7200 lang=c99 */
/* Clone of src/eboot/step_and_store_000f1b38.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The `self->f94 = x;` store must come BEFORE the call in the source: mwcc then sinks it into the `jal`
   delay slot and keeps no saved register for self. Writing the store after the call keeps `self` live
   across it (an s0 save, 17 words vs retail's 13). */
typedef struct Self {
    char pad0[144];
    float f90;                   /* 144 */
    float f94;                   /* 148 */
} Self;
extern float DAT_0037e5d8;
void FUN_000f7234(Self *self, float v);

void FUN_000f7200(Self *self, int flag, float v)
{
    self->f90 = v * DAT_0037e5d8;
    if (flag != 0) {
        float x = self->f90;
        self->f94 = x;
        FUN_000f7234(self, x);
    }
}

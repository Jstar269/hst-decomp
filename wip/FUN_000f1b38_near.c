/* HSTMATCH module=EBOOT.BIN start=0x000f1b38 end=0x000f1b6c symbol=FUN_000f1b38 lang=c99 */
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
        FUN_000f1b6c(self, self->f90);
        self->f94 = self->f90;
    }
}
// near miss from lane dsn3 (unreviewed)

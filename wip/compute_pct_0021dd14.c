/* HSTMATCH module=EBOOT.BIN start=0x0021dd14 end=0x0021de38 symbol=FUN_0021dd14 lang=c99 */
extern int *DAT_0034b5d4;
extern int FUN_002af920(int arg);
extern void FUN_002afa48(int *pIdx, void *zero, int val);
extern void FUN_0021df6c(void *self, int idx);
extern void FUN_0021e090(void *self, float pct);
struct Obj_0021dd14 { char pad[0x170]; int f170; char pad2[0x1f0-0x174]; int f1F0; int f1F4; int f1F8; int f1FC; int f200; };
#define VAL(i) ((float)(DAT_0034b5d4[(i) * 2] >> 4))
void FUN_0021dd14(struct Obj_0021dd14 *self)
{
    float fVar2;
    int idx;
    self->f1F8 = FUN_002af920(self->f170);
    self->f200 = self->f1F8;
    self->f1FC = self->f1F8;
    FUN_002afa48(&idx, 0, self->f1F8);
    FUN_0021df6c(self, idx);
    if (idx < 0) fVar2 = 0.0f;
    else if (idx < 0x1e) fVar2 = VAL(idx);
    else fVar2 = 0.0f;
    self->f1F0 = (int)fVar2;
    idx = idx + 1;
    if (idx >= 0 && idx < 0x1e) fVar2 = VAL(idx);
    else fVar2 = 0.0f;
    self->f1F4 = (int)fVar2;
    FUN_0021e090(self, (float)(self->f200 - self->f1F0) * 100.0f / (float)((int)(fVar2) - self->f1F0));
}
// improved by lane rt2 (unreviewed): 30 -> 26 differing words

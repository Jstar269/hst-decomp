/* HSTMATCH module=EBOOT.BIN start=0x00125c4c end=0x00125d38 symbol=FUN_00125c4c lang=c99 */
struct C { char pad0[88]; int f58; char pad5c[4]; float f60; int f64; char pad68[16]; char f78; char pad79[23]; int f90; };
extern void FUN_0001f1fc(struct C *self, int on);
extern void FUN_001258bc(struct C *self, int a);
extern char *DAT_003386b0;
extern char *DAT_00340284;

void FUN_00125c4c(struct C *self, float v)
{
  float cur;
  self->f64 = 0;
  cur = self->f60;
  if (v == cur)
    return;
  if (cur > 0.0f) {
    if (v > 0.0f) {
      self->f90 = *(int *)(*(int *)(DAT_003386b0 + 156) + 88);
      *(int *)(DAT_00340284 + 296) = 0;
      *(int *)(DAT_00340284 + 300) = 1;
      FUN_001258bc(self, self->f58);
      FUN_0001f1fc(self, 1);
      self->f78 = 1;
    } else {
      FUN_0001f1fc(self, 0);
      self->f78 = 0;
    }
  }
  self->f60 = v;
}
// near miss from lane dsn3 (unreviewed)

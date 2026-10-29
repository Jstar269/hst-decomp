/* HSTMATCH module=EBOOT.BIN start=0x00170d9c end=0x00170ebc symbol=FUN_00170d9c lang=c99 */
struct Pair { short a, b; };
extern char DAT_00341a10;
extern unsigned char DAT_00341aac, DAT_00341aad, DAT_00341aae, DAT_00341aaf;
extern signed char DAT_00341ab0;
extern float DAT_00341ab4, DAT_00341ab8, DAT_00341abc, DAT_00341ac0, DAT_00341ac4;
extern int DAT_00341ac8;
extern struct Pair DAT_00341acc[3];
extern char *DAT_003386c8;
extern void *FUN_0016b164(char *self);
extern void FUN_001c184c(int a, void *b, int c);
extern void FUN_00097b2c(void *dst, void *src);

void FUN_00170d9c(char *self)
{
  char *s;
  void *r;
  int i;
  r = FUN_0016b164(self);
  r = ((void *(*)(void *))*(void **)(self + 0x3e8))(r);
  FUN_001c184c(0, r, *(int *)(self + 0x8c));
  if (DAT_003386c8 == 0)
    return;
  s = *(char **)(DAT_003386c8 + 0x40) + 0x648;
  FUN_00097b2c(s, &DAT_00341a10);
  *(unsigned char *)(s + 0x9c) = DAT_00341aac;
  *(unsigned char *)(s + 0x9d) = DAT_00341aad;
  *(unsigned char *)(s + 0x9e) = DAT_00341aae;
  *(unsigned char *)(s + 0x9f) = DAT_00341aaf;
  *(signed char *)(s + 0xa0) = DAT_00341ab0;
  *(float *)(s + 0xa4) = DAT_00341ab4;
  *(float *)(s + 0xa8) = DAT_00341ab8;
  *(float *)(s + 0xac) = DAT_00341abc;
  *(float *)(s + 0xb0) = DAT_00341ac0;
  *(float *)(s + 0xb4) = DAT_00341ac4;
  *(int *)(s + 0xb8) = DAT_00341ac8;
  for (i = 0; i < 3; i++)
    ((struct Pair *)(s + 0xbc))[i] = DAT_00341acc[i];
}
// near miss from lane dsn3 (unreviewed)

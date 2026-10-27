/* HSTMATCH module=hstp_trans_main.prx start=0x00198c8c end=0x00198e40 symbol=FUN_00198c8c lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: explicit cursors pcg/pobj over the two 15-entry global tables, stepped in the for-increment and declared in the order i, j, tex, obj, pcg, src, dst, pobj (the assert text shows the original indexed g_pDefCGData[i]; the indexed form leaves the table induction pointer in s0, 9 words off); exact match verified; names and types await human review. */
/* prerender.cpp (Sharing debug build): load data/menu/chrselect/def_NN.bin for NN = 0..14 into g_pDefCGData[NN]
   (DAT_003ea870, assert at line 764) and copy each 64x128-byte image into a new 0x48-byte object "PreDNN"
   (table DAT_003ea8ac), bracketed by FUN_0001c5f4/FUN_0001c73c(&DAT_003b7ebc, "menu/chrsel_020_prerender.xb"). */
extern void *DAT_003ea870[15];                  /* g_pDefCGData */
extern void *DAT_003ea8ac[15];
extern char DAT_003b7ebc[];
extern char DAT_00388244[];                     /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00388280[];                     /* "prerender.cpp" */
extern char DAT_00388290[];                     /* "menu/chrsel_020_prerender.xb" */
extern char DAT_003882b0[];                     /* "%sdef_%02d.bin" */
extern char DAT_003882c0[];                     /* "data/menu/chrselect/" */
extern char DAT_003882d8[];                     /* "g_pDefCGData[i]" */
extern char DAT_003882e8[];                     /* "PreD%02d" */
extern void FUN_0001c5f4(void *, const char *);
extern void FUN_0001c73c(void *);
extern int FUN_000143b0(char *, const char *, ...);
extern void *FUN_0004cd8c(const char *, int, int, int);
extern void FUN_00197f88(const char *, ...);
extern void *FUN_0004eaf8(int *, int *, int, int, int, int);
extern void *FUN_00000bcc(unsigned int);
extern void *FUN_00051964(void *, const char *, void *, int);
extern char *FUN_00051df0(void *);
extern void *FUN_00011090(void *, const void *, unsigned int);

void FUN_00198c8c(void)
{
  if (DAT_003ea870[0] == 0) {
    char path[64];
    int w;
    int h;
    char name[64];
    int i;
    int j;
    void *tex;
    void *obj;
    void **pcg;
    char *src;
    char *dst;
    void **pobj;
    w = 0;
    h = 0;
    FUN_0001c5f4(DAT_003b7ebc, DAT_00388290);
    for (i = 0, pcg = DAT_003ea870, pobj = DAT_003ea8ac; i < 15; i++, pcg++, pobj++) {
      FUN_000143b0(path, DAT_003882b0, DAT_003882c0, i);
      *pcg = FUN_0004cd8c(path, 0, 16, 1);
      src = *pcg;
      if (!*pcg) {
        FUN_00197f88(DAT_00388244, DAT_003882d8, DAT_00388280, 764);
        for (;;) {}
      }
      if (src) {
        FUN_000143b0(name, DAT_003882e8, i);
        tex = FUN_0004eaf8(&w, &h, 1, 0, 64, 64);
        obj = FUN_00000bcc(0x48);
        if (obj) obj = FUN_00051964(obj, name, tex, 0);
        dst = FUN_00051df0(obj);
        for (j = 0; j < 64; j++) {
          FUN_00011090(dst, src, 128);
          src += 128;
          dst += 128;
        }
        *pobj = obj;
      }
    }
    FUN_0001c73c(DAT_003b7ebc);
  }
}

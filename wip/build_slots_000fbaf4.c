/* HSTMATCH module=EBOOT.BIN start=0x000fbaf4 end=0x000fbbf8 symbol=FUN_000fbaf4 lang=c99 */
extern void *FUN_00000bcc(unsigned size);
extern void *FUN_00050fc0(void *mem, char *name);
extern void FUN_000511c4(void *obj, char *name, int flag);
extern void FUN_00051398(void *obj, float value);
extern void FUN_00102e38(void *obj);
extern void FUN_00104118(void *obj, char *name, int flag);
extern void FUN_00103540(void *obj, float value);
extern void FUN_001037c8(void *obj, int mode);
extern void FUN_00103628(void *obj, int flag);
extern unsigned char DAT_003386b8;
extern char DAT_002d8324[];
extern char *DAT_002c0d5c[];
void FUN_000fbaf4(char *self)
{
    if (DAT_003386b8 != 0) {
        int i = 0;
        char *slot = self;
        char **src = DAT_002c0d5c;
        do {
            void *obj = FUN_00000bcc(72);
            if (obj != 0)
                obj = FUN_00050fc0(obj, src[i]);
            *(void **)(slot + 64) = obj;
            FUN_000511c4(obj, src[i], 0);
            FUN_00051398(obj, 100000.0f);
            i++;
            slot += 4;
        } while (i < 6);
        void *q = FUN_00000bcc(84);
        if (q != 0) {
            FUN_00102e38(q);
            *(void **)(self + 0x3c) = q;
            FUN_00104118(q, DAT_002d8324, 0);
            FUN_00103540(q, 100000.0f);
            FUN_001037c8(q, -1);
            FUN_00103628(q, 1);
        }
    }
}
// NEAR MISS: 71/65 words. Structure right (flag guard, 6x {alloc 72, ctor(o,name), store at +64, two
// setters}, 100000.0f constant, q block with 84-byte ctor chain); ours keeps the new object in s4 and
// duplicates the store into both arms of `if (obj)` where retail branches on v0 and stores once at the
// join. Ruled out: typed pointer, inline New() helper (MISPLACED), index-form slot store.
// near miss from lane ds11 (unreviewed)

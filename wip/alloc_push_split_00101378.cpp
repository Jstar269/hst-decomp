/* NEAR 103/92 words. First source for 0x00101378 (previously unattempted).
   Shares the 0x00101220 vector/factory idiom: same empty+grow guard
   (`if (v->count == 0 && cap < n) FUN_00107034(&v->data)`), same 0x9c allocation with
   the three chained vtable stores and `item[0x12] = v`, then per entry strcpy into a
   256-byte buffer, strrchr/split on '/', strcpy the tail into a second 256-byte buffer,
   clear *(slash+1), call FUN_00100a1c(item, buf1, buf2, 0, 0) and push inline or via
   FUN_00106ff0(&v->data, &item, 0) (three arguments here, unlike 0x00101220).
   Remaining: 11 words and two extra saved registers; retail uses s0-s4 only and a
   560-byte frame (ours 576). */
/* HSTMATCH module=EBOOT.BIN start=0x00101378 end=0x001014e8 symbol=FUN_00101378 lang=c++ */
struct Vec {
    void *unk0;
    void **data;
    int count;
    int cap;
};
extern "C" char DAT_00307b58[];
extern "C" char DAT_00307bac[];
extern "C" char DAT_00307b38[];
extern "C" void *FUN_00000bcc(int);
extern "C" void FUN_00050fc0(void *);
extern "C" void FUN_00100a1c(void *, char *, char *, int, int);
extern "C" void FUN_00107034(void **);
extern "C" void FUN_00106ff0(void **, void **, int);
extern "C" void FUN_000149a8(char *, const char *);
extern "C" char *FUN_00014cfc(char *, int);

extern "C" void FUN_00101378(struct Vec *v, const char **names, unsigned n)
{
    unsigned i;
    char buf1[256];
    char buf2[256];
    int *item;
    char *slash;

    if (v->count == 0 && (unsigned)v->cap < n)
        FUN_00107034((void **)&v->data);
    for (i = 0; i < n; i++, names++) {
        item = (int *)FUN_00000bcc(0x9c);
        if (item != 0) {
            FUN_00050fc0(item);
            item[0] = (int)DAT_00307b58;
            item[0x12] = 0;
            item[0x13] = -1;
            item[0] = (int)DAT_00307bac;
            item[0x14] = 0;
            item[0] = (int)DAT_00307b38;
            item[0x15] = 0;
            *(char *)(item + 0x16) = 0;
        }
        FUN_000149a8(buf1, *names);
        slash = FUN_00014cfc(buf1, '/');
        FUN_000149a8(buf2, slash + 1);
        *(slash + 1) = 0;
        item[0x12] = (int)v;
        FUN_00100a1c(item, buf1, buf2, 0, 0);
        if (v->count < v->cap) {
            v->count = v->count + 1;
            v->data[v->count - 1] = item;
        } else {
            FUN_00106ff0((void **)&v->data, (void **)&item, 0);
        }
    }
}
// near miss from lane fm6 (unreviewed)

/* NEAR 90/86 words. First source for 0x00101220 (previously unattempted).
   Structure is right: empty-check + grow (`if (v->count == 0 && v->cap < n)
   FUN_00107034(&v->data);`), then the allocation loop with the three chained vtable
   stores, `item[0x12] = (int)v`, the FUN_00100a1c call with (param_2, pair[0], pair[1],
   param_5) and the push (`v->data[v->count] = item; v->count++;` inline when
   count < cap, else FUN_00106ff0(&v->data, &item)`).
   Remaining: 4 words and two extra saved registers (s7/s8) - our version keeps the
   push target and the loop's pair pointer live differently; retail uses s0-s6 only.
   Ruled out so far: dropping the separate `p` local (96 words, worse). */
/* HSTMATCH module=EBOOT.BIN start=0x00101220 end=0x00101378 symbol=FUN_00101220 lang=c++ */
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
extern "C" void FUN_00100a1c(void *, int, int, int, int);
extern "C" void FUN_00107034(void **);
extern "C" void FUN_00106ff0(void **, void **);

extern "C" void FUN_00101220(struct Vec *v, int param_2, int *param_3, int param_4, int param_5)
{
    int i;
    int *p;

    if (v->count == 0 && (unsigned)v->cap < (unsigned)param_4)
        FUN_00107034((void **)&v->data);
    for (i = 0; i < param_4; i++, param_3 += 2) {
        int *item = (int *)FUN_00000bcc(0x9c);
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
        p = item;
        item[0x12] = (int)v;
        FUN_00100a1c(item, param_2, param_3[0], param_3[1], param_5);
        if (v->count < v->cap) {
            v->data[v->count] = item;
            v->count = v->count + 1;
        } else {
            FUN_00106ff0((void **)&v->data, (void **)&p);
        }
    }
}
// near miss from lane fm6 (unreviewed)

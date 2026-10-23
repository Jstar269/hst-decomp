/* HSTMATCH module=EBOOT.BIN start=0x0020507c end=0x002052b8 symbol=FUN_0020507c lang=c99 */
extern void FUN_0001ca58(int *, char *, int);
extern void FUN_00206640(void *, int);
extern void FUN_000143b0(char *, char *, ...);
extern int FUN_00000bcc(int);
extern int FUN_00055dd0(int);
extern void FUN_00055eac(int, char *, int);
extern void FUN_000b42b4(void *, int *, char);
extern void FUN_00092e50(int *, int, char *, char *, int, int);
extern void FUN_0001cb88(int *);
extern int DAT_0030ebf4;
extern char DAT_002ef66c[];
extern char *DAT_002ef598[];
extern char DAT_002ef5dc[];
extern char DAT_002ef600[];
extern char DAT_002ef688[];

struct Obj20507c {
    int *owner;
    char pad0[8];
    int *data;
    unsigned int count;
    unsigned int cap;
    char pad1[0x54];
    unsigned char f6c;
};

void FUN_0020507c(struct Obj20507c *p, int param_2)
{
    int flag;
    int i;
    char **namep;
    int handle;
    char bufP[64];
    char bufN[256];
    char bufM[256];
    int local;

    flag = *(int *)((char *)p->owner + 0x50);
    FUN_0001ca58(&DAT_0030ebf4, DAT_002ef66c, param_2);
    if (p->cap < 6)
        FUN_00206640(&p->data, 6);
    i = 0;
    namep = DAT_002ef598;
    do {
        FUN_000143b0(bufP, *namep, param_2);
        switch (i) {
        case 2:
        case 3:
        case 4:
        case 5:
            FUN_000143b0(bufN, DAT_002ef5dc, 99, bufP);
            break;
        default:
            FUN_000143b0(bufN, DAT_002ef5dc, param_2, bufP);
            break;
        }
        handle = FUN_00000bcc(0x10);
        if (handle != 0)
            handle = FUN_00055dd0(handle);
        local = handle;
        FUN_00055eac(local, bufN, 0);
        if (p->count < p->cap) {
            handle = p->count + 1;
            p->count = handle;
            p->data[handle - 1] = local;
        } else {
            FUN_000b42b4(&p->data, &local, (char)0);
        }
        if (flag != 0) {
            switch (i) {
            case 2:
            case 3:
            case 4:
            case 5:
                FUN_000143b0(bufN, DAT_002ef600, 99, bufP);
                break;
            default:
                FUN_000143b0(bufN, DAT_002ef600, param_2, bufP);
                break;
            }
            FUN_000143b0(bufM, DAT_002ef688, param_2);
            FUN_00092e50(p->owner, i, bufN, bufM, 0, p->f6c);
        }
        i++;
        namep++;
    } while (i < 6);
    FUN_0001cb88(&DAT_0030ebf4);
}
// 142/143 words, 60 differ but only two deltas (everything else is shifted by the missing word):
// (1) the container-full arm: retail materialises the third (char) argument as `move v0,zero`
//     in the `beqzl` delay slot and then `seb a2,v0`; this MWCC folds a literal 0 argument to a
//     bare `move a2,zero`, so the arm is one word short. Tried: `char`/`signed char` parameter,
//     `(char)0` argument - both still fold.
// (2) the `beqql s0,...` increment hop is 4 bytes later, purely from (1).
// Everything else - the 5 saved registers, the stack layout (local sp+44, M sp+48, N sp+304,
// P sp+560), the `switch (i) case 2..5` dispatch both times, the container push, and the
// `local = handle` conversion - is byte-identical.
// near miss from lane fm8 (unreviewed)

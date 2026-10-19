/* HSTMATCH module=hstp_trans_main.prx start=0x00242dc4 end=0x00242f2c symbol=FUN_00242dc4 lang=c99 */
/* Clone of src/eboot/init_challenge_lobby_00232cc4.c (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured Obj/Inner, unified alloc/ctor idiom, loop typing; exact match verified; names and types await human review. */

extern char DAT_003b7ebc;
extern char DAT_0039c6e8[];
extern char DAT_0039c73c[];
extern char DAT_0039c758[];
extern char DAT_0039c774[];
extern void *DAT_003f3458;

extern void *FUN_00000bcc(unsigned int);
extern void FUN_000143b0(char *, const char *, ...);
extern void FUN_0001c5f4(void *, const char *);
extern void FUN_0001c684(void *, int, const char *);
extern void FUN_0001c73c(void *);
extern void *FUN_000518d4(void *);
extern void FUN_00051ad8(void *, const char *, int);
extern void FUN_00051d38(void *, float);
extern void *FUN_0022f648(void *);
extern void *FUN_00230474(void *);
extern void *FUN_0024177c(void *);
extern void FUN_002bf5d0(void *, int);
extern void FUN_002bf730(int);

typedef struct {
    void *p0;
    void *p1;
    void *p2;
} Obj;

typedef struct {
    char pad[0x1a8];
    void *items[10];
} Inner;

void FUN_00242dc4(Obj *param_1)
{
    char buf[256];
    void *p0;
    void *p1;
    void *p2;
    Inner *s0;
    int s1;
    void *item;

    FUN_0001c684(&DAT_003b7ebc, 1, DAT_0039c73c);

    p0 = FUN_00000bcc(752);
    if (p0)
        p0 = FUN_0024177c(p0);
    param_1->p0 = p0;

    p1 = FUN_00000bcc(120);
    if (p1)
        p1 = FUN_0022f648(p1);
    param_1->p1 = p1;

    p2 = FUN_00000bcc(160);
    if (p2)
        p2 = FUN_00230474(p2);
    param_1->p2 = p2;

    FUN_0001c73c(&DAT_003b7ebc);
    FUN_0001c5f4(&DAT_003b7ebc, DAT_0039c758);

    s0 = (Inner *)param_1->p0;
    for (s1 = 0; s1 < 10; s1++) {
        FUN_000143b0(buf, DAT_0039c6e8, s1 + 1);
        item = FUN_00000bcc(72);
        if (item)
            item = FUN_000518d4(item);
        s0->items[s1] = item;
        FUN_00051ad8(item, buf, 0);
        FUN_00051d38(s0->items[s1], 1100.0f);
    }

    FUN_0001c73c(&DAT_003b7ebc);
    FUN_0001c684(&DAT_003b7ebc, 1, DAT_0039c774);
    FUN_002bf5d0(DAT_003f3458, 0);
    FUN_002bf730(1);
    FUN_0001c73c(&DAT_003b7ebc);
}

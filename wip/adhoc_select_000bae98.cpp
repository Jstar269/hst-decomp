/* NEAR 78/78 words, 6 differ (first +0x10). Everything matches, including the
   doubled state block: `m->state = 7; switch (m->state) { case 4: case 8: <call>;
   break; case 10: break; }` reproduces retail's beq 10 / beq 8 / beq 4 chain
   (switching on a LOCAL instead lets MWCC constant-fold the switch away; switching
   on the field forwards the store but does not fold). Remaining 6 words are one
   colouring choice in the 3x2 byte copy loop: retail keeps the destination pointer
   in t0 (counter in a0), ours in a2. Loads must be batched into two temporaries
   (`c0 = name[0]; c1 = name[1]; d[0] = c0; d[1] = c1;`) to get retail's lb/lb/sb/sb
   order. Ruled out: direct d[0]=name[0] (interleaves lb/sb), block-scoped dest,
   pointer-walk *d++=*name++, index loop, dest in a declared pointer vs &buf[0]. */
/* HSTMATCH module=EBOOT.BIN start=0x000bae98 end=0x000bafd0 symbol=FUN_000bae98 lang=c++ */
struct Match {
    char pad0[0x10];
    unsigned short field10;
    char pad1[0x28 - 0x12];
    int state;
    char pad2[0x16c - 0x2c];
    int target;
    char pad3[0x178 - 0x170];
    unsigned char finished;
    char pad4[0x17c - 0x179];
    int result;
};
extern "C" char DAT_002d51a8[];
extern "C" int DAT_00338ac4;
extern "C" int FUN_002b7db8(int, char *);
extern "C" void FUN_000ba3ac(char *, int);
extern "C" unsigned char FUN_000bda40(int, int, unsigned short, int, int);

extern "C" int FUN_000bae98(struct Match *m, const char *name)
{
    char buf[6];
    char *d = &buf[0];
    int i = 3;
    int r;
    char c0;
    char c1;

    do {
        c1 = name[1];
        c0 = name[0];
        d[0] = c0;
        d[1] = c1;
        name += 2;
        d += 2;
    } while (--i > 0);
    r = FUN_002b7db8(m->target, buf);
    if (r < 0) {
        FUN_000ba3ac(DAT_002d51a8, r);
        if (m->finished == 0) {
            m->state = 7;
            switch (m->state) {
            case 4:
            case 8:
                m->result = FUN_000bda40(DAT_00338ac4, DAT_00338ac4 + 0x38,
                                         m->field10, 0x5a4, 0);
                break;
            case 10:
                break;
            }
        }
        return 0;
    }
    if (m->finished == 0) {
        m->state = 6;
            switch (m->state) {
            case 4:
            case 8:
                m->result = FUN_000bda40(DAT_00338ac4, DAT_00338ac4 + 0x38,
                                         m->field10, 0x5a4, 0);
                break;
            case 10:
                break;
            }
    }
    return 1;
}
// near miss from lane fm6 (unreviewed)

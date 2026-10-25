/* HSTMATCH module=EBOOT.BIN start=0x001f9528 end=0x001f98f0 symbol=FUN_001f9528 lang=c++ helpers=FUN_001ef3f8@0x001ef3f8-0x001ef424 */
extern "C" {
extern char DAT_003417d0[];
extern char DAT_0034189b[];
extern char DAT_003417b8[];
extern char DAT_003417d2[];
extern char DAT_003417d4[];
extern char DAT_003417d6[];
extern char DAT_003417d8[];
extern char DAT_003417da[];
extern char DAT_00341835[];
extern char DAT_00341836[];
extern char DAT_0034186c[];
extern char DAT_0034186d[];
extern char DAT_0034186e[];
extern char *DAT_003415a8;
extern int DAT_0034a77c;
extern char DAT_002eed00[];
extern char DAT_002eed14[];
extern char DAT_002eed20[];
extern char DAT_002eed3c[];
extern char DAT_002eed48[];
extern char DAT_002eed54[];
extern char DAT_002eed60[];
extern char DAT_002eed6c[];

extern int FUN_0016bb88(void);
extern int FUN_002af920(int value);
extern void FUN_002afa48(int *out, int zero, int value);
extern int FUN_0016b21c(short value);
extern void FUN_001c16b0(int id, short value, int result,
                         unsigned char flag, int out, int zero);
extern void *FUN_00193474(int index);
extern int FUN_0016bb5c(void);
extern int FUN_0024dd40(float value, int global);
extern void FUN_001c1c50(int, int, unsigned int, unsigned short, unsigned short,
                         unsigned short, unsigned short, short, bool, bool,
                         bool, int, int, int, unsigned int, void *,
                         unsigned char, int, int, int, int, int, int, int,
                         void *);
static void FUN_001ef3f8(...) { }
}
struct Manager {
    char pad[0x3cc];
    int first;
    int second;
};

extern "C" void FUN_001f9528(struct Manager *self)
{
    struct Manager *base = self;
    int out;
    int temp;

    temp = FUN_002af920(FUN_0016bb88());
    out = 0;
    FUN_002afa48(&out, 0, temp);

    {
    register int first = base->first;
    if (first != -1) {
        register int off1 = first * 0x120;
        short value = *(short *)(DAT_003417d0 + off1);
        int result = FUN_0016b21c(value);
        unsigned char flag = *(unsigned char *)(DAT_0034189b + off1);
        FUN_001c16b0(first, value, result, flag, out, 0);

        FUN_001ef3f8(DAT_002eed00, first);
        FUN_001ef3f8(DAT_002eed14, DAT_003417b8 + off1 + 0xcc);
        FUN_001ef3f8(DAT_002eed20,
                     *(short *)(DAT_003417b8 + off1 + 0),
                     *(short *)(DAT_003417b8 + off1 + 2),
                     *(short *)(DAT_003417b8 + off1 + 4),
                     *(short *)(DAT_003417b8 + off1 + 6),
                     *(short *)(DAT_003417b8 + off1 + 8),
                     *(short *)(DAT_003417b8 + off1 + 10));
        FUN_001ef3f8(DAT_002eed3c, *(signed char *)(DAT_003417b8 + off1 + 0xa0));
        FUN_001ef3f8(DAT_002eed48, *(unsigned char *)(DAT_003417b8 + off1 + 0x64));
        FUN_001ef3f8(DAT_002eed54, *(unsigned char *)(DAT_003417b8 + off1 + 0x66));
        FUN_001ef3f8(DAT_002eed60, DAT_003417b8 + off1 + 0x54);
        FUN_001ef3f8(DAT_002eed6c, *(unsigned char *)(DAT_003417b8 + off1 + 0x67));
    }
    }

    {
        int second = base->second;
        if (second != -1) {
            int off = second * 0x120;
            char *entry = DAT_003417b8 + off;
            short value = *(short *)(DAT_003417d0 + off);
            void *info = FUN_00193474(value);
            char *selected = 0;
            char *base = DAT_003415a8 + 128;
            int global_value;
            int asset;

            if (value < 0) {
                selected = 0;
            } else if (value < 15) {
                selected = 0;
            } else {
                selected = base + value * 56 + 4;
            }
            global_value = FUN_0016bb5c();
            asset = FUN_0024dd40(*(float *)(selected + 4), DAT_0034a77c);
            FUN_001c1c50(
                second, (int)(entry + 0xe4), (unsigned)value,
                *(unsigned short *)(DAT_003417d2 + off),
                *(unsigned short *)(DAT_003417d4 + off),
                *(unsigned short *)(DAT_003417d6 + off),
                *(unsigned short *)(DAT_003417d8 + off),
                *(short *)(DAT_003417da + off),
                *(unsigned char *)(DAT_0034186c + off) != 0,
                *(unsigned char *)(DAT_0034186d + off) != 0,
                *(unsigned char *)(DAT_0034186e + off) != 0,
                out, global_value, *(unsigned char *)(DAT_00341835 + off),
                (unsigned)value, entry + 0x6c,
                *(unsigned char *)(DAT_00341836 + off), 0, 0, asset, 1,
                *(unsigned char *)(DAT_0034189b + off), 0, 0, info);

            FUN_001ef3f8(DAT_002eed00, second);
            FUN_001ef3f8(DAT_002eed14, entry + 0xcc);
            FUN_001ef3f8(DAT_002eed20,
                         *(short *)(entry + 0), *(short *)(entry + 2),
                         *(short *)(entry + 4), *(short *)(entry + 6),
                         *(short *)(entry + 8), *(short *)(entry + 10));
            FUN_001ef3f8(DAT_002eed3c, *(signed char *)(entry + 0xa0));
            FUN_001ef3f8(DAT_002eed48, *(unsigned char *)(entry + 0x64));
            FUN_001ef3f8(DAT_002eed54, *(unsigned char *)(entry + 0x66));
            FUN_001ef3f8(DAT_002eed60, entry + 0x54);
            FUN_001ef3f8(DAT_002eed6c, *(unsigned char *)(entry + 0x67));
        }
    }
}
// NEAR MISS: 200 differing words out of the 242-word target after 15 compile attempts.
// The 128-byte frame, initial 0x16bb88/0x2af920/0x2afa48 calls, and same-file
// FUN_001ef3f8 helper are exact. The 25-argument FUN_001c1c50 call and its 17 stack
// arguments are represented. Remaining differences are mostly register coloring:
// retail keeps self in s1, the first index in s0, and its scaled row offset in s2;
// this candidate assigns those to s2, s1, and s0. The second path similarly rotates
// the row pointer, id, item pointer, and global value registers. First-log row loads
// and helper calls are close, but their setup order still differs.
// Ruled out: void/char/int/pointer parameter forms, a typed Manager pointer and alias,
// register hints, function-scope versus block-scope first index, direct scaled-index
// expressions versus a saved offset, and C versus C++ linkage. Signed/unsigned
// halfword and bool/byte argument prototypes changed the score but did not improve the
// best result. Use the current helpers= header; FUN_001ef3f8 matches its retail range.
// near miss from lane lnm2 (unreviewed)

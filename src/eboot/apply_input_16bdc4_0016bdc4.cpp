/* HSTMATCH module=EBOOT.BIN start=0x0016bdc4 end=0x0016bee8 symbol=FUN_0016bdc4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: C++ with prototyped float parameters (65535.0f/-1.0f in f12/f13), the byte flag is unsigned char (lbu), and the two zeroed 16-byte argument temporaries are `Q()` objects (user ctor) with aligned(16), which leaves retail 8-byte hole above them; exact match verified; names and types await human review. */
struct Cam { char pad[0xc]; float f0c; };
struct Snd { char pad[8]; float f08; };
struct Q { int a, b, c, d; Q() : a(0), b(0), c(0), d(0) {} } __attribute__((aligned(16)));
extern "C" {
extern Cam *DAT_00331b84;
extern Snd *DAT_0034a820;
extern int DAT_0034a678;
void FUN_00063830(float, float, Cam *, const Q &, const Q &, int, int, int);
void FUN_001ff5f0(unsigned char *, int *);
void FUN_00292e40(Snd *, int);
void FUN_002930c8(float, Snd *, int);
}

extern "C" void FUN_0016bdc4(int param_1)
{
    unsigned char flag = 0;
    int v = 0;
    if (param_1 == 0x24) {
        if (DAT_0034a678 - 0x25U < 2 && DAT_0034a820 != 0)
            FUN_001ff5f0(&flag, &v);
    } else if (param_1 == 0x27 && DAT_0034a678 == 0x27 && DAT_0034a820 != 0) {
        FUN_001ff5f0(&flag, &v);
    }
    if (flag != 0) {
        FUN_00292e40(DAT_0034a820, v);
        FUN_002930c8(65535.0f, DAT_0034a820, 1);
    }
    FUN_00063830(65535.0f, -1.0f, DAT_00331b84, Q(), Q(), 10, 0, 0);
}

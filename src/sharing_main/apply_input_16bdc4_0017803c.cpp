/* HSTMATCH module=hstp_trans_main.prx start=0x0017803c end=0x00178160 symbol=FUN_0017803c lang=c++ */
/* Clone of src/eboot/apply_input_16bdc4_0016bdc4.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: C++ with prototyped float parameters (65535.0f/-1.0f in f12/f13), the byte flag is unsigned char (lbu), and the two zeroed 16-byte argument temporaries are `Q()` objects (user ctor) with aligned(16), which leaves retail 8-byte hole above them; exact match verified; names and types await human review. */
struct Cam { char pad[0xc]; float f0c; };
struct Snd { char pad[8]; float f08; };
struct Q { int a, b, c, d; Q() : a(0), b(0), c(0), d(0) {} } __attribute__((aligned(16)));
extern "C" {
extern Cam *DAT_003daec4;
extern Snd *DAT_003f3b50;
extern int DAT_003f39a8;
void FUN_000646f4(float, float, Cam *, const Q &, const Q &, int, int, int);
void FUN_0020ddc0(unsigned char *, int *);
void FUN_002a444c(Snd *, int);
void FUN_002a46d4(float, Snd *, int);
}

extern "C" void FUN_0017803c(int param_1)
{
    unsigned char flag = 0;
    int v = 0;
    if (param_1 == 0x24) {
        if (DAT_003f39a8 - 0x25U < 2 && DAT_003f3b50 != 0)
            FUN_0020ddc0(&flag, &v);
    } else if (param_1 == 0x27 && DAT_003f39a8 == 0x27 && DAT_003f3b50 != 0) {
        FUN_0020ddc0(&flag, &v);
    }
    if (flag != 0) {
        FUN_002a444c(DAT_003f3b50, v);
        FUN_002a46d4(65535.0f, DAT_003f3b50, 1);
    }
    FUN_000646f4(65535.0f, -1.0f, DAT_003daec4, Q(), Q(), 10, 0, 0);
}

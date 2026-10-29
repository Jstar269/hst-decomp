/* HSTMATCH module=hstp_trans_main.prx start=0x001aafa4 end=0x001ab158 symbol=FUN_001aafa4 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/stop_effect_apply_input_0019da6c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct Cam { char pad[0xc]; float f0c; };
struct Snd { char pad[8]; float f08; };
struct A { char pad[0x2a4]; unsigned char b2a4; };
struct B { char pad[0x178]; unsigned char b178; };
struct Q { int a, b, c, d; Q() : a(0), b(0), c(0), d(0) {} } __attribute__((aligned(16)));
extern "C" {
extern Cam *DAT_003daec4;
extern B *DAT_003e1e04;
extern A *DAT_003eaac0;
extern Snd *DAT_003f3b50;
extern int DAT_003f39a8;
void FUN_000646f4(float, float, Cam *, const Q &, const Q &, int, int, int);
void FUN_000647e0(float, Cam *, int);
void FUN_0020ddc0(unsigned char *, int *);
void FUN_002a444c(Snd *, int);
void FUN_002a46d4(float, Snd *, int);
void FUN_002a48c4(float, Snd *, int);
}

enum { STATE_22 = 0x16, STATE_23 = 0x17, STATE_25 = 0x19 }; /* state ids handled here */

/* React to entering a state: fetch an input for states 22 and 25 (under extra conditions), call the sound object for 23 and for a fetched input, then make the camera call that matches the state. */
extern "C" void FUN_001aafa4(int stateId)
{
    unsigned char flag = 0; /* set when an input was fetched */
    int v = 0;               /* the fetched input */
    bool alt = false;
    if (stateId == STATE_22) {
        if (DAT_003f39a8 == 0x29 && DAT_003f3b50 != 0)
            FUN_0020ddc0(&flag, &v);
    } else if (stateId == STATE_25) {
        if (DAT_003f39a8 == 0x29 && DAT_003eaac0->b2a4 != 0 && DAT_003e1e04->b178 != 0 && DAT_003f3b50 != 0)
            FUN_0020ddc0(&flag, &v);
    } else if (stateId == STATE_23) {
        alt = true;
        if (DAT_003f3b50 != 0)
            FUN_002a48c4(65535.0f, DAT_003f3b50, 6);
    }
    if (flag != 0) {
        FUN_002a444c(DAT_003f3b50, v);
        FUN_002a46d4(65535.0f, DAT_003f3b50, 1);
    }
    if (alt)
        FUN_000647e0(65535.0f, DAT_003daec4, 15);
    else
        FUN_000646f4(65535.0f, -1.0f, DAT_003daec4, Q(), Q(), 10, 0, 0);
}

/* HSTMATCH module=EBOOT.BIN start=0x0019da6c end=0x0019dc20 symbol=FUN_0019da6c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Cam { char pad[0xc]; float f0c; };
struct Snd { char pad[8]; float f08; };
struct A { char pad[0x2a4]; unsigned char b2a4; };
struct B { char pad[0x178]; unsigned char b178; };
struct Q { int a, b, c, d; Q() : a(0), b(0), c(0), d(0) {} } __attribute__((aligned(16)));
extern "C" {
extern Cam *DAT_00331b84;
extern B *DAT_00338ac4;
extern A *DAT_00341784;
extern Snd *DAT_0034a820;
extern int DAT_0034a678;
void FUN_00063830(float, float, Cam *, const Q &, const Q &, int, int, int);
void FUN_0006391c(float, Cam *, int);
void FUN_001ff5f0(unsigned char *, int *);
void FUN_00292e40(Snd *, int);
void FUN_002930c8(float, Snd *, int);
void FUN_002932b8(float, Snd *, int);
}

enum { STATE_22 = 0x16, STATE_23 = 0x17, STATE_25 = 0x19 }; /* state ids handled here */

/* React to entering a state: fetch an input for states 22 and 25 (under extra conditions), call the sound object for 23 and for a fetched input, then make the camera call that matches the state. */
extern "C" void FUN_0019da6c(int stateId)
{
    unsigned char flag = 0; /* set when an input was fetched */
    int v = 0;               /* the fetched input */
    bool alt = false;
    if (stateId == STATE_22) {
        if (DAT_0034a678 == 0x29 && DAT_0034a820 != 0)
            FUN_001ff5f0(&flag, &v);
    } else if (stateId == STATE_25) {
        if (DAT_0034a678 == 0x29 && DAT_00341784->b2a4 != 0 && DAT_00338ac4->b178 != 0 && DAT_0034a820 != 0)
            FUN_001ff5f0(&flag, &v);
    } else if (stateId == STATE_23) {
        alt = true;
        if (DAT_0034a820 != 0)
            FUN_002932b8(65535.0f, DAT_0034a820, 6);
    }
    if (flag != 0) {
        FUN_00292e40(DAT_0034a820, v);
        FUN_002930c8(65535.0f, DAT_0034a820, 1);
    }
    if (alt)
        FUN_0006391c(65535.0f, DAT_00331b84, 15);
    else
        FUN_00063830(65535.0f, -1.0f, DAT_00331b84, Q(), Q(), 10, 0, 0);
}

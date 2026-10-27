/* HSTMATCH module=hstp_trans_main.prx start=0x000fb29c end=0x000fb360 symbol=__ct__10C_000fb29cFv lang=c++ data=0x0037ef44 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037ef44-0x0037ef49) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Constructor of a polymorphic object (vtable 0x003b0aac, deleting dtor 0x000fb360) holding two 72-byte panes
   (polymorphic class with out-of-line ctor 0x000518d4 / dtor 0x000519d4, built by __construct_array): each pane
   is loaded from "data/menu/inpane/inp_fukidashi/" + "fukidashi000" / "moyamoya" (FUN_000143b0 = sprintf,
   format "%s%s"), then FUN_000fb4c0 resets the 16 slot records. Written as a real constructor: only the
   constructor keeps retail's byte-offset induction (`addu v0,s0,s1; addiu a0,v0,4`, `addiu s1,s1,72`) with
   `this` in s0; the same body as an extern "C" function walks a pointer IV instead. Names provisional. */
struct B_000518d4 {
    virtual ~B_000518d4();
    char data[0x44];
    B_000518d4();
};

extern "C" {
extern char *DAT_0037ef3c[];   /* "fukidashi000", "moyamoya" */
extern char DAT_002d0ec4[];    /* "data/menu/inpane/inp_fukidashi/" */
int FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_00051ad8(B_000518d4 *pane, const char *path, int flag);
}

struct C_000fb29c {
    virtual ~C_000fb29c();
    B_000518d4 panes[2];
    C_000fb29c();
};

extern "C" void FUN_000fb4c0(C_000fb29c *self);

C_000fb29c::C_000fb29c()
{
    for (unsigned int i = 0; i < 2; i++) {
        char buf[256];
        FUN_000143b0(buf, "%s%s", DAT_002d0ec4, DAT_0037ef3c[i]);
        FUN_00051ad8(&panes[i], buf, 0);
    }
    FUN_000fb4c0(this);
}

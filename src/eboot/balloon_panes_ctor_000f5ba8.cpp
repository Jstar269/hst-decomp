/* HSTMATCH module=EBOOT.BIN start=0x000f5ba8 end=0x000f5c6c symbol=__ct__10C_000f5ba8Fv lang=c++ data=0x002d816c */
/* Clone of src/sharing_main/balloon_panes_ctor_000fb29c.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d816c-0x002d8171) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of a polymorphic object (vtable 0x3077e0, deleting dtor 0x000fb360) holding two 72-byte panes
   (polymorphic class with out-of-line ctor 0x50fc0 / dtor 0x510c0, built by __construct_array): each pane
   is loaded from "data/menu/inpane/inp_fukidashi/" + "fukidashi000" / "moyamoya" (FUN_000143b0 = sprintf,
   format "%s%s"), then FUN_000f5dcc resets the 16 slot records. Written as a real constructor: only the
   constructor keeps retail's byte-offset induction (`addu v0,s0,s1; addiu a0,v0,4`, `addiu s1,s1,72`) with
   `this` in s0; the same body as an extern "C" function walks a pointer IV instead. Names provisional. */
struct B_00050fc0 {
    virtual ~B_00050fc0();
    char data[0x44];
    B_00050fc0();
};

extern "C" {
extern char *DAT_002d8164[];   /* "fukidashi000", "moyamoya" */
extern char DAT_002c0c54[];    /* "data/menu/inpane/inp_fukidashi/" */
int FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_000511c4(B_00050fc0 *pane, const char *path, int flag);
}

struct C_000f5ba8 {
    virtual ~C_000f5ba8();
    B_00050fc0 panes[2];
    C_000f5ba8();
};

extern "C" void FUN_000f5dcc(C_000f5ba8 *self);

C_000f5ba8::C_000f5ba8()
{
    for (unsigned int i = 0; i < 2; i++) {
        char buf[256];
        FUN_000143b0(buf, "%s%s", DAT_002c0c54, DAT_002d8164[i]);
        FUN_000511c4(&panes[i], buf, 0);
    }
    FUN_000f5dcc(this);
}

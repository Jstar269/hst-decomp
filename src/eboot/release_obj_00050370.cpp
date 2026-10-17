/* HSTMATCH module=EBOOT.BIN start=0x00050370 end=0x000503d0 symbol=FUN_00050370 lang=c++ */
/* Clone of src/sharing_main/release_obj_00050c4c.cpp (hstclone.py tag u1r5e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" void FUN_00050d8c(void *, int);

struct Obj {
    virtual ~Obj();
};

struct Holder {
    char pad[0x1a0a4];
    Obj *p;
};

extern "C" void FUN_00050370(Holder *param_1)
{
    FUN_00050d8c(param_1, 1);
    Obj *p = param_1->p;
    if (p) {
        delete p;
        param_1->p = 0;
    }
}

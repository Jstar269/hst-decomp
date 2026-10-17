/* HSTMATCH module=hstp_trans_main.prx start=0x00050c4c end=0x00050cac symbol=FUN_00050c4c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" void FUN_000516a0(void *, int);

struct Obj {
    virtual ~Obj();
};

struct Holder {
    char pad[0x1a0a4];
    Obj *p;
};

extern "C" void FUN_00050c4c(Holder *param_1)
{
    FUN_000516a0(param_1, 1);
    Obj *p = param_1->p;
    if (p) {
        delete p;
        param_1->p = 0;
    }
}

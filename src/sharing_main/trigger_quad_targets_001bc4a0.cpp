/* HSTMATCH module=hstp_trans_main.prx start=0x001bc4a0 end=0x001bc520 symbol=FUN_001bc4a0 lang=c++ */
/* Clone of src/eboot/trigger_quad_targets_001aedc8.cpp (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct SubTarget {
    virtual ~SubTarget();
    virtual void dummy1();
    virtual void dummy2();
    virtual void trigger();
};

struct SubHolder {
    SubTarget *target;
};

struct Obj_001bc4a0 {
    int pad0;
    SubHolder *h1;  /* +4 */
    SubHolder *h2;  /* +8 */
    SubHolder *h3;  /* +12 */
    SubHolder *h4;  /* +16 */
};

extern "C" void FUN_001bc4a0(Obj_001bc4a0 *self)
{
    self->h4->target->trigger();
    self->h2->target->trigger();
    self->h1->target->trigger();
    self->h3->target->trigger();
}

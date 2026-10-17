/* HSTMATCH module=EBOOT.BIN start=0x001aedc8 end=0x001aee48 symbol=FUN_001aedc8 lang=c++ */
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

struct Obj_001aedc8 {
    int pad0;
    SubHolder *h1;  /* +4 */
    SubHolder *h2;  /* +8 */
    SubHolder *h3;  /* +12 */
    SubHolder *h4;  /* +16 */
};

extern "C" void FUN_001aedc8(Obj_001aedc8 *self)
{
    self->h4->target->trigger();
    self->h2->target->trigger();
    self->h1->target->trigger();
    self->h3->target->trigger();
}

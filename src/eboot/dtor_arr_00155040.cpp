/* HSTMATCH module=EBOOT.BIN start=0x00155040 end=0x001550c0 symbol=__dt__10C_00155040Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +0x10: free it and clear the pointer; the inline base
   destructor restores the base vtable (template instance, hsttmpl.py tag t4). Names provisional. */
class B_0030840c {
public:
    virtual void key_0030840c();
    virtual ~B_0030840c() {}
};
class C_00155040 : public B_0030840c {
public:
    virtual void key_00155040();
    char pad[0xc];
    char *buffer;
    virtual ~C_00155040();
};
C_00155040::~C_00155040() { if (buffer) { delete[] buffer; buffer = 0; } }

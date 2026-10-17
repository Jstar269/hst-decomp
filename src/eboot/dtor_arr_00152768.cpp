/* HSTMATCH module=EBOOT.BIN start=0x00152768 end=0x001527e8 symbol=__dt__10C_00152768Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +0xc: free it and clear the pointer; the inline base
   destructor restores the base vtable (template instance, hsttmpl.py tag t4). Names provisional. */
class B_0030840c {
public:
    virtual void key_0030840c();
    virtual ~B_0030840c() {}
};
class C_00152768 : public B_0030840c {
public:
    virtual void key_00152768();
    char pad[0x8];
    char *buffer;
    virtual ~C_00152768();
};
C_00152768::~C_00152768() { if (buffer) { delete[] buffer; buffer = 0; } }

/* HSTMATCH module=EBOOT.BIN start=0x0014d14c end=0x0014d1cc symbol=__dt__10C_0014d14cFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_0030840c {
public:
    virtual void key_0030840c();
    virtual ~B_0030840c() {}
};
class C_0014d14c : public B_0030840c {
public:
    virtual void key_0014d14c();
    int f4;
    char *buffer;
    virtual ~C_0014d14c();
};
C_0014d14c::~C_0014d14c() { if (buffer) { delete[] buffer; buffer = 0; } }

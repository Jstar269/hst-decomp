/* HSTMATCH module=EBOOT.BIN start=0x001517cc end=0x0015184c symbol=__dt__10C_001517ccFv */
/* Clone of src/eboot/dtor_0014d14c.cpp (hstclone.py tag c4): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_0030840c {
public:
    virtual void key_0030840c();
    virtual ~B_0030840c() {}
};
class C_001517cc : public B_0030840c {
public:
    virtual void key_001517cc();
    int f4;
    char *buffer;
    virtual ~C_001517cc();
};
C_001517cc::~C_001517cc() { if (buffer) { delete[] buffer; buffer = 0; } }

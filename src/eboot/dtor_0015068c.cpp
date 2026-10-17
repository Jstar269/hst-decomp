/* HSTMATCH module=EBOOT.BIN start=0x0015068c end=0x0015070c symbol=__dt__10C_0015068cFv */
/* Clone of src/eboot/dtor_0014d14c.cpp (hstclone.py tag c4): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_0030840c {
public:
    virtual void key_0030840c();
    virtual ~B_0030840c() {}
};
class C_0015068c : public B_0030840c {
public:
    virtual void key_0015068c();
    int f4;
    char *buffer;
    virtual ~C_0015068c();
};
C_0015068c::~C_0015068c() { if (buffer) { delete[] buffer; buffer = 0; } }

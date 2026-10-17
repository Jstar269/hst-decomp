/* HSTMATCH module=EBOOT.BIN start=0x001518cc end=0x0015194c symbol=__dt__10C_001518ccFv */
/* Clone of src/eboot/dtor_0014d14c.cpp (hstclone.py tag c4): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_0030840c {
public:
    virtual void key_0030840c();
    virtual ~B_0030840c() {}
};
class C_001518cc : public B_0030840c {
public:
    virtual void key_001518cc();
    int f4;
    char *buffer;
    virtual ~C_001518cc();
};
C_001518cc::~C_001518cc() { if (buffer) { delete[] buffer; buffer = 0; } }

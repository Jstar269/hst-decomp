/* HSTMATCH module=EBOOT.BIN start=0x00150458 end=0x001504d8 symbol=__dt__10C_00150458Fv */
/* Clone of src/eboot/dtor_0014d14c.cpp (hstclone.py tag c4): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_0030840c {
public:
    virtual void key_0030840c();
    virtual ~B_0030840c() {}
};
class C_00150458 : public B_0030840c {
public:
    virtual void key_00150458();
    int f4;
    char *buffer;
    virtual ~C_00150458();
};
C_00150458::~C_00150458() { if (buffer) { delete[] buffer; buffer = 0; } }

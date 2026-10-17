/* HSTMATCH module=hstp_trans_main.prx start=0x00158c34 end=0x00158cb4 symbol=__dt__10C_00158c34Fv */
/* Clone of src/eboot/dtor_0014d14c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_003b16d8 {
public:
    virtual void key_003b16d8();
    virtual ~B_003b16d8() {}
};
class C_00158c34 : public B_003b16d8 {
public:
    virtual void key_00158c34();
    int f4;
    char *buffer;
    virtual ~C_00158c34();
};
C_00158c34::~C_00158c34() { if (buffer) { delete[] buffer; buffer = 0; } }

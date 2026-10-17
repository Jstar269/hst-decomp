/* HSTMATCH module=hstp_trans_main.prx start=0x0015c490 end=0x0015c510 symbol=__dt__10C_0015c490Fv */
/* Clone of src/eboot/dtor_0014d14c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_003b16d8 {
public:
    virtual void key_003b16d8();
    virtual ~B_003b16d8() {}
};
class C_0015c490 : public B_003b16d8 {
public:
    virtual void key_0015c490();
    int f4;
    char *buffer;
    virtual ~C_0015c490();
};
C_0015c490::~C_0015c490() { if (buffer) { delete[] buffer; buffer = 0; } }

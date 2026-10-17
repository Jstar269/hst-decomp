/* HSTMATCH module=hstp_trans_main.prx start=0x0015d974 end=0x0015d9f4 symbol=__dt__10C_0015d974Fv */
/* Clone of src/eboot/dtor_0014d14c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +8: free it and clear the pointer; the inline base
   destructor restores the base vtable. Names provisional. */
class B_003b16d8 {
public:
    virtual void key_003b16d8();
    virtual ~B_003b16d8() {}
};
class C_0015d974 : public B_003b16d8 {
public:
    virtual void key_0015d974();
    int f4;
    char *buffer;
    virtual ~C_0015d974();
};
C_0015d974::~C_0015d974() { if (buffer) { delete[] buffer; buffer = 0; } }

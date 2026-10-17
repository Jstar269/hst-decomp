/* HSTMATCH module=hstp_trans_main.prx start=0x0015e8f0 end=0x0015e970 symbol=__dt__10C_0015e8f0Fv */
/* Clone of src/eboot/dtor_arr_00152768.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +0xc: free it and clear the pointer; the inline base
   destructor restores the base vtable (template instance, hsttmpl.py tag t4). Names provisional. */
class B_003b16d8 {
public:
    virtual void key_003b16d8();
    virtual ~B_003b16d8() {}
};
class C_0015e8f0 : public B_003b16d8 {
public:
    virtual void key_0015e8f0();
    char pad[0x8];
    char *buffer;
    virtual ~C_0015e8f0();
};
C_0015e8f0::~C_0015e8f0() { if (buffer) { delete[] buffer; buffer = 0; } }

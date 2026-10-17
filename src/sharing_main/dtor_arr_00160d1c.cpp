/* HSTMATCH module=hstp_trans_main.prx start=0x00160d1c end=0x00160d9c symbol=__dt__10C_00160d1cFv */
/* Clone of src/eboot/dtor_arr_00154964.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +0x1c: free it and clear the pointer; the inline base
   destructor restores the base vtable (template instance, hsttmpl.py tag t4). Names provisional. */
class B_003b16d8 {
public:
    virtual void key_003b16d8();
    virtual ~B_003b16d8() {}
};
class C_00160d1c : public B_003b16d8 {
public:
    virtual void key_00160d1c();
    char pad[0x18];
    char *buffer;
    virtual ~C_00160d1c();
};
C_00160d1c::~C_00160d1c() { if (buffer) { delete[] buffer; buffer = 0; } }

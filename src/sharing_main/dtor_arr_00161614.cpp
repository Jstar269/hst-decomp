/* HSTMATCH module=hstp_trans_main.prx start=0x00161614 end=0x00161694 symbol=__dt__10C_00161614Fv */
/* Clone of src/eboot/dtor_arr_00155040.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a heap array at +0x10: free it and clear the pointer; the inline base
   destructor restores the base vtable (template instance, hsttmpl.py tag t4). Names provisional. */
class B_003b16d8 {
public:
    virtual void key_003b16d8();
    virtual ~B_003b16d8() {}
};
class C_00161614 : public B_003b16d8 {
public:
    virtual void key_00161614();
    char pad[0xc];
    char *buffer;
    virtual ~C_00161614();
};
C_00161614::~C_00161614() { if (buffer) { delete[] buffer; buffer = 0; } }

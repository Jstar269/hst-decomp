/* HSTMATCH module=hstp_trans_main.prx start=0x0029ef54 end=0x0029efc0 symbol=__dt__10C_0029ef54Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0029f050(void *self);
struct Blob_0029ef54 { int v; ~Blob_0029ef54() {} };
class B_0029ef54 { public: Blob_0029ef54 *data; ~B_0029ef54() { FUN_0029f050(this); delete data; } };
class C_0029ef54 : public B_0029ef54 { public: int count; ~C_0029ef54(); };
C_0029ef54::~C_0029ef54() { count = 0; }

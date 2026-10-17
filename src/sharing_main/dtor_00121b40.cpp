/* HSTMATCH module=hstp_trans_main.prx start=0x00121b40 end=0x00121bac symbol=__dt__10C_00121b40Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00121bac(void *self);
struct Blob_00121b40 { int v; ~Blob_00121b40() {} };
class B_00121b40 { public: Blob_00121b40 *data; ~B_00121b40() { FUN_00121bac(this); delete data; } };
class C_00121b40 : public B_00121b40 { public: int count; ~C_00121b40(); };
C_00121b40::~C_00121b40() { count = 0; }

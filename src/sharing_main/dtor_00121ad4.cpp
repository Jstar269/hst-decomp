/* HSTMATCH module=hstp_trans_main.prx start=0x00121ad4 end=0x00121b40 symbol=__dt__10C_00121ad4Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00121bd0(void *self);
struct Blob_00121ad4 { int v; ~Blob_00121ad4() {} };
class B_00121ad4 { public: Blob_00121ad4 *data; ~B_00121ad4() { FUN_00121bd0(this); delete data; } };
class C_00121ad4 : public B_00121ad4 { public: int count; ~C_00121ad4(); };
C_00121ad4::~C_00121ad4() { count = 0; }

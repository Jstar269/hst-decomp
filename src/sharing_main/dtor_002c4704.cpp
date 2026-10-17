/* HSTMATCH module=hstp_trans_main.prx start=0x002c4704 end=0x002c4770 symbol=__dt__10C_002c4704Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_002c4770(void *self);
struct Blob_002c4704 { int v; ~Blob_002c4704() {} };
class B_002c4704 { public: Blob_002c4704 *data; ~B_002c4704() { FUN_002c4770(this); delete data; } };
class C_002c4704 : public B_002c4704 { public: int count; ~C_002c4704(); };
C_002c4704::~C_002c4704() { count = 0; }

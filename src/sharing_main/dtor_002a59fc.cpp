/* HSTMATCH module=hstp_trans_main.prx start=0x002a59fc end=0x002a5a68 symbol=__dt__10C_002a59fcFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_002a5a68(void *self);
struct Blob_002a59fc { int v; ~Blob_002a59fc() {} };
class B_002a59fc { public: Blob_002a59fc *data; ~B_002a59fc() { FUN_002a5a68(this); delete data; } };
class C_002a59fc : public B_002a59fc { public: int count; ~C_002a59fc(); };
C_002a59fc::~C_002a59fc() { count = 0; }

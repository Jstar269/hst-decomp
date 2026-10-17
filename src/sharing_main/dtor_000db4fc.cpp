/* HSTMATCH module=hstp_trans_main.prx start=0x000db4fc end=0x000db568 symbol=__dt__10C_000db4fcFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000db568(void *self);
struct Blob_000db4fc { int v; ~Blob_000db4fc() {} };
class B_000db4fc { public: Blob_000db4fc *data; ~B_000db4fc() { FUN_000db568(this); delete data; } };
class C_000db4fc : public B_000db4fc { public: int count; ~C_000db4fc(); };
C_000db4fc::~C_000db4fc() { count = 0; }

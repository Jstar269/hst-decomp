/* HSTMATCH module=hstp_trans_main.prx start=0x001567ac end=0x0015681c symbol=__dt__10D_001567acFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001567ac { int v; ~Elem_001567ac() {} };
class V_001567ac {
public:
    Elem_001567ac *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001567ac() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001567ac : public V_001567ac { public: ~D_001567ac(); };
D_001567ac::~D_001567ac() { size = 0; }

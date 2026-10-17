/* HSTMATCH module=hstp_trans_main.prx start=0x001566cc end=0x0015673c symbol=__dt__10D_001566ccFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001566cc { int v; ~Elem_001566cc() {} };
class V_001566cc {
public:
    Elem_001566cc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001566cc() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001566cc : public V_001566cc { public: ~D_001566cc(); };
D_001566cc::~D_001566cc() { size = 0; }

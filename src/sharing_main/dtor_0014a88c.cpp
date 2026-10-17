/* HSTMATCH module=hstp_trans_main.prx start=0x0014a88c end=0x0014a8fc symbol=__dt__10D_0014a88cFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0014a88c { int v; ~Elem_0014a88c() {} };
class V_0014a88c {
public:
    Elem_0014a88c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0014a88c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0014a88c : public V_0014a88c { public: ~D_0014a88c(); };
D_0014a88c::~D_0014a88c() { size = 0; }

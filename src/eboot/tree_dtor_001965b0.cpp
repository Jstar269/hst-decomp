/* HSTMATCH module=EBOOT.BIN start=0x001965b0 end=0x0019660c symbol=__dt__13Tree_001965b0Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_001965b0;
struct Tree_001965b0 {
    int header;
    Node_001965b0 *root;
    ~Tree_001965b0();
};
extern "C" void FUN_00196720(Tree_001965b0 *t, Node_001965b0 *x);
Tree_001965b0::~Tree_001965b0()
{
    if (root)
        FUN_00196720(this, root);
}

/* HSTMATCH module=EBOOT.BIN start=0x00229b94 end=0x00229bf0 symbol=__dt__13Tree_00229b94Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_00229b94;
struct Tree_00229b94 {
    int header;
    Node_00229b94 *root;
    ~Tree_00229b94();
};
extern "C" void FUN_0022a124(Tree_00229b94 *t, Node_00229b94 *x);
Tree_00229b94::~Tree_00229b94()
{
    if (root)
        FUN_0022a124(this, root);
}

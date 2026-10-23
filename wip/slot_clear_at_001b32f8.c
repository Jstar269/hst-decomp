/* HSTMATCH module=EBOOT.BIN start=0x001b32f8 end=0x001b338c symbol=FUN_001b32f8 lang=c99 */
extern void FUN_00062418(int, int);

void FUN_001b32f8(int *param_1,int param_2)
{
  int *arr;
  int i;
  int b;

  arr = (int *)*param_1;
  i = param_2 + 0x27;
  b = 0;
  if ((i < 0x1da) && (arr[i] != 0)) {
    b = 1;
  }
  if (b != 0) {
    if (arr[i] != 0) {
      FUN_00062418(arr[i],1);
      arr[i] = 0;
    }
  }
}
// NEAR 11 (26 vs 37 words): the source shape (arr = *param_1; i = param_2 + 0x27; bool b = i < 0x1da
// && arr[i]; if (b) { if (arr[i]) { release(arr[i],1); arr[i] = 0; } }) is right, but retail re-indexes
// from scratch in every block (`sll v1,s0,2; addu v1,s1,v1` twice) and keeps arr in s1 / i in s0,
// where ours hoists the element address. Needs the element read spelled as a repeated
// `arr[param_2 + 0x27]` with no cached pointer, plus the two-instruction skip retail has for the
// second guard.
// near miss from lane fm5 (unreviewed)

#include <stdio.h>
#include <stdbool.h>

static void takuzuPrintBinary(unsigned int n, unsigned int bits)
{
  int bit;
  
  for(bit = 0; bit < bits; ++bit)
    printf("%c", ((1 << bit) & n)?'1':'0');
    
  printf("\n");
}

static void takuzuStringPrint(unsigned int n, unsigned int bits)
{
  bool valid = true;
  int pVal, val = -1;
  int same = 0;
  int bit;
  
  for(bit = 0; bit < bits; ++bit) {
    pVal = val;
    val = ((1 << bit) & n)?1:0;
    
    if(pVal == val)
      if(++same == 2) {
        valid = false;
        break;
      }
  }
    
  if(valid)
    takuzuPrintBinary(n, bits);
  
  if(n != 0)
    takuzuStringPrint(n - 1, bits);
}

void takuzuString(unsigned int n)
{
  takuzuStringPrint((1 << (n << 1)) - 1, n << 1);
}

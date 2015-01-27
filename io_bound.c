#include <stdio.h>
main()
{
 FILE  *out;
 char  c;
 int   a;

 while(1)
 {
   for(a=0;a>0;)
     ++a;

  if((out=fopen("io_bound.data","w"))!=NULL)
  {
    c=38;
    for(a=0; a<10000;a++)
    {
      putc(c,out);
      if(++c>126)
        c=38;
    }
    fclose(out);
  }
  else
  {
    printf("Cannot open file.\n");
    exit(0);
  }
 }
}

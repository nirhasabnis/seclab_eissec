#include <unistd.h>
#include <stdio.h>

#define UChar unsigned char

int main()
{
						int i;
						UChar ll_i = 0xEA;
						UChar yy[256];

						for(i = 0; i < 256; i++)
								yy[i] = (UChar) i;

            register UChar  rtmp;
            register UChar* ryy_j;
            register UChar  rll_i;
            rtmp  = yy[1];
            yy[1] = yy[0];
            ryy_j = &(yy[1]);
            rll_i = ll_i;
            while ( rll_i != rtmp ) {
               register UChar rtmp2;
               ryy_j++;
               rtmp2  = rtmp;
               rtmp   = *ryy_j;
							 *ryy_j = rtmp2;
						}
						yy[0] = rtmp;

						printf("%2x", yy[0]);

						return 0;
}

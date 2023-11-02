#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

enum boolean {NO, YES};   //  0 and 1 
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
            NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
            JUL, AUG, SEP, OCT, NOV, DEC };
            /* FEB = 2, MAR = 3, etc. */

int my_strlen(char s[]);

int xextern = 100; 

int main(){
    const double e = 2.71828182845905;   // see constant dont change effect
    const char msg[] = "warning: ";

    double k = sqrt((double)23.567);

    printf("Ranges for char: %e\n %s", k, msg);
    printf("Signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 to %u\n", UCHAR_MAX);

    // short
    printf("Ranges for short:\n");
    printf("Signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0 to %u\n", USHRT_MAX);

    // int
    printf("Ranges for int:\n");
    printf("Signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int: 0 to %u\n", UINT_MAX);

    // long
    printf("Ranges for long:\n");
    printf("Signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 to %lu\n", ULONG_MAX);

    // float
    printf("Ranges for float:\n");
    printf("Float min: %e\n", FLT_MIN);
    printf("Float max: %e\n", FLT_MAX);

    // double
    printf("Ranges for double:\n");
    printf("Double min: %e\n", DBL_MIN);
    printf("Double max: %e\n", DBL_MAX);

    // long double
    printf("Ranges for long double:\n");
    printf("Long double min: %Le\n", LDBL_MIN);
    printf("Long double max: %Le\n", LDBL_MAX);

    return 0;
}

/**
 * 
Ranges for char: 4.854585e+00
warning: Signed char: -128 to 127
Unsigned char: 0 to 255
Ranges for short:
Signed short: -32768 to 32767
Unsigned short: 0 to 65535
Ranges for int:
Signed int: -2147483648 to 2147483647
Unsigned int: 0 to 4294967295
Ranges for long:
Signed long: -9223372036854775808 to 9223372036854775807
Unsigned long: 0 to 18446744073709551615
Ranges for float:
Float min: 1.175494e-38
Float max: 3.402823e+38
Ranges for double:
Double min: 2.225074e-308
Double max: 1.797693e+308
Ranges for long double:
Long double min: 3.362103e-4932
Long double max: 1.189731e+4932
*/



int my_strlen(char s[]){
    int i;
    while(s[i] != '\0')
        ++i;
    return i;
}


int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(x<v[mid])
            high=mid+1;
        else if(x>v[mid])
            low=mid+1;
        else
            return mid;
    }
    return -1;
}


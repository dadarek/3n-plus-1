#include <stdio.h> // C functions
#include <iostream> // C++ functions

#define ASSERT_EQ(expected, actual) \
{ \
  int e = expected; \
  int a = actual; \
  if( e != a ) \
  { \
    printf("\033[0;31m"); \
    printf("******ASSERTION FAILED******\n"); \
    printf("In file       : %s:%d\n", __FILE__, __LINE__); \
    printf("Expected      : %d\n", e); \
    printf("Actual        : %d\n", a); \
    printf("Comparing     : %s\n", #expected); \
    printf("Against       : %s\n\n", #actual); \
    printf("\033[0m"); \
  } \
}  

using namespace std;

int howMuchToTerminate(unsigned long long n)
{
  int result = 1;
  
  while( n != 1 )
  {
    if( 1 == n % 2 )
    {
      n = n*3 + 1;
    }
    else
    {
      n /= 2;
    }

    result++;
  }

  return result;
}

int maxBetween( int a, int b )
{
  int result = 1;
  while( a <= b )
  {
    int howMuch = howMuchToTerminate( a );
    if(howMuch > result)
      result = howMuch;

    a++;
  }
  return result;
}

void RUN_TESTS()
{
  ASSERT_EQ( 0, howMuchToTerminate( 15 ) );
  ASSERT_EQ( 8, howMuchToTerminate( 17) );

  ASSERT_EQ( 1, howMuchToTerminate( 1 ) );
  ASSERT_EQ( 2, howMuchToTerminate( 2 ) );
  ASSERT_EQ( 8, howMuchToTerminate( 3 ) );
  ASSERT_EQ( 3, howMuchToTerminate( 4 ) );
  ASSERT_EQ( 6, howMuchToTerminate( 5 ) );
  ASSERT_EQ( 16, howMuchToTerminate( 22 ) );

  ASSERT_EQ( 1, maxBetween( 1, 1 ) );
  ASSERT_EQ( 2, maxBetween( 1, 2 ) );
  ASSERT_EQ( 8, maxBetween( 1, 3 ) );
  ASSERT_EQ( 6, maxBetween( 4, 5 ) );
  ASSERT_EQ( 8, maxBetween( 1, 5 ) );

  ASSERT_EQ( 20, maxBetween( 1, 10 ) );
  ASSERT_EQ( 125, maxBetween( 100, 200 ) );
  ASSERT_EQ( 89, maxBetween( 201, 210 ) );
  ASSERT_EQ( 174, maxBetween( 900, 1000 ) );

  printf("MAXIMUM: %d\n", maxBetween(1, 10000000) );

  printf("Tests complete.\n\n");
}

void C_READ()
{
  for(;;)
  {
    long p, q;
    printf("C Reading...\n");
    if( EOF == scanf("%ld %ld", &p, &q ) )
      break;

    printf( "You typed: [%ld, %ld]\n", p, q );
  }
}

void CPP_READ()
{
  for(;;)
  {
    long long p, q;
    cout << "C++ Reading..." << endl;
    if( !( cin >> p >> q ) )
      break;

    cout << "You typed: [" << p << ", " << q << "]" << endl;
  }

  cout << "Done reading." << endl;
}

int main()
{
  RUN_TESTS();
  return 0;
}

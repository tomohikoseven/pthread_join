#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int
test( )
{
    return 2;
}

int
main( )
{
    pthread_t   th_num;
    int         ret;
    void*       thread_return;

    ret = pthread_create( &th_num, NULL, ( void* )test, NULL );
    if( 0 != ret )
    {
        printf( "pthread_create error.\n" );
        exit( 1 );
    }
    ret = pthread_join( th_num, &thread_return );
    if( 0 != ret )
    {
        printf( "pthread_join error.\n" );
        exit( 1 );
    }

    printf( "thread_return:%p\n", thread_return );

    return 0;
}

#include <iostream>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std ;

// 若差距小於零, 則設為零. 
// 請留意 : b 參數所代表的元素在 a 參數所代表元素的後一位
int  positive_difference( int b , int a ) {
    int  d = b - a ;
    return  ( d < 0 ? 0 : d ) ;
}

int main() {
    
    int x[5] = { 4 , 2 , 2 , 5 , 2 };
    int dx[5] ;
    
    cout << "> 陣列   = " ;
    copy( x , x+5 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    adjacent_difference( x , x+5 , dx ) ;
    
    cout << "> 差距   = " ;
    copy( dx , dx+5 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    adjacent_difference( x , x+5 , dx , positive_difference ) ;
    
    cout << "> 正差距 = " ;
    copy( dx , dx+5 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}


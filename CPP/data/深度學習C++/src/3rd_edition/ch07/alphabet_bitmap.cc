#include <iostream>
#include <string>

using  namespace  std ;

// 大寫英文字點矩陣文字

int  main() {

    int  i , j , k , bit , no ;
    
    // 二十六個英文大寫字母, 每個字母用 5 x 4 點矩陣儲存, 
    // 也就是 5 個介於 [0,15] 之間的數字

    int  bitmap[26][5] = {
        {6,9,15,9,9}   , {14,9,14,9,14} , {6,9,8,9,6}   , 
        {14,9,9,9,14}  , {15,8,14,8,15} , {15,8,14,8,8} , 
        {7,8,11,9,6}   , {9,9,15,9,9}   , {7,2,2,2,7}   , 
        {7,2,2,10,14}  , {9,10,12,10,9} , {8,8,8,9,15}  ,
        {9,15,9,9,9}   , {9,13,11,9,9}  , {6,9,9,9,6}   , 
        {14,9,14,8,8}  , {15,9,13,11,15}, {14,9,14,10,9}, 
        {7,8,6,1,14}   , {15,2,2,2,2}   , {9,9,9,9,15}  , 
        {9,9,9,9,6}    , {9,9,9,15,9}   , {9,9,6,9,9}   ,
        {9,9,7,1,14}   , {15,1,2,4,15} } ;

    // 輸入一大寫英文字
    string  word ;
    cout << "> 輸入大寫英文字 : " ;
    cin >> word ;
    cout << '\n' ;
    
    // 儲存每一列的點矩陣資料
    string  line_map ;
    
    for ( i = 0 ; i < 5 ; ++i ) {
        for ( j = 0 ; j < word.size() ; ++j ) {

            // 找出每個字母在 26 字母的順序編號
            no = word[j] - 'A' ;
            
            // 找出 bitmap 所代表的數字
            bit = bitmap[no][i] ;

            // 利用位元運算子 (&) 由第四個位元往第一個位元方向一一
            // 取得各個位元的值, 如果是 1 則存入星號, 否則為空白
            for ( k = 0 ; k < 4 ; ++k ) {
                line_map += ( bit & (8>>k) ? " *" : "  " ) ;
            }

            // 各字母之間保持一個空白距離
            line_map += " " ;
        }

        cout << line_map << endl ;
        line_map = "" ;
    }

    return 0 ;
    
}

                                 

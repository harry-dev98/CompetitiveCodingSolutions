#include <algorithm>  
#include <string>  
#include <iostream>  
  
using namespace std;  
   
int main()  
{  
    string s = "";  
    int x = 0;
    int _ = 1;
    while(x < 877){
        char c = '0' + _++; 
        s += c;
        do {  
            if(x++ >= 873)
            cout<<x<<" -> " << s << '\n';  
            if(x>876)break;
        } while(next_permutation(s.begin(), s.end()));  
    } 
      
    return 0;  
}  
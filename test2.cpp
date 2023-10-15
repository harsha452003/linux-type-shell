#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    
    int y=5;
    while(y--){
        if(fork()==0){
            cout<<getpid();
            int x=10;
            while(x--){
                if(fork()==0){
                    cout<<getpid();
                    while(1){}
                }
            }
            while(1){}
        }
        
    }    
     
   return 0; 
}
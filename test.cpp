#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    
    int y=5,c=1;
    if(c--)cout<<"*"<<getpid();
    while(y--){
        if(fork()==0){
            int x=10;
            while(x--){
                if(fork()==0){
                    int temp=getpid();
                    cout<<"\ncheck"<<temp;
                    while(1){}
                }
                
            }
            while(1){}
        }
        sleep(20); 
    }    
   return 0; 
}
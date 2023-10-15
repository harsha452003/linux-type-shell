#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include<sys/file.h>
using namespace std;

int main() {
  
  int pid = fork();

  if (pid == 0) 
  {
    
       ofstream file("file.txt");
       if (!file.is_open())
       {
            cout << "Error opening file\n";
            return 1;
       }
       else cout <<"\nCreated a file \"file.txt\" in a child process\n";
       int fd = open("file.txt", O_RDONLY);
       int lock = flock(fd, LOCK_EX);
       if(lock==0) cout <<"\nChild has locked the file and starts writing to it\n";
  
       int count = 0;
       while (1)
       {
        string message = "Writing to file: " + to_string(count++) + "\n";
        cout << "Writing to file\n";
        file << message;
        file.flush();
        sleep(1);
       }
       file.close();
       close(fd);
    
  } 
 
  return 0;
}

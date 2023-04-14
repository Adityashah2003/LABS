 #include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

pid_t getpid();
pid_t getppid();

int main(){

pid_t pid;
pid=fork();

if(pid<0)
    cout<<"Chile process failed : pid<0";
else if(pid>0){
    cout<<"Parent process : pid>0"<<endl;
    cout<<"Parent's PID: "<<getppid()<<endl;
    cout<<"PID: "<<getpid()<<endl;
}
else{
    cout<<"Child process : pid=0"<<endl;
    cout<<"Parent's PID: "<<getppid()<<endl;
    cout<<"PID: "<<getpid()<<endl;
}
return 0;
}

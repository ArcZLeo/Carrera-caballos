#include <iostream>
#include<stdlib.h>
#include <string>
#include <thread>
#include <pthread.h>
#include <chrono>
using namespace std;
static int fin=5;

void run(string nom){
  for (int i=0;i<=fin;i++){
    cout<<nom<<" posicion "<<i<<endl;
    try{
      this_thread::sleep_for (chrono::milliseconds(rand()%10000));
      cout<<"El caballo "<<nom<< " descansa"<<endl;
    }catch (exception e){
    } 
  }
  cout<<"Final de la carrera: "<<nom<<endl;
}

int main() {
  int n;
  cout << "Ingerese cantidad caballos: ";
  cin>>n;
  thread lis[n];
  for(int i=0;i<n;i++){
    string name="c"+ to_string(i);
    lis[i]= thread(run, name);
  }
  for (auto& th : lis) th.join();
}
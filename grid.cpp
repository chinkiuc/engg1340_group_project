#include <iostream>
using namespace std;
extern char B[9];

void grid()
{
 for(int h=0;h<9;h+=3)
 {
  cout<<endl<<"   |   |"<<endl;
  cout<<" "<<B[h]<<" | "<<B[h+1]<<" | "<<B[h+2]<<endl;
  cout<<"   |   |"<<endl;
  if(h<6)
   for(int y=0;y<11;y++)
    cout<<"-";
 }
}

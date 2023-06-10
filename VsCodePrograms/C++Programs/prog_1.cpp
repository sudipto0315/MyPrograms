#include <iostream>
using namespace std;
void forEachLoopChar()
{
  char vowels[5];
  cout<<"Enter the vowels: "<<endl;
  for (char &ele : vowels)//pass by reference
  {
    cin >> ele;
  }
  for (int i = 0; i < 5; i++)
  {
    cout << vowels[i];
  }
  cout<<"\n";
}

void forEachLoopInteger(){
  int arr[]={1,2,3,4,5};
  for (int i = 0; i < 5; i++)
  {
    cout<<arr[i]<<endl;
  }

  for (int ele:arr)//pass by value
  {
    cout<<ele<<endl;
  }
  
    
}
int main()
{
  forEachLoopChar();
  forEachLoopInteger();
  return 0;
}
#include <iostream>
using namespace std;

///stak
class myStak
{
    int* stk;
    int tos ;
    int size;

    public:
        myStak(int s){
        cout << "ctor \n";
        tos =0;
        size = s;
        stk =new int[size];
        }
        ~myStak()
        {
            cout<<"destructor \n";
            delete [] stk;
        }
        bool isEmpty(){
        if (tos ==0 )return true ;
              ///  return tos ==0;

      else{ return false ;}
         }
        bool isFull (){
        if (tos==size) {return true;}


       else {return false ;}
         }
         void push (int n ){
           if (!isFull())

            stk[tos++] = n;
         else cout << "stk is empty \n ";
         }
         int pop ()
         {
             if (isEmpty() == false)
                return stk [--tos];
                else cout<<"stk is empty \n";
         }
          int peek(){
                if (tos == 0){
                cout<< "peek"<<endl;}
                else {return stk[tos];}}


        void display (){
                if (tos == 0){
                cout<< "your stak is "<<endl;}
                else {
                    for (int i = tos ; i>=0 ;i--){
                        cout << stk[i]<<"\t";}
}
        }

};
int main()
{
        myStak A (3);

        A.push (0);
        A.push (22);
        A.push(33);
        A.push(55);
        cout << "set stk value \n";
        A.display();
        A.pop();
        cout<<endl;
        cout <<"after pop fun"<<endl;
        A.display();
                cout<<endl;
    cout << "peek = "<<  A.peek()<<endl;
    return 0;

}

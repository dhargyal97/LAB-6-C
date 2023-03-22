///CS211
//Tezin dhargyal
//Project6
//Describtion: CREATE A THE PROGRAM WHICH ALLOCATES THE INTEGERS 1-8 TO THE SQUARES IN THE FIGURE ABOVE" //"SUBJECT TO THE RESTRICTIONS THAT NO TWO ADJACENT SQUARES CONTAIN CONSECUTIVE INTEGERS
// One dimensional array representation.
//Date:Oct-20- 2020


#include <iostream>
#include <cmath>
using namespace std;





void backtrack(int &Square){

     Square--;// takes us back to pervious column 
     if (Square==-1) {
         exit(1);//if it goes below one, all solutions are found and exit progrm
     }// int 

}//backtrack


void print(int q[], int &count) { //this will print the answer. the order for the array in the cross goes from top to bottom then left to right. So      the slot all the way to the left is zero. Then the top      left part of the cross is one
        cout<<"   "<< "SOLUTION: "<<"[" <<count<<"]" << endl << endl;
     for(int Square=0;Square<8;Square++){
         cout<<" " <<q[Square]<<" ";

    }
     cout<<endl<<endl;
}


bool ok(int q[8], int b, int c) { //this will check whether the numbers around it are the  same or off by one of our number
     for(int i=0; i<b; i++) {
         if (q[i]==q[b]||(abs(q[b]-q[c]) == 1)) return false;//if it is then it returns false
     }
     return true;//if the number works it returns true
}




int main() {



     int ans[8]={0}, c=0, i=0, count=0;
     cout<< "\n"<< "THE PROGRAM WHICH ALLOCATES THE INTEGERS 1-8 TO THE SQUARES IN THE FIGURE ABOVE" <<endl<<"SUBJECT TO THE RESTRICTIONS THAT NO TWO ADJACENT SQUARES CONTAIN CONSECUTIVE INTEGERS"<< endl <<endl;
     
      cout<<"   __|1|2|__  "<< endl;
      cout<<"   |0|3|4|7|  " << endl;
      cout<<"     |5|6|  "<<endl<< endl<<": The list of soltution are as follows:"<<endl << endl;


     int q[8][5] = {   //ceating a helper array whcih tells us which part of the array has to be our number 
         { 0,-1,-1,-1,-1},
         { 0,-1,-1,-1,-1},
         { 0, 1,-1,-1,-1},
         { 0, 2,-1,-1,-1},
         { 1, 2,-1,-1,-1},
         { 1, 2, 3, 4,-1},
         { 2, 3, 5,-1,-1},
         { 4, 5, 6,-1,-1} };

     while(true){   //this loop will make the program run until the backtrack      function ends the program
         while(c<8) {//the column shouldnt go past 7
             ans[c]++;
            if (ans[c]>8) {
                ans[c]=0;
                 backtrack(c);
               continue;
             }
             for(i=0; i<5; i++) {
                 if(q[c][i]==-1){//we go tthe next column if q[c][i]==  -1 
                     c++;
                     if(c==8) { // when c == 0, we have found the solition, so we quit using break;
                         print(ans,++count);
                        backtrack(c);                    }
                  break;
                }
                 if(ok(ans,c,q[c][i])==false) break;// we have to use different num or apporch if it appers to be false
            }

         }
     }

}



/* OUTPUTt
//
// THE PROGRAM WHICH ALLOCATES THE INTEGERS 1-8 TO THE SQUARES IN THE FIGURE ABOVE
SUBJECT TO THE RESTRICTIONS THAT NO TWO ADJACENT SQUARES CONTAIN CONSECUTIVE INTEGERS

   __|1|2|__
   |0|3|4|7|
     |5|6|

: The list of soltution are as follows:

   SOLUTION: [1]

 2  5  8  6  3  1  4  7

   SOLUTION: [2]

 2  6  8  5  4  1  3  7

   SOLUTION: [3]

7  3  1  4  5  8  6  2

   SOLUTION: [4]

 7  4  1  3  6  8  5  2



...Program finished with exit code 1
Press ENTER to exit console.

*/
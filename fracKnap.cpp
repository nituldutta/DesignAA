#include <bits/stdc++.h>
using namespace std;
// test case 1.   
// W = 80;
//  arr[] ={ { 50, 40 }, { 70, 35 }, { 90, 40 } };
//Profit. 166.25

 //test case 2.
 //W=40;
 //arr[]={ { 40, 20 }, { 80, 30 }, { 100, 20 } }; 
 //Profit. 153.333
 
 //test case 3.
 //W = 50;
 //arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
 //Profit. 240
 
// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
    int value, weight;
 
    // Constructor
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};
 

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
 

double fractionalKnapsack(int W, struct Item arr[], int N)
{
 
    sort(arr, arr + N, cmp);
 
    double finalvalue = 0.0;
 
   
    for (int i = 0; i < N; i++) {
         
 
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }
 
 
        else {
            finalvalue
                += arr[i].value
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }
 
 
    return finalvalue;
}

int main()
{
    int W = 80;//40;//50;
    int it[3];
    int val[3];
    cout<<"Capacity. ";
    cin>>W;
    cout<<"wight and profit.";
    for(int i=0;i<3;i++)
      {
          cin>>it[i];
          cin>>val[i];
      }
    Item arr[]={ {it[0], val[0]}, {it[1], val[1]}, {it[2], val[2]} };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}
//
//  main.cpp
//  Project 2
//
//  Created by Nicholas Rodriguez on 11/22/22.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <climits>
#include <vector>

using namespace std;

using namespace std::literals::chrono_literals;

struct Timer{
    
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    
    Timer() {
     start = std::chrono::high_resolution_clock::now();
    }
    
    ~Timer() {
     end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        
        float ms = duration.count() * 1000.0f;
        cout << endl;
        cout << "Timer took " << ms << " ms" << endl;
      
    }
    
};


int part(int *a, int l, int h){
    int piv = a[h];
    int lw = l;
        
    for(int i = l; i < h; ++i){
        if(a[i] < piv){
            swap(a[i],a[lw]);
            lw = lw + 1;
        }
    }
    swap(a[h], a[lw]);
    
    return(lw);
}




void Quicksort(int *a, int l, int h){
    int pl;
    if(l < h){
        pl = part(a, l, h);
        Quicksort(a, l, pl - 1);
        Quicksort(a, pl + 1, h);
    }
    
}







void MyHeapify(int *arr, int size){
    int OE;
    int tmpSIZE;
    int begSIZE;
    OE = size%2;
    
    
    if(OE == 0){
        tmpSIZE = size/2;
    } else {
        tmpSIZE = size/2 + 1;
    }
    begSIZE = size - tmpSIZE;
    
    if(OE == 0){
        
        if(arr[begSIZE - 1] > arr[2*begSIZE - 1]){
            swap(arr[begSIZE - 1], arr[2*begSIZE - 1]);
        }
        
        begSIZE--;
    }
    
    
    while(begSIZE != 0){
        
        
        if(arr[2*begSIZE - 1] < arr[2*begSIZE]){
            
            if(arr[begSIZE - 1] > arr[2*begSIZE - 1]){
                swap(arr[begSIZE - 1], arr[2*begSIZE - 1]);
            }
            
        } else if(arr[2*begSIZE - 1] > arr[2*begSIZE]){
            
            if(arr[begSIZE - 1] > arr[2*begSIZE]){
                swap(arr[begSIZE - 1], arr[2*begSIZE]);
            }
        }
        begSIZE--;
        
    }
    
    
    
}

void MyHeapifyVECT(vector<int>Myvect, int size){
    int OE;
    int tmpSIZE;
    int begSIZE;
    OE = size%2;
    
    
    if(OE == 0){
        tmpSIZE = size/2;
    } else {
        tmpSIZE = size/2 + 1;
    }
    begSIZE = size - tmpSIZE;
    
    if(OE == 0){
        
        if(Myvect.at(begSIZE - 1) > Myvect.at(2*begSIZE - 1)){
            swap(Myvect.at(begSIZE - 1), Myvect.at(2*begSIZE - 1));
        }
        
        begSIZE--;
    }
    
    
    while(begSIZE != 0){
        
        
        if(Myvect.at(2*begSIZE - 1) < Myvect.at(2*begSIZE)){
            
            if(Myvect.at(begSIZE - 1) > Myvect.at(2*begSIZE - 1)){
                swap(Myvect.at(begSIZE - 1), Myvect.at(2*begSIZE - 1));
            }
            
        } else if(Myvect.at(2*begSIZE - 1) > Myvect.at(2*begSIZE)){
            
            if(Myvect.at(begSIZE - 1) > Myvect.at(2*begSIZE)){
                swap(Myvect.at(begSIZE - 1), Myvect.at(2*begSIZE));
            }
        }
        begSIZE--;
        
    }
    
   
    
}


void PriorityQueueMINARRAY(int *a, int size){
    
    Quicksort(a, 0, size);
    
}


int partVECT(vector<int> MyVect, int l, int h){
    int piv = MyVect.at(h);
    int lw = l;
    
    for(int i = l; i < h; ++i){
        if(MyVect.at(i) < piv){
            swap(MyVect.at(i),MyVect.at(lw));
            lw = lw + 1;
        }
    }
    swap(MyVect.at(h), MyVect.at(lw));
    
    return(lw);
}




void QuicksortVECT(vector<int> MyVect, int l, int h){
    int pl;
    if(l < h){
        pl = partVECT(MyVect, l, h);
        QuicksortVECT(MyVect, l, pl - 1);
        QuicksortVECT(MyVect, pl + 1, h);
    }
    
}

    
    
void priorityQueueMinVector(vector<int> MyVect){
    QuicksortVECT(MyVect, 0, 100);
}


int main() {
    // insert code here...
    srand(time(NULL)); //For array
    int x[1000000];
  
    int size = 1000000; // For Vectors
    vector<int> MyVect;
    Timer time; //Timer
  

  
   
    
   
    
  

  
   
  /*
     for(int i = 0; i < size; ++i){
        x[i] = rand()%10000000; //A loop to insert numbers into the array
     }
    MyHeapify(x, size);
   Quicksort(x, 0, 1000000);
   for(int i = 1; i < 101; ++i){ //The loop and the Heapify/Quicksort to sort the numbers in the array
         cout << x[i] << " ";
     }
    */
    
    /*
    for(int A = 0; A < 1000000; ++A){
         MyVect.push_back(rand()%10000000); //A loop to insert Numbers into the vector
     }
    MyHeapifyVECT(MyVect, size);
    priorityQueueMinVector(MyVect); //The loop and the Heapify/PriorityQueue to sort the numbers in the vector
    for(int B = 0; B < 100; ++B){
        cout << MyVect.at(B) << " ";
     }
    */
  
    
    
    return 0;
}

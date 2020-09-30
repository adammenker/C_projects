#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
   using namespace std;
   int main()
   {
       // where n is number of vertices and m is number of edges
       int n, u, v, m;
       cin>> n>> m;
       vector< vector<int> > A(n);
       for(int i=0; i< m; i++)
       {
           cin>> u>> v;
           A[u].push_back(v);
           A[v].push_back(u); // In case of directed graph this statement is removed. 
       }
       // After above loop Adjcency List is ready.
        for(int i=0; i<n; i++)
       {
            cout<< i<< " ----> ";
            for(int j=0; j<A[i].size(); j++)
                cout<< A[i][j]<< " -->";
            cout <<  "\n";
       } 
       return 0;
     }
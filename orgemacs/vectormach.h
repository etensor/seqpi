#pragma once
#include <vector>
#include <iostream>

using namespace std;

class VectorMach{
  public:
  vector<vector<vector<vector<int>>>> create_v_mtr(int dims[3]){


  vector<vector<vector<vector<int>>>> v_mtr(
  dims[0], vector<vector<vector<int>>>(
  dims[1], vector<vector<int>>(
  dims[2], vector<int>(3)
      )
    )
  );

  for (int i=0; i<dims[0]; i++){
    for (int j=0;j<dims[1]; j++){
      for (int k=0;k<dims[2]; k++){
        v_mtr[i][j][k] = { i , j , k};
      }
    }
  }

cout<<"[\n";
for (int i = 0; i < dims[0]; i++){
  cout<<"  [\n";
  for (int j = 0; j<dims[1]; j++){
    cout<<"   [ ";
    for (int k=0; k<dims[2]; k++){
      cout<<" [";
      for (int s = 0; s < 3; s++){
        cout<<v_mtr[i][j][k][s];
        if (s < 2) cout<<",";
      }
      cout<<"]";
      if (k < dims[2]-1)cout<<",";
      
    }
    cout<<"  ]";
    if (j < dims[1]-1) cout<<",\n";
    
  }
  
  cout<<"\n  ]";
  if (i < dims[0] - 1 ) cout<<",\n";
}
cout<<endl<<"]";

return v_mtr;
}

};

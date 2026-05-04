#include <iostream>
#include <string>
#include <vector>
#include <cmath>
double derivada_x(const std :: vector <std :: vector <double>>&imagem, float x,float y){

  if(x <= 0) return 0;

  return imagem[y][x] - imagem[y][x-1];

}


double derivada_y(const std :: vector < std :: vector <double>>&imagem , float x,float y){

  if(y<=0) return 0;

  return imagem[y][x] - imagem[y-1][x];
}

double orientacao_borda(const std :: vector <std :: vector <double>>&imagem,float x,float y){
  
  double dx = derivada_x(imagem,x,y);
  double dy = derivada_y(imagem,x,y);
  return std :: atan2(dx,dy);

}


int main(){

   std :: vector < std :: vector <double>>imagem= {
    {20,30,14},
    {29,41,29},
    {32,56,19}
  };
  
  double cal1= orientacao_borda(imagem,2,2);

  std :: cout <<"Orientacao Borda:" << cal1 << std :: endl;

  return 0;
}

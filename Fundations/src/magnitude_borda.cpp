#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib> 
double derivada_em_x(const std :: vector<std :: vector<double>>&imagem,int x,int y){

    if(x<=0) return 0;

    return imagem[y][x] - imagem[y][x-1];
}

double derivada_em_y(const std :: vector <std :: vector <double>>&imagem,int x,int y){

    if(y<=0) return 0;

    return imagem[y][x] - imagem[y-1][x];
}

std :: pair <double,double> gradiente_imagem(const std :: vector <std :: vector <double>>&imagem,int x , int y){

    double derivada_x=derivada_em_x(imagem,x,y);

    double derivada_y=derivada_em_y(imagem,x,y);

    return std :: make_pair(derivada_x,derivada_y);
}

double norma_do_gradiente(const std :: vector <std :: vector <double >>&imagem,int x,int y){
    std :: pair<double,double> gradiente=gradiente_imagem(imagem,x,y);
    double dx=gradiente.first;
    double dy=gradiente.second;

    return sqrt(dx*dx+dy*dy);


}

double magnitude_borda(std :: vector <std :: vector <double>>&imagem,int x,int y){
   
    return norma_do_gradiente(imagem,x,y);
}

int main(){

    std :: vector < std :: vector<double>> imagem ={
        {10,15,30},
        {20,9,18},
        {29,19,22}
    };

    for(int y=0;y<3;y++){
        for(int x=0;x<3;x++){
            double e=magnitude_borda(imagem,x,y);
            std :: cout <<e << "\t";
        }
        std :: cout << std :: endl;
    }

    return 0;
}
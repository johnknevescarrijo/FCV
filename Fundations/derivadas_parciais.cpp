#include <iostream>
#include <vector>
//Derivadas Parciais: Calcular a variação de intensidade horizontal (∂ℓ/∂x) e vertical (∂ℓ/∂y) usando as aproximações discretas 
//fornecidas pelas equações (2.5) ou (2.6)

double derivada(const std :: vector <std :: vector<double>>&imagem,int x,int y){
    //verificar se a borda não esta a esquerda

    if(x<=0) return 0;

    return imagem[y][x] - imagem[y][x-1];
}

int main(){

    std :: vector <std :: vector <double>>imagem={
        {10,10,10},
        {15,25,32},
        {30,35,49},
    };

    double grad_x = derivada(imagem,1,1);

    std::cout << "∂ℓ/∂x no ponto (1,1) = " << grad_x << std::endl;

    return 0;

}
#include <iostream>
#include <cmath>

const float D = 1;
const float s = 1;
const float Psi1 = 0;
const float Psi2 = 0;
const float Tmax = 1;
float dT;
int nT;
int Nx;
float dX;

void FTCS(float **);
void mostrarMatriz(float **, int, int);

int main(int argc, char **argv){
	int input = atoi(argv[1]);
    if(input == 0) Nx = 10;
	else if(input == 1) Nx = 30;
	else Nx = 100;
	
    dX = 2.0/Nx;  
    dT = pow(dX, 2)/(2.0*D);
    //nT = Tmax / dT;
    
	int maxNt = 15000;
    float **Psi = new float*[maxNt];
    for(int i=0;i<maxNt;i++){
        Psi[i] = new float[Nx];
    }
    for(int i=0; i<Nx; i++){
        **(Psi + i) = 0;
    }
	
    FTCS(Psi);
    mostrarMatriz(Psi, nT, Nx);
	
    for(int i=0;i<maxNt;i++){
        delete[] Psi[i];
    }
    return 0;
}

void FTCS(float **Psi){
    float dPsi;
    int n = 1;
    int index;
    float maximo;
    do{
        for(int j=0; j<Nx; j++){
            if(j == 0){
                *(*(Psi+n)+j) = Psi1;
            }
            else if(j == (Nx - 1)){
                *(*(Psi+n)+j) = Psi2;
            }
            else{
                *(*(Psi+n)+j) = *(*(Psi+n-1)+j) + 1/2.0*( *(*(Psi+n-1)+j+1) - 2*(*(*(Psi+n-1)+j)) + *(*(Psi+n-1)+j-1) ) + s*pow(dX, 2)/(2.0*D);
            }
        }
        index = 0;
        maximo = *(*(Psi+n)+index);
        for(int i=1; i<Nx; i++){
            if( *(*(Psi+n)+i) > maximo ){
                maximo = *(*(Psi+n)+i);
                index = i;
            }
        }
        dPsi = std::abs( *(*(Psi+n)+index) - *(*(Psi+n-1)+index) )/std::abs( *(*(Psi+n)+index) );
        n = n+1;
        nT = n;
    }
    while( dPsi > 10e-6 );

}


void mostrarMatriz(float **Matriz, int filas, int col){
    for(int i=0;i<filas;i++){
        for(int j=0;j<col;j++){
            std::cout<<*(*(Matriz+i)+j)<<"\t";
            
        }
        std::cout<<std::endl;
    }
}
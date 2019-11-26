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
    nT = Tmax / dT;
    
	
    float **Psi = new float*[nT];
    for(int i=0;i<nT;i++){
        Psi[i] = new float[Nx];
        **(Psi+i) = 0;
    }
	
    FTCS(Psi);
    mostrarMatriz(Psi, nT, Nx);
	
    for(int i=0;i<nT;i++){
        delete[] Psi[i];
    }
    return 0;
}

void FTCS(float **Psi){
    for(int n=1; n<nT; n++){
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
    }
}

void mostrarMatriz(float **Matriz, int filas, int col){
    for(int i=0;i<filas;i++){
        for(int j=0;j<col;j++){
            std::cout<<*(*(Matriz+i)+j)<<"\t";
            
        }
        std::cout<<std::endl;
    }
}
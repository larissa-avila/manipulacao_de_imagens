/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "imagens.h"

using namespace std;

//clareia a imagem a partir de um fator que diz quantos tons deve clarear.
void clarear_imagem(Timagem img, int linha, int coluna, int tons, int fator){
    for (int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            if(img[i][j] >= tons - fator){
                img[i][j] = tons;
            }
            else{
                img[i][j] = img[i][j]+fator;
            }
        }
    }
}

//escurece a imagem a partir de um fator que diz quantos tons deve escurecer.
void escurecer_imagem(Timagem img, int linha, int coluna, int tons, int fator){
    for (int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            if(img[i][j] <= fator){
                img[i][j] = 0;
            }
            else{
                img[i][j] = img[i][j] - fator;
            }
        }
    }
}

//estabelece a imagem negativa da imagem real.
void imagem_negativa(Timagem img, int linha, int coluna, int tons){
    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            img[i][j] = tons - img[i][j];
            }
        }
    }

// estabelece a imagem binarizada, ou seja, em apenas duas cores: preto e branco.
void binarizar_imagem(Timagem img, int linha, int coluna, int tons, int fator){
    for (int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            if(img[i][j] <= fator){
                img[i][j] = 0;
            }
            else{
                img[i][j] = tons;
            }
        }
    }
}

// transforma a imagem real em uma ícone de 64x64 pixels.
void iconizar_imagem(Timagem img, int linha, int coluna, int img2[64][64]){
    int lin_bloco, col_bloco, cont, media, k, l, limite_i, limite_j;
    lin_bloco = linha/64; 
    col_bloco = coluna/64;
    
    for(int i=0; i<64; i++){
        for(int j=0; j<64; j++){
            cont=0;
            media=0;
            if(i==63){
                limite_i = linha;
            }else{
                limite_i = i*lin_bloco + lin_bloco;
            }
            if(j==63){
                limite_j = coluna;
            }else{
                limite_j = j*col_bloco + col_bloco;
            }
            
            for(k = i*lin_bloco; k<limite_i; k++ ){
                for(l = j*col_bloco; l<limite_j; l++){
                    media = media + img[k][l];
                    cont++;
                }
            }
            img2[i][j] = media/cont;
        }
    }
}

//espalha ruídos (pontos pretos) aleatoriamente pela imagem.
void ruidos(Timagem img, int linha, int coluna){
    srand(time(NULL));
    int a, b;
    for(int k=0; k<150; k++){
        a = (rand()%linha); b = (rand()%coluna);
        for(int i=0; i<linha; i++){
            for(int j=0; j<coluna; j++){
                if(i==a && j==b){
                    img[i][j] = 0;
                }
            }
        }
    }
}

//aplica uma filtro linear, utilizando máscara 3x3, para suavizar a imagem. 
void filtro(Timagem img, int linha, int coluna){
    for(int i=1; i<linha-2; i++){
        for(int j=1; j<coluna-2; j++){
            img[i][j] = (img[i-1][j-1] + img[i-1][j] + img[i-1][j+1] + img[i][j-1]
            + img[i][j] + img[i][j+1] + img[i+1][j-1] + img[i+1][j] + img[i+1][j+1]) / 9;
        }
    }
}




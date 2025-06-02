/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   imagens.h
 * Author: larissa-avila
 *
 * Created on 17 de junho de 2024, 17:26
 */

#ifndef IMAGENS_H
#define IMAGENS_H

typedef int Timagem[1024][1024];

void clarear_imagem(Timagem img, int linha, int coluna, int tons, int fator);
void escurecer_imagem(Timagem img, int linha, int coluna, int tons, int fator);
void imagem_negativa(Timagem img, int linha, int coluna, int tons);
void binarizar_imagem(Timagem img, int linha, int coluna, int tons, int fator);
void iconizar_imagem(Timagem img, int linha, int coluna, int img2[64][64]);
void ruidos(Timagem img, int linha, int coluna);
void filtro(Timagem img, int linha, int coluna);


#endif /* IMAGENS_H */


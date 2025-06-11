#pragma once
#include "Struct_Stack.h";

//cac ham thuc hien cac tinh nang dac biet nhu undo/redo
void SaveMatrixU(Game2048& myGame); //luu ma tran vao stack dung cho undo
void Undo(Game2048& myGame);
void SaveMatrixR(Game2048& myGame); //luu ma tran vao stack dung cho redo
void Redo(Game2048& myGame);

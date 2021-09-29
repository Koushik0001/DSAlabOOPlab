#pragma once
class cmatrix
{
private:
	int r, c;
	float** mat;
public:
	void get_data();
	void display();
	void transpose(cmatrix);
	void add(cmatrix, cmatrix);
	void multiply(cmatrix, cmatrix);
	void negative_of_matrix(cmatrix);
	void const_multiplication(cmatrix, float);
	float element(float*, float*, int);
};
void matrix();
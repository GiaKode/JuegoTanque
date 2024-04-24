#pragma once
#include"Movimientos.h"

class Tanque : public Movimientos
{
private:
	int inicioX, inicioY;

public:
	Tanque(int ancho, int alto) :Movimientos(ancho, alto) {
		//this->vida = vidas;
		x = 100;
		y = 300;
		dx = dy = 4;
		inicioX = x;
		inicioY = y;
	
	}

	~Tanque() {}

	void movimientos(Graphics^ g, char i) {

		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx;
				idY = 1;
			}
			break;

		case 'D':
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idY = 2;
			}
			break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idY = 3;
			}
			break;

		case 'S':
			if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idY = 0;
			}
			break;
		}

		idX++;
		if (idX >= 3)idX = 0;
	}

	

};

	